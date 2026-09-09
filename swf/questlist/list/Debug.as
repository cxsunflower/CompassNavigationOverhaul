// A diagnostic sibling of the HUD content, never a child of DetailBox or the
// viewport mask. Its graphics and labels cannot contribute to layout bounds.
function SetLayoutDebug(a_enabled:Boolean):Void
{
    layoutDebugEnabled = a_enabled == true;
    layoutDebugKey = "";
    if (!layoutDebugEnabled && layoutDebugOverlay != undefined)
    {
        layoutDebugOverlay._visible = false;
        layoutDebugOverlay.Lines.clear();
        layoutDebugOverlay.drawnRegions = 0;
        for (var i:Number = 0; i < layoutDebugLabelCount; i++)
            layoutDebugOverlay.Labels["Region"+i].removeTextField();
        layoutDebugLabelCount = 0;
    }
    // A newly enabled diagnostic must not wait for the next visible HUD frame.
    if (layoutDebugEnabled) UpdateLayoutDebug();
}

// Observe the normal HUD gate without using it to hide the diagnostic itself.
// In particular, an invisible parent must not prevent us from reporting why
// the QuestList is invisible. This never changes the original display list.
function GetLayoutDebugVisibility():Object
{
    if (dedicatedPanel) return {visible:entries.length > 0,reason:entries.length > 0 ? "dedicated panel" : "no entries"};
    var reason:String = "visible";
    if (entries.length == 0) reason = "no entries";
    else if (anchorText == undefined) reason = "no anchor";
    else if (_alpha <= 0) reason = "list alpha";
    for (var ancestor:MovieClip = this; ancestor != undefined; ancestor = ancestor._parent)
    {
        if (ancestor._visible == false || ancestor._alpha <= 0)
        {
            reason = "hidden ancestor: " + ancestor._name;
            break;
        }
    }
    var holder:MovieClip = _root.HUDMovieBaseInstance.CompassShoutMeterHolder;
    if (holder == undefined || holder.Compass == undefined || holder.Compass.DirectionRect == undefined)
        reason = "compass holder missing";
    else if (holder.Compass.DirectionRect._alpha <= 0 || holder._alpha <= 0)
        reason = "compass alpha";
    return {visible:reason == "visible",reason:reason};
}

// Read by the native settings/snapshot diagnostics, not by the normal frame loop.
function GetLayoutDebugState():String
{
    var state:Object = GetLayoutDebugVisibility();
    return "enabled=" + layoutDebugEnabled + "; overlay=" + (layoutDebugOverlay != undefined) +
        "; overlayVisible=" + (layoutDebugOverlay != undefined && layoutDebugOverlay._visible) +
        "; drawnRegions=" + (layoutDebugOverlay != undefined ? layoutDebugOverlay.drawnRegions : 0) +
        "; entries=" + entries.length + "; hudVisible=" + state.visible +
        "; reason=" + state.reason + "; root=" + _root + "; parent=" + _parent;
}

function GetLayoutDebugGeometry(a_region:Object):Object
{
    var rect:Object = a_region.rect;
    var corners:Array = [{x:rect.xMin,y:rect.yMin},{x:rect.xMax,y:rect.yMin},
        {x:rect.xMax,y:rect.yMax},{x:rect.xMin,y:rect.yMax}];
    var bounds:Object = {xMin:Number.POSITIVE_INFINITY,yMin:Number.POSITIVE_INFINITY,
        xMax:Number.NEGATIVE_INFINITY,yMax:Number.NEGATIVE_INFINITY};
    for (var i:Number = 0; i < corners.length; i++)
    {
        a_region.clip.localToGlobal(corners[i]);
        // Overlay, clipping viewport and labels all live in root coordinates.
        // Layout itself remains Target-local; never mix those two spaces.
        _root.globalToLocal(corners[i]);
        bounds.xMin = Math.min(bounds.xMin,corners[i].x);
        bounds.yMin = Math.min(bounds.yMin,corners[i].y);
        bounds.xMax = Math.max(bounds.xMax,corners[i].x);
        bounds.yMax = Math.max(bounds.yMax,corners[i].y);
    }
    return {name:a_region.name, points:corners, bounds:bounds,
        localWidth:rect.xMax-rect.xMin, localHeight:rect.yMax-rect.yMin,
        visible:a_region.visible, color:a_region.color};
}

function LayoutDebugNumber(a_value:Number):String
{
    return isFinite(a_value) ? String(Math.round(a_value*10)/10) : "n/a";
}

function LayoutDebugRectText(a_region:Object):String
{
    var b:Object = a_region.bounds;
    return a_region.name + (a_region.visible ? "" : " [HIDDEN]") + "  x=" + LayoutDebugNumber(b.xMin) +
        " y=" + LayoutDebugNumber(b.yMin) + "  w=" + LayoutDebugNumber(b.xMax-b.xMin) +
        " h=" + LayoutDebugNumber(b.yMax-b.yMin);
}

function GetLayoutDebugData():Object
{
    var regions:Array = new Array();
    var visibleRows:Number = 0;
    var totalRows:Number = 0;
    for (var i:Number = 0; i < Math.min(8,entries.length); i++)
    {
        var item:QuestItem = entries[i];
        var itemRegions:Array = item.GetLayoutDebugRegions();
        for (var j:Number = 0; j < itemRegions.length; j++)
        {
            var sourceRegion:Object = itemRegions[j];
            var region:Object = {name:"Q" + i + "/" + sourceRegion.name, clip:sourceRegion.clip, rect:sourceRegion.rect, visible:sourceRegion.visible, color:sourceRegion.color};
            regions.push(GetLayoutDebugGeometry(region));
        }
    }
    for (var k:Number = 0; k < entries.length; k++)
    {
        totalRows += entries[k].ObjectiveItemList.length;
        // Debug statistics are observational only. Do not use debug code to
        // participate in visibility decisions or gate the QuestList render path.
        for (var n:Number = 0; n < entries[k].ObjectiveItemList.length; n++)
            visibleRows++;
    }
    AddHudReferenceDebugRegions(regions);
    var full:Object = GetFullBoundsInRoot();
    var localFull:Object = GetFullBoundsInSpace(GetLayoutSpace());
    var visibility:Object = GetLayoutDebugVisibility();
    var lines:Array = ["QUESTLIST DEBUG / root coordinates",
        "HUD: " + visibility.reason + " | diagnostic enabled=" + layoutDebugEnabled,
        "Stage " + Stage.width + " x " + Stage.height + " | scale " + TEXT_SCALE + "% -> " + effectiveScale + "%",
        "Viewport bottom " + LayoutDebugNumber(GetViewportBottom()) + " | content limit " + LayoutDebugNumber(omissionLimit),
        "Content limit " + LayoutDebugNumber(omissionLimit) + " | visible bottom " + LayoutDebugNumber(lastVisibleBottom),
        "Full bottom " + LayoutDebugNumber(full.yMax) + " | rows " + visibleRows + "/" + totalRows,
        "Layout space " + (compassPassengerMode && !dedicatedPanel ? "Target" : "root") +
            " | local bottom " + LayoutDebugNumber(localFull.yMax),
        "Fit: " + fitReason + " | overflow=" + fitOverflow,
        "Omit: " + omissionReason,
        "Red=layout  Orange=header  Cyan=mask/limit",
        "Dashed=hidden | x,y,w,h are root-space bounds"];
    for (var p:Number = 0; p < regions.length; p++)
    {
        if (regions[p].name.indexOf("/Box") >= 0 || regions[p].name.indexOf("/Header") >= 0 ||
            regions[p].name.indexOf("/Body") >= 0 ||
            regions[p].name.indexOf("/Description") >= 0)
            lines.push(LayoutDebugRectText(regions[p]));
    }
    var signature:String = lines.join("\n");
    for (var r:Number = 0; r < regions.length; r++)
    {
        var entry:Object = regions[r];
        signature += ";" + LayoutDebugRectText(entry) + ",L=" + LayoutDebugNumber(entry.localWidth) +
            "," + LayoutDebugNumber(entry.localHeight);
        for (var c:Number = 0; c < entry.points.length; c++)
            signature += "," + LayoutDebugNumber(entry.points[c].x) + "," + LayoutDebugNumber(entry.points[c].y);
    }
    return {regions:regions, lines:lines, signature:signature, totalRows:totalRows, visibleRows:visibleRows};
}

// Debug-only coordinate references. These are outside QuestList layout and
// cannot affect DetailBox measurement or overflow decisions.
function AddHudReferenceDebugRegions(a_regions:Array):Void
{
    if (dedicatedPanel) return;
    var holder:MovieClip = _root.HUDMovieBaseInstance.CompassShoutMeterHolder;
    if (holder == undefined || holder.Compass == undefined) return;

    var compassClip:MovieClip = holder.Compass.CompassMask_mc != undefined ? holder.Compass.CompassMask_mc : holder.Compass.DirectionRect;
    if (compassClip == undefined) return;
    var compass:Object = compassClip.getBounds(_root);
    a_regions.push(GetLayoutDebugGeometry({name:"Compass", clip:_root,
        rect:compass, visible:true, color:0x00FF66}));

    if (anchorText != undefined)
    {
        // AS2 TextField has no getBounds/localToGlobal. Its rectangle lives
        // in its parent's space; transform the four corners through that clip.
        var target:Object = {xMin:anchorText._x,yMin:anchorText._y,
            xMax:anchorText._x+anchorText._width,yMax:anchorText._y+anchorText._height};
        a_regions.push(GetLayoutDebugGeometry({name:"TargetText", clip:anchorText._parent,
            rect:target, visible:true, color:0xFFFF00}));
    }
}

function LayoutDebugText(a_name:String, a_text:String, a_x:Number, a_y:Number, a_width:Number, a_height:Number, a_size:Number):TextField
{
    var labels:MovieClip = layoutDebugOverlay.Labels;
    var field:TextField = labels[a_name];
    if (field == undefined)
    {
        labels.createTextField(a_name, labels.getNextHighestDepth(), 0, 0, a_width, a_height);
        field = labels[a_name];
        var format:TextFormat = new TextFormat();
        format.font = "$EverywhereMediumFont";
        format.size = a_size;
        format.color = 0xFFFFFF;
        format.bold = false;
        field.setNewTextFormat(format);
        field.embedFonts = true;
        field.background = false;
        field.border = false;
        field.selectable = false;
        field.mouseEnabled = false;
        field.filters = [new flash.filters.GlowFilter(0x000000,1,2,2,3,1,false,false)];
        field.multiline = true;
        field.wordWrap = false;
        field.autoSize = false;
    }
    field._x = a_x; field._y = a_y;
    field._width = a_width; field._height = a_height;
    field.text = a_text;
    field._visible = true;
    return field;
}

// Convert the actual logical viewport to root space. The four corners are
// retained for the mask; the AABB is used only for bounded label placement.
function GetLayoutDebugRootViewport():Object
{
    var rect:Object = GetViewportBounds();
    var space:MovieClip = GetLayoutSpace();
    var points:Array = [{x:rect.xMin,y:rect.yMin},{x:rect.xMax,y:rect.yMin},
        {x:rect.xMax,y:rect.yMax},{x:rect.xMin,y:rect.yMax}];
    var bounds:Object = {xMin:Number.POSITIVE_INFINITY,yMin:Number.POSITIVE_INFINITY,
        xMax:Number.NEGATIVE_INFINITY,yMax:Number.NEGATIVE_INFINITY};
    for (var i:Number = 0; i < points.length; i++)
    {
        space.localToGlobal(points[i]);
        _root.globalToLocal(points[i]);
        bounds.xMin = Math.min(bounds.xMin,points[i].x);
        bounds.yMin = Math.min(bounds.yMin,points[i].y);
        bounds.xMax = Math.max(bounds.xMax,points[i].x);
        bounds.yMax = Math.max(bounds.yMax,points[i].y);
    }
    if (compassPassengerMode && !dedicatedPanel)
    {
        bounds.yMin = Math.max(bounds.yMin,GetSharedHudSafeTop());
        bounds.yMax = Math.min(bounds.yMax,GetSharedHudSafeBottom());
    }
    return {points:points,bounds:bounds};
}

function LayoutDebugRectsOverlap(a:Object,b:Object):Boolean
{
    return a.xMin < b.xMax && a.xMax > b.xMin && a.yMin < b.yMax && a.yMax > b.yMin;
}

// Clip every segment before drawing. A root-level diagnostic must not create
// full-stage lines or off-window text that can leak into another HUD region.
function LayoutDebugClipSegment(a:Object,b:Object,r:Object):Object
{
    var dx:Number = b.x-a.x;
    var dy:Number = b.y-a.y;
    var p:Array = [-dx,dx,-dy,dy];
    var q:Array = [a.x-r.xMin,r.xMax-a.x,a.y-r.yMin,r.yMax-a.y];
    var low:Number = 0;
    var high:Number = 1;
    for (var i:Number = 0; i < 4; i++)
    {
        if (p[i] == 0)
        {
            if (q[i] < 0) return undefined;
        }
        else
        {
            var t:Number = q[i]/p[i];
            if (p[i] < 0) low = Math.max(low,t);
            else high = Math.min(high,t);
            if (low > high) return undefined;
        }
    }
    return {a:{x:a.x+dx*low,y:a.y+dy*low},b:{x:a.x+dx*high,y:a.y+dy*high}};
}

function DrawLayoutDebugLine(a:Object,b:Object,r:Object):Void
{
    if (!isFinite(a.x) || !isFinite(a.y) || !isFinite(b.x) || !isFinite(b.y)) return;
    var segment:Object = LayoutDebugClipSegment(a,b,r);
    if (segment == undefined) return;
    layoutDebugOverlay.Lines.moveTo(segment.a.x,segment.a.y);
    layoutDebugOverlay.Lines.lineTo(segment.b.x,segment.b.y);
}

function DrawLayoutDebugRegion(a_region:Object):Void
{
    var r:Object = GetLayoutDebugRootViewport().bounds;
    var points:Array = a_region.points;
    var lines:MovieClip = layoutDebugOverlay.Lines;
    lines.lineStyle(a_region.name.indexOf("/Box") >= 0 ? 2 : 1,a_region.color,100);
    for (var i:Number = 0; i < 4; i++)
    {
        var a:Object = points[i];
        var b:Object = points[(i+1)%4];
        if (a_region.visible) DrawLayoutDebugLine(a,b,r);
        else
        {
            var length:Number = Math.sqrt((b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y));
            var count:Number = Math.max(1,Math.ceil(length/10));
            for (var d:Number = 0; d < count; d += 2)
            {
                var start:Number = d/count;
                var end:Number = Math.min(d+1,count)/count;
                DrawLayoutDebugLine({x:a.x+(b.x-a.x)*start,y:a.y+(b.y-a.y)*start},
                    {x:a.x+(b.x-a.x)*end,y:a.y+(b.y-a.y)*end},r);
            }
        }
    }
}

function UpdateLayoutDebug():Void
{
    if (!layoutDebugEnabled || calibrationEnabled) return;
    if (layoutDebugOverlay == undefined)
    {
        layoutDebugOverlay = _root.QuestListLayoutDebugOverlay;
        if (layoutDebugOverlay == undefined)
        {
            layoutDebugOverlay = _root.createEmptyMovieClip("QuestListLayoutDebugOverlay",_root.getNextHighestDepth());
            layoutDebugOverlay.createEmptyMovieClip("Lines",layoutDebugOverlay.getNextHighestDepth());
            layoutDebugOverlay.createEmptyMovieClip("Summary",layoutDebugOverlay.getNextHighestDepth());
            layoutDebugOverlay.createEmptyMovieClip("Labels",layoutDebugOverlay.getNextHighestDepth());
        }
        layoutDebugOverlay.layoutDebugOwner = this;
        layoutDebugOverlay.drawnRegions = 0;
        layoutDebugOverlay.mouseEnabled = false;
        layoutDebugOverlay.tabEnabled = false;
        // Segments and labels are bounded explicitly; no filled debug mask.
        if (layoutDebugOverlay.ClipMask != undefined)
            layoutDebugOverlay.ClipMask.removeMovieClip();
    }
    // Observe hidden content without changing its own visibility or the HUD gate.
    layoutDebugOverlay._visible = true;
    layoutDebugOverlay._alpha = 100;
    var data:Object = GetLayoutDebugData();
    var viewport:Object = GetLayoutDebugRootViewport();
    var r:Object = viewport.bounds;
    var signature:String = data.signature + ";" + Stage.width + "," + Stage.height +
        ";" + r.xMin + "," + r.yMin + "," + r.xMax + "," + r.yMax;
    for (var z:Number = 0; z < viewport.points.length; z++)
        signature += ";" + viewport.points[z].x + "," + viewport.points[z].y;
    if (signature == layoutDebugKey) return;
    var lines:MovieClip = layoutDebugOverlay.Lines;
    lines.clear();
    layoutDebugOverlay.drawnRegions = 0;
    // Purple: actual Passenger rectangle, not three arbitrary stage Y values.
    lines.lineStyle(1,0xAA00FF,100);
    for (var e:Number = 0; e < 4; e++)
        DrawLayoutDebugLine(viewport.points[e],viewport.points[(e+1)%4],r);
    // Green: Compass's own mask/direction geometry, excluding QuestList.
    var compass:Object = undefined;
    for (var c:Number = 0; c < data.regions.length; c++)
        if (data.regions[c].name == "Compass") compass = data.regions[c];
    if (compass != undefined) DrawLayoutDebugRegion(compass);
    for (var all:Number = 0; all < data.regions.length; all++)
    {
        if (data.regions[all].name != "Compass" && data.regions[all].visible)
            DrawLayoutDebugRegion(data.regions[all]);
    }
    layoutDebugOverlay.drawnRegions = data.regions.length;
    // Red is the real viewport bottom in the same coordinate system.
    var localViewport:Object = GetViewportBounds();
    var space:MovieClip = GetLayoutSpace();
    var bottomLeft:Object = {x:localViewport.xMin,y:localViewport.yMax};
    var bottomRight:Object = {x:localViewport.xMax,y:localViewport.yMax};
    space.localToGlobal(bottomLeft);space.localToGlobal(bottomRight);
    _root.globalToLocal(bottomLeft);_root.globalToLocal(bottomRight);
    lines.lineStyle(1,0xFF3030,100);
    DrawLayoutDebugLine(bottomLeft,bottomRight,r);
    // Cyan is the actual omission limit, not a duplicate of the bottom line.
    if (isFinite(omissionLimit) && omissionLimit < localViewport.yMax && omissionLimit > localViewport.yMin)
    {
        var cutLeft:Object = {x:localViewport.xMin,y:omissionLimit};
        var cutRight:Object = {x:localViewport.xMax,y:omissionLimit};
        space.localToGlobal(cutLeft);space.localToGlobal(cutRight);
        _root.globalToLocal(cutLeft);_root.globalToLocal(cutRight);
        lines.lineStyle(1,0x00DDEE,100);
        DrawLayoutDebugLine(cutLeft,cutRight,r);
    }
    // Only primary quest boxes receive on-screen labels. The full per-row and
    // per-section geometry remains available in GetLayoutDebugData/log snapshots.
    var labelCount:Number = 0;
    var placedLabels:Array = new Array();
    var firstTop:Number = r.yMax;
    for (var j:Number = 0; j < data.regions.length; j++)
    {
        var region:Object = data.regions[j];
        if (region.name.indexOf("/Box") < 0 || region.name.indexOf("/Box") != region.name.length-4) continue;
        if (labelCount >= 3) break;
        var b:Object = region.bounds;
        firstTop = Math.min(firstTop,b.yMin);
        // Geometry was already drawn above; this pass only places labels.
        var labelWidth:Number = Math.min(160,Math.max(1,r.xMax-r.xMin-8));
        var labelHeight:Number = 18;
        var x:Number = Math.max(r.xMin+4,Math.min(r.xMax-labelWidth-4,b.xMin+2));
        var y:Number = b.yMin-labelHeight-2;
        if (y < r.yMin+2) y = b.yMin+2;
        y = Math.max(r.yMin+2,Math.min(r.yMax-labelHeight-2,y));
        var labelRect:Object = {xMin:x,yMin:y,xMax:x+labelWidth,yMax:y+labelHeight};
        var free:Boolean = true;
        for (var n:Number = 0; n < placedLabels.length; n++)
            if (LayoutDebugRectsOverlap(labelRect,placedLabels[n])) free = false;
        if (free && labelWidth >= 48 && r.yMax-r.yMin >= 24)
        {
            var debugName:String = region.name;
            debugName += " R (";
            debugName += ") L " + LayoutDebugNumber(region.localWidth) + "x" + LayoutDebugNumber(region.localHeight);
            LayoutDebugText("Region"+labelCount,debugName,x,y,labelWidth,labelHeight,12);
            placedLabels.push(labelRect);
            labelCount++;
        }
    }
    for (var h:Number = labelCount; h < layoutDebugLabelCount; h++)
        layoutDebugOverlay.Labels["Region"+h].removeTextField();
    layoutDebugLabelCount = labelCount;
    // A short status is enough on the HUD. Detailed coordinates belong in the
    // on-demand native log, never a 480px-wide full-stage report panel.
    var summary:MovieClip = layoutDebugOverlay.Summary;
    summary.clear();
    var visibility:Object = GetLayoutDebugVisibility();
    var status:String = "QuestList: " + visibility.reason + " | " + data.visibleRows + "/" + data.totalRows;
    var showStatus:Boolean = !visibility.visible || entries.length == 0 || firstTop-r.yMin >= 24;
    if (showStatus && r.xMax-r.xMin >= 80 && r.yMax-r.yMin >= 24)
    {
        var panelWidth:Number = Math.min(240,r.xMax-r.xMin-8);
        // Debug summary uses text/lines only. Do not create a filled panel
        // because the debug layer is overlaid directly on the VR HUD.
        summary.lineStyle(1,0xAAAAAA,100);
        summary.moveTo(r.xMin+2,r.yMin+2);
        summary.lineTo(r.xMin+panelWidth+6,r.yMin+2);
        summary.lineTo(r.xMin+panelWidth+6,r.yMin+22);
        summary.lineTo(r.xMin+2,r.yMin+22);
        summary.lineTo(r.xMin+2,r.yMin+2);
        LayoutDebugText("SummaryText",status,r.xMin+4,r.yMin+3,panelWidth,18,12);
    }
    else if (layoutDebugOverlay.Labels.SummaryText != undefined)
        layoutDebugOverlay.Labels.SummaryText._visible = false;
    layoutDebugKey = signature;
}

function onUnload():Void
{
    if (calibrationOverlay != undefined) calibrationOverlay.removeMovieClip();
    calibrationOverlay = undefined;
    if (layoutDebugOverlay != undefined && layoutDebugOverlay.layoutDebugOwner == this)
        layoutDebugOverlay.removeMovieClip();
    layoutDebugOverlay = undefined;
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
        layoutDebugKey = "";
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
    if (layoutDebugOverlay != undefined) layoutDebugOverlay._visible = false;
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

