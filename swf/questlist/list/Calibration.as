// Independent tool. Not the ordinary HUD observer.
function onUnload():Void
{
    if (calibrationOverlay != undefined) calibrationOverlay.removeMovieClip();
    calibrationOverlay = undefined;
}

// Independent measurement sibling: no QuestList mask, fit solver or safe-area clamp.
// Coordinates printed here are SWF root coordinates, NOT physical screen pixels.
function SetCalibration(a_enabled:Boolean, a_axis:Number, a_start:Number, a_step:Number, a_cross:Number):Void
{
    if (!isFinite(a_axis) || !isFinite(a_start) || !isFinite(a_step) || !isFinite(a_cross)) return;
    calibrationEnabled = a_enabled == true;
    calibrationAxis = a_axis == 1 ? 1 : 0;
    calibrationStart = Math.max(0,Math.min(1024,a_start));
    calibrationStep = Math.max(2,Math.min(80,a_step));
    calibrationCross = Math.max(12,Math.min(1012,a_cross));
    if (!calibrationEnabled)
    {
        if (calibrationOverlay != undefined) calibrationOverlay.removeMovieClip();
        calibrationOverlay = undefined;
        fitKey = "";
        Update();
    }
    else UpdateCalibration();
}

function CalibrationPoint(a_x:Number,a_y:Number):Object
{
    var point:Object = {x:a_x,y:a_y};
    _root.localToGlobal(point);
    calibrationOverlay.globalToLocal(point);
    return point;
}

function UpdateCalibration():Void
{
    if (!calibrationEnabled) return;
    // Only hide our own normal content; never change parent visibility or alpha.
    _alpha = 0;
    if (calibrationOverlay == undefined)
    {
        calibrationOverlay = _parent.createEmptyMovieClip("QuestListCalibration",_parent.getNextHighestDepth());
        calibrationOverlay.mouseEnabled = false;
        calibrationOverlay.tabEnabled = false;
    }
    calibrationOverlay.clear();
    calibrationOverlay._visible = true;
    for (var i:Number = 0; i < 9; i++)
    {
        var value:Number = calibrationStart+i*calibrationStep;
        var field:TextField = calibrationOverlay["Tick"+i];
        if (field == undefined)
        {
            calibrationOverlay.createTextField("Tick"+i,calibrationOverlay.getNextHighestDepth(),0,0,100,20);
            field = calibrationOverlay["Tick"+i];
            var format:TextFormat = new TextFormat();
            format.font = "$EverywhereMediumFont";
            format.size = 12;
            format.color = 0xFFFFFF;
            field.setNewTextFormat(format);
            field.embedFonts = true;
            field.background = false;
            field.border = false;
            field.selectable = false;
            field.wordWrap = false;
        }
        field._visible = value <= (calibrationAxis == 0 ? Stage.height : Stage.width);
        if (field._visible)
        {
            var x:Number = calibrationAxis == 0 ? calibrationCross : value;
            var y:Number = calibrationAxis == 0 ? value : calibrationCross;
            calibrationOverlay.lineStyle(1,i%2 == 0 ? 0x00FFFF : 0xFFAA00,100);
            // Short crosshair, no filled rectangles and no implicit clipping.
            var left:Object = CalibrationPoint(x-8,y);
            var right:Object = CalibrationPoint(x+8,y);
            var top:Object = CalibrationPoint(x,y-4);
            var bottom:Object = CalibrationPoint(x,y+4);
            calibrationOverlay.moveTo(left.x,left.y);calibrationOverlay.lineTo(right.x,right.y);
            calibrationOverlay.moveTo(top.x,top.y);calibrationOverlay.lineTo(bottom.x,bottom.y);
            var label:Object = CalibrationPoint(x+12,y-6);
            field._x = label.x;field._y = label.y;
            field.text = (calibrationAxis == 0 ? "Y=" : "X=") + value;
        }
    }
}

function GetCalibrationState():String
{
    return "enabled=" + calibrationEnabled + "; axis=" + calibrationAxis +
        "; start=" + calibrationStart + "; step=" + calibrationStep + "; cross=" + calibrationCross +
        "; coordinates=root; parent=" + _parent + "; stage=" + Stage.width + "," + Stage.height;
}
