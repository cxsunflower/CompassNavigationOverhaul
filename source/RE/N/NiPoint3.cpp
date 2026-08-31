#include "RE/N/NiPoint3.h"

#include <numbers>

// ============================================================================
// CommonLibSSE-NG 6.7.1 起，RE::NiPoint3 的全部标准成员（operator[]/==/!=/+/-/*
// //、复合赋值、Cross/Dot/GetDistance/GetSquaredDistance/Length/SqrLength/
// UnitCross/Unitize 等）都在 CommonLibSSE.lib 里给了脱线定义。
// 旧的 CommonLibVR 4.0.0 没有，所以本工程当年自带了一份实现。
//
// 现在再留着那份实现，两边符号名逐字相同（QEBA?AV01@…），链接期就是 LNK2005
// 重定义。因此这里只保留 CommonLib 唯一没有的、本 mod 自己加的
// GetHorizontalAngleTo —— 其余标准成员的调用一律落到 CommonLib.lib。
//
// 注意：include/RE/N/NiPoint3.h 这份「影子头」必须保留：它声明了
// GetHorizontalAngleTo、保证 sizeof==0xC 的布局，且工程各处都按这个头来编译。
// ============================================================================

namespace RE
{
	float NiPoint3::GetHorizontalAngleTo(const NiPoint3& a_pt) const
	{
		NiPoint3 diff{ a_pt.x - x, a_pt.y - y, a_pt.z - z };

		float angle;
		if (diff.y) {
			angle = atanf(diff.x / diff.y);
			if (diff.y < 0.0F) {
				angle += std::numbers::pi_v<float>;
			}
		} else {
			if (diff.x <= 0.0F) {
				angle = 3 * std::numbers::pi_v<float> / 2;
			} else {
				angle = std::numbers::pi_v<float> / 2;
			}
		}

		return angle;
	}
}
