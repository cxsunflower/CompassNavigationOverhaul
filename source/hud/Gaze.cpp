#include "HUDMarkerManager.h"

#include "RE/B/BSTimer.h"

namespace CNO
{
	bool HUDMarkerManager::IsLookingAtCompass(const Compass* a_compass)
	{
		using namespace settings::questlist;

		// Visibility and gaze are independent user requirements. Disabling
		// gaze must not bypass a still-enabled compass visibility gate.
		const bool compassVisible = !requireCompassVisible || IsCompassVisible(a_compass);
		compassVisibilityPassed = compassVisible;
		if (!requireLookingAtCompass)
		{
			compassGazeActive = false;
			return compassVisible;
		}

		RE::NiPoint3 forward{ 0.0F, 0.0F, 0.0F };
		const bool haveForward = GetCameraForward(forward);

		const std::uint32_t mode = GetEffectiveGazeMode();
		RE::NiPoint3 camPos = playerCamera->GetRuntimeData2().pos;
		if (REL::Module::IsVR() && player) {
			if (auto* nodes = player->GetVRNodeData(); nodes && nodes->HmdNode)
				camPos = nodes->HmdNode->world.translate;
		}

		// 读数：mode 0 是俯角（越大越往下看），mode 1/2 是 3D 视线夹角（越小越正对）。
		float reading = 180.0F;
		float pointDistance = -1.0F;
		bool withinDistance = true;

		if (haveForward)
		{
			if (mode == 0)
			{
				reading = util::GetDepressionAngle(forward);
				if (!compassOnPalm)
				{
					reading = -reading;  // 罗盘在视线上方：抬头才算看向
				}
			}
			else
			{
				const RE::NiAVObject* pointNode = (mode == 2) ? compassNode.get() : handNode.get();
				if (pointNode)
				{
					const RE::NiPoint3& pointPos = pointNode->world.translate;
					reading = util::GetGazeAngleBetween(forward, camPos, pointPos);
					pointDistance = camPos.GetDistance(pointPos);
					withinDistance = pointDistance <= compassMaxDistance;
				}
			}
		}

		const float showThreshold = (mode == 0) ? compassGazePitchToShow : compassGazeAngleToShow;
		const float keepThreshold = (mode == 0) ? compassGazePitchToKeep : compassGazeAngleToKeep;

		bool gazeNow = false;
		if (haveForward)
		{
			if (mode == 0)
			{
				gazeNow = compassGazeActive ? (reading >= keepThreshold) : (reading >= showThreshold);
			}
			else
			{
				gazeNow = withinDistance &&
					(compassGazeActive ? (reading <= keepThreshold) : (reading <= showThreshold));
			}
		}

		compassGazeActive = compassVisible && gazeNow;

		// [QuestListGaze] 打点：约 2Hz，一行看全部门控读数（Debug 级别可见）。
		gazeProbeTime += timeManager->realTimeDelta;
		if (gazeProbeTime >= 0.5F)
		{
			gazeProbeTime = 0.0F;
			logger::debug("[QuestListGaze] mode={}/{} vis={} fwd={} read={:.1f} dist={:.1f} show={:.0f} keep={:.0f} gaze={}",
				compassGazeMode, mode, compassVisible, haveForward, reading, pointDistance, showThreshold,
				keepThreshold, compassGazeActive);
		}

		return compassGazeActive;
	}

	std::uint32_t HUDMarkerManager::GetEffectiveGazeMode()
	{
		const std::uint32_t configured =
			settings::questlist::compassGazeMode > 2 ? 2 : settings::questlist::compassGazeMode;

		std::uint32_t effective = 0;
		if (configured >= 2 && FindCompassNode())
		{
			effective = 2;
		}
		else if (configured >= 1 && FindHandNode())
		{
			effective = 1;
		}

		if (effective != lastEffectiveGazeMode)
		{
			if (effective < configured)
			{
				logger::warn("[QuestListGaze] gaze mode degraded {} -> {} (3D node missing, retrying)",
					configured, effective);
			}
			else
			{
				logger::info("[QuestListGaze] effective gaze mode: {}", effective);
			}
			lastEffectiveGazeMode = effective;
		}

		return effective;
	}

	bool HUDMarkerManager::GetCameraForward(RE::NiPoint3& a_forwardOut)
	{
		if (!playerCamera || !playerCamera->cameraRoot.get())
		{
			return false;
		}

		const RE::NiMatrix3& rotate = playerCamera->cameraRoot->world.rotate;

		float yaw = playerCamera->GetRuntimeData2().yaw;
		util::CropAngleRange(yaw);

		// 12 个候选：旋转矩阵 3 列 + 3 行 × 正负。真前向量是唯一水平朝向恒等于
		// 相机 yaw 的轴（俯仰/滚转都不改变前向量的水平朝向），与已验证的 yaw 对齐即选中。
		auto candidate = [&](int a_index) {
			const int axis = a_index >> 1;  // 0-2 列，3-5 行
			const float sign = (a_index & 1) ? -1.0F : 1.0F;
			if (axis < 3)
			{
				return RE::NiPoint3{ sign * rotate.entry[0][axis], sign * rotate.entry[1][axis],
					sign * rotate.entry[2][axis] };
			}
			const int row = axis - 3;
			return RE::NiPoint3{ sign * rotate.entry[row][0], sign * rotate.entry[row][1],
				sign * rotate.entry[row][2] };
		};

		float bestDiff = 1e9F;
		int bestIndex = -1;
		for (int i = 0; i < 12; ++i)
		{
			const RE::NiPoint3 v = candidate(i);

			// 接近竖直的轴水平朝向不可信，跳过。
			if (v.x * v.x + v.y * v.y < 0.0025F)
			{
				continue;
			}

			float heading = std::atan2(v.x, v.y);  // 与 GetHorizontalAngleTo 同约定
			util::CropAngleRange(heading);

			float diff = std::fabs(heading - yaw);
			if (diff > util::pi)
			{
				diff = 2 * util::pi - diff;
			}

			if (diff < bestDiff)
			{
				bestDiff = diff;
				bestIndex = i;
			}
		}

		// 残差超过 15 度：全部不可信（万向节附近），沿用上次标定。
		static constexpr float calibrateResidual = 15.0F * util::pi / 180.0F;
		static constexpr float switchResidual = 5.0F * util::pi / 180.0F;

		int axisIndex = calibratedForwardAxis;
		if (bestIndex < 0 || bestDiff > calibrateResidual)
		{
			if (axisIndex < 0)
			{
				return false;
			}
		}
		else if (axisIndex < 0)
		{
			axisIndex = bestIndex;
			calibratedForwardAxis = bestIndex;
			logger::info("[QuestListGaze] camera forward calibrated: axis={} residual={:.1f}deg", bestIndex,
				util::RadiansToDegrees(bestDiff));
		}
		else if (bestIndex != axisIndex && bestDiff < switchResidual)
		{
			logger::info("[QuestListGaze] camera forward axis switched {} -> {} (residual={:.1f}deg)", axisIndex,
				bestIndex, util::RadiansToDegrees(bestDiff));
			axisIndex = bestIndex;
			calibratedForwardAxis = bestIndex;
		}

		const RE::NiPoint3 forward = candidate(axisIndex);
		const float length =
			std::sqrt(forward.x * forward.x + forward.y * forward.y + forward.z * forward.z);
		if (length <= 0.0001F)
		{
			return false;
		}

		a_forwardOut.x = forward.x / length;
		a_forwardOut.y = forward.y / length;
		a_forwardOut.z = forward.z / length;

		return true;
	}
}
