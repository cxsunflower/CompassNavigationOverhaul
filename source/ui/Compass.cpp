#include "Compass.h"
#include "Settings.h"

namespace CNO
{
	void Compass::InitSingleton(const GFxDisplayObject& a_originalCompass)
	{
		if (!singleton)
		{
			static Compass singletonInstance{ a_originalCompass };
			singleton = &singletonInstance;
		}
	}

	void Compass::SetupMod(const GFxDisplayObject& a_replaceCompass)
	{
		if (a_replaceCompass.HasMember("Compass"))
		{
			*static_cast<GFxDisplayObject*>(this) = a_replaceCompass;

			Invoke("Compass");
		}
	}

	void Compass::SetUnits()
	{
		Invoke("SetUnits", settings::display::useMetricUnits);
	}

	void Compass::SetMarkerTextScale(float a_scale)
	{
		Invoke("SetMarkerTextScale", a_scale);
	}

	void Compass::SetMarkerNameScale(float a_scale)
	{
		RE::GFxValue result;
		const bool invoked = Invoke("SetMarkerNameScale", &result, a_scale);
		logger::info("[MarkerScale] name={} invoked={}", a_scale, invoked);
	}

	void Compass::SetMarkerDistanceScale(float a_scale)
	{
		RE::GFxValue result;
		const bool invoked = Invoke("SetMarkerDistanceScale", &result, a_scale);
		logger::info("[MarkerScale] distance={} invoked={}", a_scale, invoked);
	}

	void Compass::SetFocusedMarkerInfo(const std::string_view& a_targetText, float a_distance,
							  float a_heightDifference, std::uint32_t a_markerIndex)
	{
		Invoke("SetFocusedMarkerInfo", a_targetText.data(), a_distance, a_heightDifference,
									   a_markerIndex);
	}

	IUI::GFxDisplayObject Compass::GetFocusedMarkerTargetTextField()
	{
		IUI::GFxDisplayObject focusedMarkerInfo{ GetMember("FocusedMarkerInfo") };
		IUI::GFxDisplayObject target{ focusedMarkerInfo.GetMember("Target") };
		return target.GetMember("TextFieldInstance");
	}

	void Compass::FocusMarker()
	{
		Invoke("FocusMarker");
	}

	void Compass::UnfocusMarker()
	{
		Invoke("UnfocusMarker");
	}

	void Compass::UpdateFocusedMarker()
	{
		Invoke("UpdateFocusedMarker");
	}
}
