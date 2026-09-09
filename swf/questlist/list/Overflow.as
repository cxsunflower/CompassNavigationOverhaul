

// A full section may be hidden only after testing it against the real safe
// limit. Reserve an omission line only when content is actually omitted.
function GetVisibleBottomInRoot(a_limit:Number):Number
{
    var space:MovieClip = GetLayoutSpace();
    var bottom:Number = Number.NEGATIVE_INFINITY;
    for (var i:Number = 0; i < entries.length; i++)
    {
        if (entries[i].GetHeaderBottomInSpace(space) <= a_limit)
            bottom = Math.max(bottom, entries[i].GetVisibleContentBottom(space));
    }
    return bottom;
}

function PrepareOverflowLabel(a_limit:Number):Number
{
    if (overflowLabel == undefined)
    {
        this.createTextField("overflowLabel", this.getNextHighestDepth(), 0, 0, 96, 34);
        var format:TextFormat = new TextFormat();
        format.font = "$EverywhereMediumFont";
        format.size = 24;
        format.color = 0xFFFFFF;
        overflowLabel.setNewTextFormat(format);
        overflowLabel.text = ". . .";
        overflowLabel.setTextFormat(format);
        overflowLabel.selectable = false;
        overflowLabel.wordWrap = false;
        overflowLabel.filters = [new flash.filters.GlowFilter(0x000000,1,3,3,3,2,false,false)];
    }
    overflowLabel._visible = false;
    // Match the fitted quest items, not an unscaled 34px reservation.
    overflowLabel._xscale = SCALE * effectiveScale / 100;
    overflowLabel._yscale = SCALE * effectiveScale / 100;
    var space:MovieClip = GetLayoutSpace();
    var viewport:Object = GetViewportBounds();
    lastSafeLimit = a_limit;
    omissionLimit = a_limit;
    omissionReason = "none";
    lastVisibleBottom = 0;
    if (entries.length == 0) return a_limit;
    var omitted:Boolean = false;
    var readableDescriptions:Array = new Array();
    var readableObjectives:Array = new Array();
    for (var i:Number = 0; i < entries.length; i++)
    {
        entries[i].ApplyHeightLimit(a_limit,space);
        readableDescriptions.push(entries[i].DescriptionTextField._visible);
        var count:Number = 0;
        for (var r:Number = 0; r < entries[i].ObjectiveItemList.length; r++)
            if (entries[i].ObjectiveItemList[r]._visible) count++;
        readableObjectives.push(count);
        if (entries[i].HasOmittedContent() || entries[i].GetHeaderBottomInSpace(space) > a_limit)
            omitted = true;
    }
    if (!omitted)
    {
        lastVisibleBottom = GetVisibleBottomInRoot(a_limit);
        return a_limit;
    }
    var rect:Object = entries[0].GetContentBounds(space);
    overflowLabel._x = 0;
    overflowLabel._y = 0;
    var bounds:Object = TextBoundsInSpace(overflowLabel,space);
    var height:Number = bounds.yMax - bounds.yMin;
    var reduced:Number = a_limit - height - 8;
    var lostDescription:Boolean = false;
    var lostLastObjective:Boolean = false;
    for (var j:Number = 0; j < entries.length; j++)
    {
        entries[j].ApplyHeightLimit(reduced,space);
        if (readableDescriptions[j] && !entries[j].DescriptionTextField._visible)
            lostDescription = true;
        var remaining:Number = 0;
        for (var n:Number = 0; n < entries[j].ObjectiveItemList.length; n++)
            if (entries[j].ObjectiveItemList[n]._visible) remaining++;
        if (readableObjectives[j] > 0 && remaining == 0) lostLastObjective = true;
    }
    var visibleBottom:Number = GetVisibleBottomInRoot(reduced);
    var labelTop:Number = visibleBottom + 4;
    if (lostDescription || lostLastObjective || !isFinite(visibleBottom) || labelTop + height > a_limit ||
        reduced <= viewport.yMin || rect.xMin+(bounds.xMax-bounds.xMin) > viewport.xMax)
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
    var position:Object = {x:Math.max(viewport.xMin,rect.xMin),y:labelTop};
    space.localToGlobal(position);
    this.globalToLocal(position);
    overflowLabel._x = position.x;
    overflowLabel._y = position.y;
    overflowLabel._visible = true;
    omissionLimit = reduced;
    omissionReason = "complete sections omitted";
    lastVisibleBottom = visibleBottom;
    return reduced;
}
