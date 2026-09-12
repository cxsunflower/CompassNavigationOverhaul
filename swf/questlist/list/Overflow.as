// Build the fixed-size marker once; layout measures its drawn bounds.
function EnsureOverflowLabel():Void
{
    if (overflowLabel == undefined)
    {
        overflowLabel = this.createEmptyMovieClip("overflowLabel",this.getNextHighestDepth());
        // Three explicit dots: 3x3 white cores plus a 1-unit black border.
        // No font line box or blur: the complete visible extent is 23x5.
        overflowLabel.symbol = ". . .";
        for (var dot:Number = 0; dot < 3; dot++)
        {
            var x:Number = dot*9;
            overflowLabel.beginFill(0x000000,100);
            overflowLabel.moveTo(x,0); overflowLabel.lineTo(x+5,0);
            overflowLabel.lineTo(x+5,5); overflowLabel.lineTo(x,5); overflowLabel.lineTo(x,0);
            overflowLabel.endFill();
            overflowLabel.beginFill(0xFFFFFF,100);
            overflowLabel.moveTo(x+1,1); overflowLabel.lineTo(x+4,1);
            overflowLabel.lineTo(x+4,4); overflowLabel.lineTo(x+1,4); overflowLabel.lineTo(x+1,1);
            overflowLabel.endFill();
        }
    }
}

// Attempt placement without changing which complete rows are visible.
function TryPlaceOverflowLabel(a_limit:Number, a_bottom:Number):Boolean
{
    if (!isFinite(a_bottom)) return false;
    var space:MovieClip = GetLayoutSpace();
    var viewport:Object = GetViewportBounds();
    // Reserve the icon slot and gap logically; never pad text with spaces or
    // draw a dummy icon. Resolve the first omitted objective's text column in
    // layout space, so panel scaling and parent transforms remain correct.
    var position:Object;
    for (var a:Number = 0; a < entries.length && (overflowStopIndex < 0 || a <= overflowStopIndex) && position == undefined; a++)
    {
        var item:MovieClip = entries[a];
        if (item.GetHeaderBottomInSpace(space) > a_limit) continue;
        for (var b:Number = 0; b < item.ObjectiveItemList.length; b++)
        {
            var objective:MovieClip = item.ObjectiveItemList[b];
            if (!objective._visible)
            {
                position = {x:objective.TextFieldInstance._x,y:0};
                objective.localToGlobal(position);
                space.globalToLocal(position);
                break;
            }
        }
    }
    if (position == undefined)
    {
        // Non-objective omissions retain an aligned marker after visible content.
        position = {x:entries[0].GetContentBounds(space).xMin+26*SCALE*effectiveScale/100,y:a_bottom};
    }
    space.localToGlobal(position);
    this.globalToLocal(position);
    overflowLabel._x = position.x;
    overflowLabel._y = position.y;
    var actual:Object = overflowLabel.getBounds(space);
    if (!isFinite(actual.xMin) || !isFinite(actual.xMax) ||
        !isFinite(actual.yMin) || !isFinite(actual.yMax) ||
        actual.xMin < viewport.xMin || actual.xMax > viewport.xMax ||
        actual.yMin < viewport.yMin || actual.yMax > Math.min(a_limit,viewport.yMax)) return false;
    overflowLabel._visible = true;
    lastVisibleBottom = a_bottom;
    return true;
}

// Return the visible bottom in GetLayoutSpace (the legacy name is retained).
// Entries after the first omission never contribute to the visible extent.
function GetVisibleBottomInRoot(a_limit:Number):Number
{
    var space:MovieClip = GetLayoutSpace();
    var bottom:Number = Number.NEGATIVE_INFINITY;
    for (var i:Number = 0; i < entries.length; i++)
    {
        if ((overflowStopIndex < 0 || i <= overflowStopIndex) && entries[i].GetHeaderBottomInSpace(space) <= a_limit)
            bottom = Math.max(bottom, entries[i].GetVisibleContentBottom(space));
    }
    return bottom;
}

function PrepareOverflowLabel(a_limit:Number):Number
{
    EnsureOverflowLabel();
    overflowLabel._visible = false;
    // Match the fitted quest items; reserve only the drawn dots, including their border.
    overflowLabel._xscale = SCALE * effectiveScale / 100;
    overflowLabel._yscale = SCALE * effectiveScale / 100;
    var space:MovieClip = GetLayoutSpace();
    var viewport:Object = GetViewportBounds();
    lastSafeLimit = a_limit;
    omissionLimit = a_limit;
    omissionReason = "none";
    overflowStopIndex = -1;
    lastVisibleBottom = 0;
    if (entries.length == 0) return a_limit;
    var omitted:Boolean = false;
    for (var i:Number = 0; i < entries.length; i++)
    {
        entries[i].ApplyHeightLimit(a_limit,space);
        if (entries[i].HasOmittedContent() || entries[i].GetHeaderBottomInSpace(space) > a_limit)
        {
            if (overflowStopIndex < 0) overflowStopIndex = i;
            omitted = true;
        }
    }
    if (!omitted)
    {
        lastVisibleBottom = GetVisibleBottomInRoot(a_limit);
        return a_limit;
    }
    // Place a compact replacement at the first omitted objective, without
    // padding the marker or its empty horizontal icon slot to a text line.
    var currentBottom:Number = GetVisibleBottomInRoot(a_limit);
    if (TryPlaceOverflowLabel(a_limit,currentBottom))
    {
        omissionReason = "complete sections omitted; compact replacement";
        return a_limit;
    }
    // Only the rare reservation fallback needs snapshots and marker measurement.
    // Normal frames and direct compact replacements allocate neither array.
    var readableDescriptions:Array = new Array();
    var readableObjectives:Array = new Array();
    for (var i:Number = 0; i < entries.length; i++)
    {
        readableDescriptions.push(entries[i].DescriptionTextField._visible);
        var hasObjective:Boolean = false;
        for (var r:Number = 0; r < entries[i].ObjectiveItemList.length; r++)
        {
            if (entries[i].ObjectiveItemList[r]._visible) { hasObjective = true; break; }
        }
        readableObjectives.push(hasObjective);
    }
    overflowLabel._x = 0;
    overflowLabel._y = 0;
    var bounds:Object = overflowLabel.getBounds(space);
    var height:Number = bounds.yMax - bounds.yMin;
    var reduced:Number = a_limit - height;
    var lostDescription:Boolean = false;
    var lostLastObjective:Boolean = false;
    for (var j:Number = 0; j < entries.length; j++)
    {
        entries[j].ApplyHeightLimit(reduced,space);
        if (readableDescriptions[j] && !entries[j].DescriptionTextField._visible)
            lostDescription = true;
        if (readableObjectives[j])
        {
            var hasRemaining:Boolean = false;
            for (var n:Number = 0; n < entries[j].ObjectiveItemList.length; n++)
            {
                if (entries[j].ObjectiveItemList[n]._visible) { hasRemaining = true; break; }
            }
            if (!hasRemaining) lostLastObjective = true;
        }
    }
    var visibleBottom:Number = GetVisibleBottomInRoot(reduced);
    if (lostDescription || lostLastObjective || reduced <= viewport.yMin ||
        !TryPlaceOverflowLabel(a_limit,visibleBottom))
    {
        // Never discard another row merely to reserve a label that cannot
        // itself fit. The existing whole-section guard remains in force.
        for (var k:Number = 0; k < entries.length; k++)
            entries[k].ApplyHeightLimit(a_limit,space);
        omissionReason = lostDescription ? "preserve readable description" :
            (lostLastObjective ? "preserve last readable objective" : "no room for omission label");
        lastVisibleBottom = GetVisibleBottomInRoot(a_limit);
        return a_limit;
    }
    omissionLimit = reduced;
    omissionReason = "complete sections omitted";
    lastVisibleBottom = visibleBottom;
    return reduced;
}
