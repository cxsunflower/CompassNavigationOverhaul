#pragma once

#include <algorithm>
#include <cmath>
#include <numbers>

namespace util
{
	static constexpr float pi = std::numbers::pi_v<float>;

	constexpr void CropAngleRange(float& a_angle)
	{
		if (a_angle <= 2 * pi)
		{
			if (a_angle < 0.0F)
			{
				a_angle = std::fmodf(a_angle, 2 * pi) + 2 * pi;
			}
		}
		else
		{
			a_angle = std::fmodf(a_angle, 2 * pi);
		}
	};

	constexpr float RadiansToDegrees(float a_angle)
	{
		return a_angle * 180.0F / pi;
	}

	inline float GetAngleBetween(const RE::PlayerCamera* a_playerCamera, const RE::TESObjectREFR* a_markerRef)
	{
		RE::PlayerCharacter* player = RE::PlayerCharacter::GetSingleton();
		RE::NiPoint3 playerPos = player->GetPosition();

		// Skyrim 原本使用 GetLookingAtLocation()，但精度较低。

		RE::NiPoint3 markerPos = a_markerRef->GetPosition();

		float playerCameraYawAngle = a_playerCamera->GetRuntimeData2().yaw;

		float compassAngle = playerCameraYawAngle;

		if (RE::TESObjectCELL* parentCell = player->GetParentCell())
		{
			compassAngle += parentCell->GetNorthRotation();
		}

		float headingAngle = playerPos.GetHorizontalAngleTo(markerPos);

		CropAngleRange(playerCameraYawAngle);
		CropAngleRange(compassAngle);
		CropAngleRange(headingAngle);

		float angle = headingAngle - playerCameraYawAngle;

		CropAngleRange(angle);

		return angle;
	}

	inline RE::NiPoint3 GetRealPosition(const RE::TESObjectREFR* a_objRef)
	{
		RE::NiPoint3 position = a_objRef->GetPosition();

		if (const RE::TESWorldSpace* worldSpace = a_objRef->GetWorldspace())
		{
			RE::NiPoint3 worldSpaceOffset{ worldSpace->worldMapOffsetData.mapOffsetX,
												  worldSpace->worldMapOffsetData.mapOffsetY,
												  worldSpace->worldMapOffsetData.mapOffsetZ };

			position += worldSpaceOffset * worldSpace->worldMapOffsetData.mapScale;
		}

		return position;
	}

	inline float GetDistanceBetween(const RE::PlayerCharacter* a_player, const RE::TESObjectREFR* a_marker)
	{
		RE::NiPoint3 playerPos = GetRealPosition(a_player);
		RE::NiPoint3 markerPos = GetRealPosition(a_marker);

		return playerPos.GetDistance(markerPos);
	}

	inline float GetHeightDifferenceBetween(const RE::PlayerCharacter* a_player, const RE::TESObjectREFR* a_marker)
	{
		RE::NiPoint3 playerPos = GetRealPosition(a_player);
		RE::NiPoint3 markerPos = GetRealPosition(a_marker);

		return markerPos.z - playerPos.z;
	}

	// 3D 视线夹角（度）：从 a_from 沿单位向量 a_forward 看向 a_target 的夹角。
	// 点与相机重合（距离约 0）时返回 180 度，即视为“没看向”。
	inline float GetGazeAngleBetween(const RE::NiPoint3& a_forward, const RE::NiPoint3& a_from,
		const RE::NiPoint3& a_target)
	{
		const float dx = a_target.x - a_from.x;
		const float dy = a_target.y - a_from.y;
		const float dz = a_target.z - a_from.z;
		const float length = std::sqrt(dx * dx + dy * dy + dz * dz);

		if (length <= 0.0001F)
		{
			return 180.0F;
		}

		float cosAngle = (a_forward.x * dx + a_forward.y * dy + a_forward.z * dz) / length;
		cosAngle = std::max(-1.0F, std::min(1.0F, cosAngle));

		return RadiansToDegrees(std::acos(cosAngle));
	}

	// 视线俯角（度）：正数=往下看，负数=往上看。a_forward 应为单位向量。
	inline float GetDepressionAngle(const RE::NiPoint3& a_forward)
	{
		const float sinAngle = std::max(-1.0F, std::min(1.0F, -a_forward.z));

		return RadiansToDegrees(std::asin(sinAngle));
	}
}
