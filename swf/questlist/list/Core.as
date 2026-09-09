function QuestItemList():Void
{
    entries = new Array();
    entriesByKey = new Object();
    All = true;
    Favor = true;
    StealthMode = true;
    Swimming = true;
    HorseMode = true;
    WarHorseMode = true;
}

// VR_HMD_info has no HUDMenu HudElements array.
function AddToHudElements():Void {}

// A dedicated world-space movie has its own complete texture. The anchor is
// local to that movie, never a TextField from the shared VR HUD atlas.
function SetPanelSurface():Void
{
    dedicatedPanel = true;
    _parent.createTextField("TextFieldInstance",_parent.getNextHighestDepth(),
        Stage.width*0.5-100,16,200,1);
    _parent.TextFieldInstance._visible = false;
    anchorText = _parent.TextFieldInstance;
    anchorGap = 12;
    fitKey = "";
}

function SetAnchor(a_text:TextField, a_gap:Number):Void
{
    anchorText = a_text;
    anchorGap = a_gap;
    UpdateAnchor();
}

function UpdateAnchor():Void
{
    // The list and label are siblings in Target. Passenger limits follow the
    // anchor; they must never be compared with an unrelated root-space Y=0.
    var liveText:TextField = _parent.TextFieldInstance;
    if (liveText != undefined)
    {
        anchorText = liveText;
    }
    if (anchorText == undefined || entries.length == 0)
    {
        return;
    }
    var first:Object = entries[0].GetContentBounds(this);
    var minX:Number = first.xMin;
    var maxX:Number = first.xMax;
    var minY:Number = first.yMin;
    for (var i:Number = 1; i < entries.length; i++)
    {
        var bounds:Object = entries[i].GetContentBounds(this);
        minX = Math.min(minX, bounds.xMin);
        maxX = Math.max(maxX, bounds.xMax);
        minY = Math.min(minY, bounds.yMin);
    }
    var x:Number = anchorText._x + anchorText._width * 0.5 + offsetX;
    var y:Number = anchorText._y + anchorText._height + anchorGap + offsetY;
    if (compassPassengerMode && !dedicatedPanel)
    {
        var viewport:Object = GetViewportBounds();
        x = (viewport.xMin + viewport.xMax) * 0.5;
        // Keep one tenth beyond the 4px gutter for Scaleform twip rounding.
        y = viewport.yMin + 4.1;
    }
    if (isNaN(x) || isNaN(y) || !isFinite(minX) || !isFinite(maxX) || !isFinite(minY))
    {
        return;
    }
    _x = x - (minX + maxX) * 0.5 * _xscale / 100;
    _y = y - minY * _yscale / 100;
}

function onEnterFrame():Void
{
    Update();
}

function SetOffsets(a_x:Number, a_y:Number):Void
{
    if (isNaN(a_x) || isNaN(a_y) || !isFinite(a_x) || !isFinite(a_y)) return;
    var nextX:Number = Math.max(-100,Math.min(100,a_x));
    var nextY:Number = Math.max(-100,Math.min(100,a_y));
    if (nextX == offsetX && nextY == offsetY) return;
    offsetX = nextX;
    offsetY = nextY;
    fitKey = "";
    UpdateAnchor();
}

function SetTextScale(a_scale:Number):Void
{
	if (isNaN(a_scale) || !isFinite(a_scale)) return;
	TEXT_SCALE = Math.max(25, Math.min(110, a_scale));
    fitKey = "";

	for (var i:Number = 0; i < entries.length; i++)
	{
		entries[i]._xscale = SCALE * TEXT_SCALE / 100;
		entries[i]._yscale = SCALE * TEXT_SCALE / 100;
	}
}

function SetQuestSide(a_side:String):Void
{
	questItem.SetSide(a_side);
}

function Update():Void
{
    if (calibrationEnabled) { UpdateCalibration(); return; }
    var hud:MovieClip = _root.HUDMovieBaseInstance;
    var holder:MovieClip = hud != undefined ? hud.CompassShoutMeterHolder : undefined;
    if (dedicatedPanel || (holder != undefined && holder.Compass != undefined &&
        holder.Compass.DirectionRect != undefined && holder.Compass.DirectionRect._alpha && holder._alpha))
    {
        entries.sort(ByAgeThenMiscellaneousQuests);
        if (compassPassengerMode && !dedicatedPanel)
        {
            // Normalize the authored wrapper once. The solver owns item scale.
            _xscale = 100;
            _yscale = 100;
        }
        var space:MovieClip = GetLayoutSpace();
        var viewport:Object = GetViewportBounds();
        if (entries.length > 0 && anchorText != undefined) FitLayout();
        var limit:Number = PrepareOverflowLabel(viewport.yMax);
        for (var i:Number = 0; i < entries.length; i++)
        {
            var bounds:Object = entries[i].GetContentBounds(space);
            // Keep a complete header. Long bodies are omitted only after
            // fitting; they must not cause the entire quest to disappear.
            entries[i]._visible = bounds.yMin >= viewport.yMin &&
                bounds.xMin >= viewport.xMin && bounds.xMax <= viewport.xMax &&
                entries[i].GetHeaderBottomInSpace(space) <= limit;
            entries[i].ApplyHeightLimit(limit,space);
        }
        lastVisibleBottom = GetVisibleBottomInRoot(limit);
        UpdateViewportMask();
        _alpha = 100;
    }
    else _alpha = 0;
    if (layoutDebugEnabled) UpdateLayoutDebug();
}
