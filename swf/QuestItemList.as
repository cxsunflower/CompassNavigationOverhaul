// Source modules are expanded by tools/questlist_source.py before JPEXS import.
_global.gfxExtensions = true;
var questItem:QuestItem;
var entries:Array;
var entriesByKey:Object;

var All:Boolean;
var Favor:Boolean;
var StealthMode:Boolean;
var Swimming:Boolean;
var HorseMode:Boolean;
var WarHorseMode:Boolean;

var anchorText:TextField;
var anchorGap:Number = 6;
var offsetX:Number = 0;

var SCALE:Number = 65;
var TEXT_SCALE:Number = 100;
var effectiveScale:Number = 100;
var effectiveWidth:Number = 1;
var fitKey:String = "";
var fitGeometry:String = "";
var fitOverflow:Boolean = false;
var fitRuns:Number = 0;
var fitReason:String = "not fitted";
var overflowLabel:MovieClip;
var overflowStopIndex:Number = -1;
var viewportMask:MovieClip;
var omissionReason:String = "none";
var omissionLimit:Number = 0;
var lastSafeLimit:Number = 0;
var lastVisibleBottom:Number = 0;
var calibrationEnabled:Boolean = false;
var calibrationAxis:Number = 0;
var calibrationStart:Number = 700;
var calibrationStep:Number = 40;
var calibrationCross:Number = 512;
var calibrationOverlay:MovieClip;
var dedicatedPanel:Boolean = false;

// One logical Passenger contract, expressed in Target-local coordinates.
// These values are not a measured VR mesh UV allocation. The build also reads
// this object for the embedded sprite's initial transform.
var compassPassengerMode:Boolean = true;
var compassPassengerConfig:Object = {
    width:320,
    height:220,
    offsetX:40,
    offsetY:40,
    scale:110,
    minScale:90
};
var compassPassengerWidth:Number = compassPassengerConfig.width;
var compassPassengerHeight:Number = compassPassengerConfig.height;
function GetCompassPassengerConfig():Object
{
    return compassPassengerConfig;
}

// Called without arguments by the native plugin; layout is applied separately.

// @include "list/Core.as"

// @include "list/Entries.as"

// @include "list/Layout.as"

// @include "list/Overflow.as"

// @include "list/Diagnostics.as"

// @include "list/Debug.as"

// @include "list/Calibration.as"

stop();
