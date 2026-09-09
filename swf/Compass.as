#include "utils.as"

import CompassMarkerInfo;

// Instances
var CompassFrame:MovieClip;
var CompassTemperatureHolderInstance:MovieClip;
var CompassMask_mc:MovieClip;
var DirectionRect:MovieClip;
var CompassFrameAlt:MovieClip;

var FocusedMarkerInfo:CompassMarkerInfo;

// References
var HUDMenu:MovieClip = _root.HUDMovieBaseInstance;
var MarkerList:Array = HUDMenu.CompassMarkerList;
var MarkersData:Array = HUDMenu.CompassTargetDataA;

// Variables and constants
var MarkerQuest:Number = HUDMenu.CompassMarkerQuest;
var MarkerQuestDoor:Number = HUDMenu.CompassMarkerQuestDoor;
var MarkerUnknownLocation:Number = 0;

var COMPASS_HEADING:Number = 0;
var COMPASS_ALPHA:Number = 1;
var COMPASS_GOTOANDSTOP:Number = 2;
var COMPASS_SCALE:Number = 3;
var COMPASS_STRIDE:Number = 4;

function Compass():Void
{
	CompassTemperatureHolderInstance.gotoAndStop("Empty");
	HUDMenu.TemperatureMeter_mc = CompassTemperatureHolderInstance;

	HUDMenu.CompassRect = DirectionRect;

	// Hide in dialogue mode
	delete HUDMenu.CompassShoutMeterHolder["DialogueMode"];

	// SkyHUD compatibility
	if (HUDMenu.CompassFrameAlt == undefined)
	{
		CompassFrameAlt._visible = false;
		DirectionRect.CompassDirectionTextAlt._visible = false;
	}
	else
	{
		HUDMenu.CompassFrame = CompassFrame;
		HUDMenu.CompassFrameAlt = CompassFrameAlt;
		HUDMenu.CompassCard = DirectionRect.CompassDirectionText;
		HUDMenu.CompassCardAlt = DirectionRect.CompassDirectionTextAlt;
	}

	// Hook SetCompassMarkers
	delete HUDMenu.SetCompassMarkers;
	HUDMenu.SetCompassMarkers = SetMarkers;
}

function SetUnits(a_useMetric:Boolean):Void
{
	FocusedMarkerInfo.UseMetricUnits = a_useMetric;
}

function SetMarkerTextScale(a_scale:Number):Void
{
	// 百分比直传：_xscale 即百分比；旧式除 100 会把文字缩到 1%。
	FocusedMarkerInfo.SetTextScale(a_scale);
}

function SetMarkerNameScale(a_scale:Number):Void
{
	FocusedMarkerInfo.SetNameScale(a_scale);
}

function SetMarkerDistanceScale(a_scale:Number):Void
{
	FocusedMarkerInfo.SetDistanceScale(a_scale);
}

// Diagnostic only: sampled after settings apply, not on every display frame.
function GetMarkerScaleState():String
{
	var info:MovieClip = FocusedMarkerInfo;
	var name:TextField = info.Target.TextFieldInstance;
	var distance:TextField = info.Distance.TextFieldInstance;
	return "classMethods=" + typeof(info.SetNameScale) + "," + typeof(info.SetDistanceScale) +
		"; requested=" + info.NameScale + "," + info.DistanceScale +
		"; actual=" + name._xscale + "," + name._yscale + "," + distance._xscale + "," + distance._yscale +
		"; nameRect=" + name._x + "," + name._y + "," + name._width + "," + name._height +
		"; distanceRect=" + distance._x + "," + distance._y + "," + distance._width + "," + distance._height +
		"; stage=" + Stage.width + "," + Stage.height;
}

function SetFocusedMarkerInfo(a_target:String, a_distance:Number, a_heightDifference:Number, a_markerIndex:Number):Void
{
	FocusedMarkerInfo.SetDistanceAndHeightDifference(a_distance, a_heightDifference);
	FocusedMarkerInfo.Movie = MarkerList[a_markerIndex].movie;
	FocusedMarkerInfo.Index = a_markerIndex;
	FocusedMarkerInfo.Target.TextFieldInstance.text = a_target;
	FocusedMarkerInfo.ApplyNameViewportGuard();
}

function FocusMarker():Void
{
	FocusedMarkerInfo.Target.TextFieldInstance._visible = false;
	FocusedMarkerInfo.gotoAndPlay("FadeIn");
	FocusedMarkerInfo.ApplyNameViewportGuard();
}

function UpdateFocusedMarker():Void
{
	var focusedMarker_mc:MovieClip = FocusedMarkerInfo.Movie;

	if (focusedMarker_mc != undefined)
	{
		// SkyHUD rescale functionality
		var skyHUDScaleMult:Number = (HUDMenu.scl_fCompassMarker != undefined && HUDMenu.scl_fCompassMarker != NaN) ? HUDMenu.scl_fCompassMarker : 1;

		var markerScale:Number = MarkersData[FocusedMarkerInfo.Index * COMPASS_STRIDE + COMPASS_SCALE] * skyHUDScaleMult;

		markerScale = Math.min(145, markerScale * 1.325);

		focusedMarker_mc._xscale = markerScale;
		focusedMarker_mc._yscale = markerScale;

		// Workaround-fix for pop-up out of compass when changing index
		var focusedMarker_x:Number = localToLocal(focusedMarker_mc, this).x;
		var compassMask_x:Number = localToLocal(CompassMask_mc, this).x;
		if (focusedMarker_x >= compassMask_x)
		{
			FocusedMarkerInfo._x = focusedMarker_x;
		}

		FocusedMarkerInfo._alpha = Math.max(focusedMarker_mc._alpha, 75);

		if (HUDMenu.EnemyHealth_mc.BracketsInstance._alpha)
		{
			FocusedMarkerInfo.Target.TextFieldInstance._alpha = 0;
		}
		else
		{
			FocusedMarkerInfo.Target.TextFieldInstance._alpha = 100;
		}

		// iHUD show/hide functionality
		if (DirectionRect._alpha)
		{
			FocusedMarkerInfo._alpha = 100;
		}
		else
		{
			FocusedMarkerInfo._alpha = 0;
		}
	}
}

function UnfocusMarker():Void
{
	FocusedMarkerInfo.gotoAndPlay("FadeOut");
	FocusedMarkerInfo.ApplyNameViewportGuard();
	FocusedMarkerInfo.Movie = undefined;
}

// Reference: HUDMenu.as
function SetMarkers():Void
{
	while (MarkerList.length)
	{
		MarkerList.pop().movie.removeMovieClip();
	}

	var markersDataLength:Number = MarkersData.length / COMPASS_STRIDE;

	for (var i:Number = 0; i < markersDataLength; i++)
	{
		var j:Number = i * COMPASS_STRIDE;

		var markerData:Object = { movie: undefined, heading: MarkersData[j + COMPASS_HEADING] };

		var markerType:Number = MarkersData[j + COMPASS_GOTOANDSTOP];

		if (markerType == MarkerUnknownLocation)
		{
			markerData.movie = DirectionRect.MarkerHolder.attachMovie("Unknown Location", "CompassMarker" + MarkerList.length, DirectionRect.MarkerHolder.getNextHighestDepth());
		}
		else if (markerType == MarkerQuest || markerType == MarkerQuestDoor)
		{
			markerData.movie = DirectionRect.QuestHolder.attachMovie("Compass Marker", "CompassMarker" + MarkerList.length, DirectionRect.QuestHolder.getNextHighestDepth());
		}
		else
		{
			markerData.movie = DirectionRect.MarkerHolder.attachMovie("Compass Marker", "CompassMarker" + MarkerList.length, DirectionRect.MarkerHolder.getNextHighestDepth());
		}

		MarkerList.push(markerData);

		var marker_mc:MovieClip = markerData.movie;

		// The function to position the markers in the compass checks if the marker type
		// is CompassMarkerQuest (1) or CompassMarkerQuestDoor (2) to limit the marker position
		// to the border of the compass. Unknown locations should not be kept always
		// within the compass
		if (markerType == MarkerUnknownLocation)
		{
			// Set to different than CompassMarkerQuest (1) or CompassMarkerQuestDoor (2),
			// 0 is an invalid frame so we set 3
			marker_mc.gotoAndStop(3);
		}
		else
		{
			marker_mc.gotoAndStop(markerType);
		}

		marker_mc._alpha = MarkersData[j + COMPASS_ALPHA];

		// SkyHUD rescale functionality
		var skyHUDScaleMult:Number = (HUDMenu.scl_fCompassMarker != undefined && HUDMenu.scl_fCompassMarker != NaN) ? HUDMenu.scl_fCompassMarker : 1;

		var markerScale:Number = MarkersData[j + COMPASS_SCALE] * skyHUDScaleMult;

		markerScale = Math.min(135, markerScale);

		marker_mc._xscale = markerScale;
		marker_mc._yscale = markerScale;
	}
}

// 旧基底主时间轴三语句（2.12.0 基底重编时从旧二进制补回）：
// gfxExtensions 开关 Scaleform 扩展 API；HeightIndicator 默认帧；stop 防止主时间轴（共 2 帧）走帧。
_global.gfxExtensions = true;
HeightIndicatorInstance.gotoAndStop("Above");
stop();
