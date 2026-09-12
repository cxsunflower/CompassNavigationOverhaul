// Sole ordinary HUD observer. All drawing is a root sibling, never layout input.
// Root logical geometry is NOT a measured VR mesh/UV or pixel-occlusion result.
var debugEnabled:Boolean = false;
var debugCalibration:Boolean = false;
var debugOverlay:MovieClip;
var debugQueue:Array = new Array();
var debugDropped:Number = 0;
var debugLastSample:Number = -1000;
var debugLastText:Number = -1000;
var debugEventKey:String = "";
var debugSampleKey:String = "";
var debugForce:String = "enable";
var debugSummarySlot:Object;
var questListGate:String;
var debugTextBand:Object;
var debugSuppressed:String = "";
// Build injects labels from sprite 136. No seeking or guessed stationary pose.
var debugTimeline:Object = __CNO_DEBUG_TIMELINE__;

function SetDebugOverlay(a_enabled:Boolean, a_calibration:Boolean, a_snapshot:Boolean):Void
{
    var changed:Boolean = debugEnabled != a_enabled || debugCalibration != a_calibration;
    debugEnabled = a_enabled == true;
    debugCalibration = a_calibration == true;
    if (changed || a_snapshot) debugForce = a_snapshot ? "settings" : "toggle";
    if (!debugEnabled)
    {
        if (debugOverlay != undefined) debugOverlay.removeMovieClip();
        debugOverlay = undefined;
        debugQueue = new Array();
        debugDropped = 0;
        debugSummarySlot = undefined;
        debugEventKey = "";
        debugSampleKey = "";
        return;
    }
    if (debugOverlay == undefined || debugOverlay._parent == undefined)
    {
        // One observer per HUD movie; retire a stale owner after a Compass rebuild.
        var old:MovieClip = _root.CNOHUDDebug;
        if (old != undefined) old.removeMovieClip();
        debugOverlay = _root.createEmptyMovieClip("CNOHUDDebug", _root.getNextHighestDepth());
        debugOverlay.owner = this;
        debugOverlay.onEnterFrame = function() {
            if (this.owner == undefined || this.owner._parent == undefined) this.removeMovieClip();
            else this.owner.UpdateDebugOverlay();
        };
        debugOverlay.createEmptyMovieClip("Lines",1);
        debugOverlay.createEmptyMovieClip("Labels",2);
        debugForce = "rebuild";
    }
    if (changed || a_snapshot || debugForce != "") UpdateDebugOverlay();
}

function DebugVisibility(a_clip:Object):String
{
    if (a_clip == undefined) return "missing";
    for (var p:Object = a_clip; p != undefined; p = p._parent)
    {
        if (p._visible == false) return "hidden:" + p;
        if (p._alpha <= 0) return "alpha-zero:" + p;
    }
    return "visible";
}

function DebugNumber(a_value:Number):String
{
    return a_value != undefined && isFinite(a_value) ? String(Math.round(a_value*10)/10) : "n/a";
}

function DebugBounds(a_points:Array):Object
{
    if (a_points.length == 0) return undefined;
    var b:Object = {xMin:Number.POSITIVE_INFINITY,yMin:Number.POSITIVE_INFINITY,
        xMax:Number.NEGATIVE_INFINITY,yMax:Number.NEGATIVE_INFINITY};
    for (var i:Number = 0; i < a_points.length; i++)
    {
        var p:Object = a_points[i];
        if (!isFinite(p.x) || !isFinite(p.y)) return undefined;
        b.xMin = Math.min(b.xMin,p.x); b.xMax = Math.max(b.xMax,p.x);
        b.yMin = Math.min(b.yMin,p.y); b.yMax = Math.max(b.yMax,p.y);
    }
    return b;
}

function DebugRegion(a_id:String,a_clip:Object,a_color:Number,a_dash:Boolean,a_rect:Object,a_space:MovieClip):Object
{
    var region:Object = {id:a_id,clip:a_clip,color:a_color,dash:a_dash,
        reason:DebugVisibility(a_clip),points:new Array()};
    if (a_clip == undefined) return region;
    var field:Boolean = typeof(a_clip.text) == "string";
    var space:MovieClip = a_space != undefined ? a_space : (field ? a_clip._parent : a_clip);
    var r:Object = a_rect;
    if (r == undefined) r = field ? {xMin:a_clip._x,yMin:a_clip._y,
        xMax:a_clip._x+a_clip._width,yMax:a_clip._y+a_clip._height} : a_clip.getBounds(a_clip);
    region.localRect = r;
    region.space = space;
    region.points = [{x:r.xMin,y:r.yMin},{x:r.xMax,y:r.yMin},{x:r.xMax,y:r.yMax},{x:r.xMin,y:r.yMax}];
    for (var i:Number = 0; i < 4; i++)
    {
        space.localToGlobal(region.points[i]);
        _root.globalToLocal(region.points[i]);
    }
    region.bounds = DebugBounds(region.points);
    if (region.bounds == undefined) region.reason = "invalid-transform";
    return region;
}

// Convex polygon clipping preserves rotation, including reflected parent scales.
function DebugCross(a:Object,b:Object,p:Object):Number
{
    return (b.x-a.x)*(p.y-a.y)-(b.y-a.y)*(p.x-a.x);
}
function DebugClip(a_points:Array,a_window:Array):Array
{
    var result:Array = a_points.slice();
    if (a_window.length < 3) return new Array();
    var orientation:Number = DebugCross(a_window[0],a_window[1],a_window[2]) < 0 ? -1 : 1;
    for (var e:Number = 0; e < a_window.length && result.length > 0; e++)
    {
        var input:Array = result; result = new Array();
        var a:Object = a_window[e]; var b:Object = a_window[(e+1)%a_window.length];
        var previous:Object = input[input.length-1];
        var previousSide:Number = DebugCross(a,b,previous)*orientation;
        for (var i:Number = 0; i < input.length; i++)
        {
            var current:Object = input[i];
            var side:Number = DebugCross(a,b,current)*orientation;
            if ((side >= 0) != (previousSide >= 0))
            {
                var t:Number = previousSide/(previousSide-side);
                result.push({x:previous.x+t*(current.x-previous.x),y:previous.y+t*(current.y-previous.y)});
            }
            if (side >= 0) result.push({x:current.x,y:current.y});
            previous = current; previousSide = side;
        }
    }
    return result;
}

// Counterfactual IdleShow parent matrix from the authored SWF, using the current
// field scale. Ancestors remain current; this is not a physical stationary pose.
function DebugReference(a_region:Object):String
{
    var m:Object = debugTimeline.distanceRest;
    var r:Object = a_region.localRect;
    if (m == undefined || r == undefined || FocusedMarkerInfo == undefined) return "unavailable";
    var points:Array = [{x:r.xMin,y:r.yMin},{x:r.xMax,y:r.yMin},{x:r.xMax,y:r.yMax},{x:r.xMin,y:r.yMax}];
    var result:String = "authored-IdleShow-current-ancestors:frame="+debugTimeline.restFrame+";rootCorners=";
    for (var i:Number = 0; i < points.length; i++)
    {
        var p:Object = points[i];
        var point:Object = {x:m.x+p.x*m.sx+p.y*m.r1,y:m.y+p.x*m.r0+p.y*m.sy};
        FocusedMarkerInfo.localToGlobal(point); _root.globalToLocal(point);
        result += DebugNumber(point.x)+","+DebugNumber(point.y)+"/";
    }
    return result;
}

function DebugPhase():String
{
    var frame:Number = FocusedMarkerInfo._currentframe;
    var label:String = "unknown";
    for (var i:Number = 0; i < debugTimeline.labels.length; i++)
        if (frame >= debugTimeline.labels[i].frame) label = debugTimeline.labels[i].name;
    return label;
}
function DebugPhaseText(a_phase:String):String
{
    if (a_phase == "IdleShow") return "Info shown";
    if (a_phase == "IdleHide") return "Info hidden";
    if (a_phase == "FadeIn") return "Fade in";
    if (a_phase == "FadeOut") return "Fade out";
    return "Unknown";
}

function DebugOverlap(a:Object,b:Object):Number
{
    if (a == undefined || b == undefined) return undefined;
    var x:Number = Math.min(a.xMax,b.xMax)-Math.max(a.xMin,b.xMin);
    var y:Number = Math.min(a.yMax,b.yMax)-Math.max(a.yMin,b.yMin);
    return x > 0 && y > 0 ? Math.min(x,y) : 0;
}
function DebugRectText(a:Object):String
{
    if (a == undefined) return "n/a";
    return DebugNumber(a.xMin)+","+DebugNumber(a.yMin)+","+DebugNumber(a.xMax)+","+DebugNumber(a.yMax);
}
function DebugParents(a_clip:Object):String
{
    var result:String = "";
    for (var p:Object = a_clip; p != undefined; p = p._parent)
        result += "["+p+":xy="+DebugNumber(p._x)+","+DebugNumber(p._y)+
            ";scale="+DebugNumber(p._xscale)+","+DebugNumber(p._yscale)+
            ";rotation="+DebugNumber(p._rotation)+";alpha="+DebugNumber(p._alpha)+
            ";visible="+p._visible+";frame="+p._currentframe+"]";
    return result;
}
function DebugRegionText(a:Object):String
{
    var result:String = a.id+"{exists="+(a.clip != undefined)+";state="+a.reason+
        ";sourceSpace="+a.space+";local="+DebugRectText(a.localRect)+";rootAABB="+DebugRectText(a.bounds)+";corners=";
    for (var i:Number = 0; i < a.points.length; i++) result += DebugNumber(a.points[i].x)+","+DebugNumber(a.points[i].y)+"/";
    return result+";chain="+DebugParents(a.clip)+"}";
}

function DebugField(a_name:String,a_size:Number,a_color:Number):TextField
{
    var parent:MovieClip = debugOverlay.Labels;
    var field:TextField = parent[a_name];
    if (field == undefined)
    {
        parent.createTextField(a_name,parent.getNextHighestDepth(),0,0,320,24);
        field = parent[a_name];
        field.embedFonts = true; field.selectable = false; field.wordWrap = false;
        field.background = false; field.border = false;
        field.filters = [new flash.filters.GlowFilter(0,100,3,3,3,2)];
        var format:TextFormat = new TextFormat();
        format.font = "$EverywhereMediumFont"; format.size = a_size; format.color = a_color;
        field.setNewTextFormat(format);
    }
    return field;
}
function DebugFree(a_rect:Object,a_occupied:Array):Boolean
{
    if (a_rect.xMin < 8 || a_rect.yMin < 8 || a_rect.xMax > Stage.width-8 || a_rect.yMax > Stage.height-8) return false;
    for (var i:Number = 0; i < a_occupied.length; i++)
    {
        var b:Object = a_occupied[i];
        if (a_rect.xMax+4 > b.xMin && a_rect.xMin-4 < b.xMax && a_rect.yMax+4 > b.yMin && a_rect.yMin-4 < b.yMax) return false;
    }
    return true;
}
function DebugSlot(a_x:Number,a_y:Number,a_width:Number,a_height:Number):Object
{
    return {xMin:a_x,yMin:a_y,xMax:a_x+a_width,yMax:a_y+a_height};
}
// Liang-Barsky clips a segment to an axis-aligned logical window. Unlike a
// polygon clip, it returns exactly two endpoints, including reversed segments.
function DebugClipLine(a:Object,b:Object,w:Object):Array
{
    var dx:Number = b.x-a.x; var dy:Number = b.y-a.y;
    var p:Array = [-dx,dx,-dy,dy];
    var q:Array = [a.x-w.xMin,w.xMax-a.x,a.y-w.yMin,w.yMax-a.y];
    var low:Number = 0; var high:Number = 1;
    for (var i:Number = 0; i < 4; i++)
    {
        if (!isFinite(p[i]) || !isFinite(q[i])) return new Array();
        if (Math.abs(p[i]) < 0.0000001)
        {
            if (q[i] < 0) return new Array();
        }
        else
        {
            var ratio:Number = q[i]/p[i];
            if (p[i] < 0) low = Math.max(low,ratio);
            else high = Math.min(high,ratio);
            if (low > high) return new Array();
        }
    }
    return [{x:a.x+dx*low,y:a.y+dy*low},{x:a.x+dx*high,y:a.y+dy*high}];
}

function DebugDraw(a_region:Object):Void
{
    var points:Array = a_region.points;
    if (a_region.reason != "visible" || a_region.bounds == undefined || points.length < 2) return;
    var lines:MovieClip = debugOverlay.Lines;
    lines.lineStyle(1,a_region.color,100);
    // Stage clipping is only a logical guard; does not claim a measured UV window.
    var window:Object = {xMin:1,yMin:1,xMax:Stage.width-1,yMax:Stage.height-1};
    // Q/F/V describe the list, not the whole shared HUD texture. Keep
    // full geometry in logs, but never draw its out-of-band segments.
    if (a_region.id == "Q" || a_region.id == "F" || a_region.id == "V")
    {
        if (debugTextBand == undefined || !isFinite(debugTextBand.top) ||
            !isFinite(debugTextBand.bottom)) return;
        // Inset the 1px stroke so its edge does not straddle the seam.
        window.yMin = Math.max(window.yMin,debugTextBand.top+1);
        window.yMax = Math.min(window.yMax,debugTextBand.bottom-1);
        if (window.yMin >= window.yMax) return;
    }
    // Clip each segment, not the closed polygon (which would invent boundary edges).
    for (var e:Number = 0; e < points.length; e++)
    {
        var a:Object = points[e]; var b:Object = points[(e+1)%points.length];
        var length:Number = Math.sqrt((b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y));
        var count:Number = a_region.dash ? Math.min(256,Math.ceil(length/10)) : 1;
        for (var n:Number = 0; n < count; n++)
        {
            var start:Number = n/count; var end:Number = a_region.dash ? Math.min(1,start+0.55/count) : 1;
            var segment:Array = DebugClipLine({x:a.x+(b.x-a.x)*start,y:a.y+(b.y-a.y)*start},
                {x:a.x+(b.x-a.x)*end,y:a.y+(b.y-a.y)*end},window);
            if (segment.length >= 2)
            {
                lines.moveTo(segment[0].x,segment[0].y);
                lines.lineTo(segment[1].x,segment[1].y);
            }
        }
    }
}

function DebugLabels(a_regions:Array,a_status:String,a_warning:String,a_refresh:Boolean):Void
{
    var occupied:Array = new Array();
    debugSuppressed = "";
    for (var i:Number = 0; i < a_regions.length; i++)
        if (a_regions[i].reason == "visible" && a_regions[i].bounds != undefined && a_regions[i].id != "F" && a_regions[i].id != "V") occupied.push(a_regions[i].bounds);
    var summary:TextField = DebugField("Status",15,0xCCFFFF);
    var warning:TextField = DebugField("Warning",14,0xFF5555);
    if (a_refresh) { summary.text = a_status; warning.text = a_warning; }
    summary._visible = false; warning._visible = false;
    // Cache a slot next to the focused marker border, not a Stage-edge slot.
    // Palm moves the whole surface; never chase the distance fade animation.
    var width:Number = Math.max(summary.textWidth,warning.textWidth)+8;
    var height:Number = Math.max(summary.textHeight,warning.textHeight)+6;
    if (a_refresh && debugSummarySlot == undefined && debugTextBand != undefined)
    {
        var anchor:Object;
        for (var ar:Number = 0; ar < a_regions.length; ar++)
            if (a_regions[ar].id == "M" && a_regions[ar].reason == "visible") anchor = a_regions[ar].bounds;
        if (anchor != undefined)
        {
            var y:Number = Math.max(debugTextBand.top+8,Math.min(anchor.yMin,debugTextBand.bottom-height*2-8));
            var right:Number = anchor.xMax+14;
            var left:Number = anchor.xMin-width-14;
            var candidates:Array = [DebugSlot(right,y,width,height*2),
                DebugSlot(right,debugTextBand.bottom-height*2-8,width,height*2),
                DebugSlot(left,y,width,height*2),DebugSlot(left,debugTextBand.bottom-height*2-8,width,height*2)];
            for (var c:Number = 0; c < candidates.length; c++)
                if (debugSummarySlot == undefined && DebugFree(candidates[c],occupied)) debugSummarySlot = candidates[c];
        }
    }
    var slot:Object = debugSummarySlot;
    if (slot != undefined && width <= 320 && height <= 30)
    {
        slot = DebugSlot(slot.xMin,slot.yMin,width,height*2);
        if (debugTextBand != undefined && slot.yMin >= debugTextBand.top+4 && slot.yMax <= debugTextBand.bottom-4 && DebugFree(slot,occupied))
        {
            summary._x = slot.xMin; summary._y = slot.yMin; summary._width = width; summary._height = height;
            warning._x = slot.xMin; warning._y = slot.yMin+height; warning._width = width; warning._height = height;
            summary._visible = true; warning._visible = warning.text != "";
            occupied.push(slot);
        }
    }
    if (!summary._visible) debugSuppressed += "status:no-safe-fixed-slot;";
    // Order establishes priority: D, H, M, N, Q, F, V. Only short IDs are drawn.
    for (var r:Number = 0; r < a_regions.length; r++)
    {
        var region:Object = a_regions[r];
        var field:TextField = DebugField("ID"+region.id,13,region.color);
        field.text = region.id; field._visible = false;
        var b:Object = region.bounds;
        if (region.reason == "visible" && b != undefined)
        {
            var w:Number = field.textWidth+6; var h:Number = field.textHeight+4;
            // Prefer the right edge, then below/left/above. Never clamp a label
            // away from its own border into a different part of the HUD surface.
            var positions:Array = [DebugSlot(b.xMax+5,b.yMin,w,h),DebugSlot(b.xMin,b.yMax+5,w,h),
                DebugSlot(b.xMin-w-5,b.yMin,w,h),DebugSlot(b.xMin,b.yMin-h-5,w,h)];
            for (var p:Number = 0; p < positions.length && !field._visible; p++)
                if (debugTextBand != undefined && positions[p].yMin >= debugTextBand.top+4 &&
                    positions[p].yMax <= debugTextBand.bottom-4 && DebugFree(positions[p],occupied))
                {
                    field._x = positions[p].xMin; field._y = positions[p].yMin;
                    field._width = w; field._height = h; field._visible = true; occupied.push(positions[p]);
                }
        }
        if (!field._visible) debugSuppressed += region.id+":"+(region.reason == "visible" ? "no-safe-label-slot" : region.reason)+";";
    }
}

function UpdateDebugOverlay():Void
{
    if (!debugEnabled || debugOverlay == undefined) return;
    var now:Number = getTimer();
    var info:MovieClip = FocusedMarkerInfo;
    var list:MovieClip = info.Target.QuestItemList;
    // Text uses the project's previously sampled continuous vertical band, not
    // arbitrary Stage corners. Neither the band nor Stage proves UV coverage.
    debugTextBand = list.GetSharedHudSafeTop != undefined ?
        {top:list.GetSharedHudSafeTop(),bottom:list.GetSharedHudSafeBottom()} : undefined;
    var gate:String = DebugVisibility(this);
    if (gate == "visible") gate = DebugVisibility(DirectionRect);
    if (debugCalibration || list.calibrationEnabled) gate = "calibration";
    debugOverlay._visible = gate == "visible";
    debugOverlay.Lines.clear();
    var regions:Array = [DebugRegion("D",info.Distance.TextFieldInstance,0x00DDFF,false),
        DebugRegion("H",info.Distance.HeightIndicatorInstance,0xFF9900,false),
        DebugRegion("M",info.Movie,0xFFFFFF,false),DebugRegion("N",info.Target.TextFieldInstance,0x66FF88,false)];
    var observation:Object;
    if (list.GetDebugObservation != undefined) observation = list.GetDebugObservation();
    if (observation != undefined && observation.full != undefined)
    {
        regions.push(DebugRegion("Q",list,0xCC66FF,false,observation.shown,list));
        regions.push(DebugRegion("F",list,0xCC66FF,true,observation.full,list));
        regions.push(DebugRegion("V",list,0xFFDD44,true,observation.viewport,observation.space));
        var q:Object = regions[4];
        q.points = DebugClip(q.points,regions[6].points); q.bounds = DebugBounds(q.points);
        if (q.bounds == undefined) q.reason = "outside-logical-viewport";
        if (!observation.shownVisible) { q.reason = "no-visible-sections"; q.points = new Array(); q.bounds = undefined; q.localRect = undefined; }
    }
    else
    {
        var emptyReason:String = list == undefined ? "missing" : (observation != undefined ? "empty-list" : "provider-unavailable");
        var emptyQ:Object = DebugRegion("Q",undefined,0xCC66FF,false);
        var emptyF:Object = DebugRegion("F",undefined,0xCC66FF,true);
        emptyQ.clip = list; emptyQ.reason = emptyReason;
        emptyF.clip = list; emptyF.reason = emptyReason;
        regions.push(emptyQ); regions.push(emptyF);
        if (observation != undefined)
            regions.push(DebugRegion("V",list,0xFFDD44,true,observation.viewport,observation.space));
        else
        {
            var emptyV:Object = DebugRegion("V",undefined,0xFFDD44,true);
            emptyV.clip = list; emptyV.reason = emptyReason; regions.push(emptyV);
        }
    }
    var overlap:Number;
    if (regions[0].reason == "visible" && regions[2].reason == "visible") overlap = DebugOverlap(regions[0].bounds,regions[2].bounds);
    var phase:String = DebugPhase();
    var eventKey:String = String(questListGate)+"|"+gate+"|"+phase+"|"+info.Index+"|"+info.DistanceScale+"|"+info.NameScale+"|"+(overlap > 0);
    for (var i:Number = 0; i < regions.length; i++) eventKey += "|"+regions[i].reason;
    if (observation != undefined) eventKey += "|"+observation.key;
    var transition:Boolean = eventKey != debugEventKey || debugForce != "";
    var refresh:Boolean = transition || now-debugLastText >= 200 || now < debugLastText;
    if (gate == "visible")
    {
        for (var d:Number = 0; d < regions.length; d++) DebugDraw(regions[d]);
        DebugLabels(regions,"Distance "+DebugNumber(info.DistanceScale)+"% | "+DebugPhaseText(phase),
            "QL: "+(questListGate != undefined ? questListGate : "unknown")+
                (overlap > 0 ? " | Overlap "+DebugNumber(overlap) : ""),refresh);
    }
    else debugSuppressed = "all:"+gate;
    if (refresh) debugLastText = now;
    if (transition || now-debugLastSample >= 200 || now < debugLastSample)
    {
        var snapshot:String = "listAnimation="+(observation != undefined ? observation.animation : "n/a")+";questListGate="+questListGate+";gate="+gate+";phase="+phase+";frame="+info._currentframe+"/"+info._totalframes+
            ";configuredScale="+DebugNumber(info.DistanceScale)+","+DebugNumber(info.NameScale)+
            ";distanceMarkerVerticalGap="+DebugNumber(regions[0].bounds != undefined && regions[2].bounds != undefined ? regions[2].bounds.yMin-regions[0].bounds.yMax : undefined)+
            ";distanceMarkerAABBOverlap="+DebugNumber(overlap)+";labelSuppression="+debugSuppressed;
        for (var s:Number = 0; s < regions.length; s++) snapshot += "\n"+DebugRegionText(regions[s]);
        for (var pa:Number = 0; pa < 5; pa++)
            for (var pb:Number = pa+1; pb < 5; pb++)
            {
                var ba:Object = regions[pa].bounds; var bb:Object = regions[pb].bounds;
                if (ba != undefined && bb != undefined)
                    snapshot += "\npair="+regions[pa].id+regions[pb].id+";AABBOverlap="+DebugNumber(DebugOverlap(ba,bb))+
                        ";signedGapXY="+DebugNumber(Math.max(ba.xMin,bb.xMin)-Math.min(ba.xMax,bb.xMax))+","+
                        DebugNumber(Math.max(ba.yMin,bb.yMin)-Math.min(ba.yMax,bb.yMax));
            }
        if (snapshot != debugSampleKey || transition)
        {
            var detail:String = observation != undefined ? observation.details : "list=n/a";
            if (transition && list.GetDebugDetails != undefined) detail += list.GetDebugDetails(this);
            var message:String = "schema=HUDDebug/1;timeMs="+now+";event="+(transition ? (debugForce != "" ? debugForce : "transition") : "sample")+
                ";coordinates=SWF-root;UV=unmeasured;overlap=AABB-not-pixel-occlusion;stationaryReference="+DebugReference(regions[0])+";filters=excluded\n"+snapshot+"\n"+detail;
            // Bounded queue; transitions are captured immediately, native drains
            // on the UI update hook. No file I/O or per-frame stable-state spam.
            if (message.length > 32768) message = message.substr(0,32768)+"\n[snapshot detail truncated at 32 Ki characters]";
            if (debugQueue.length >= 12) { debugQueue.shift(); debugDropped++; }
            debugQueue.push(message);
            debugSampleKey = snapshot;
        }
        debugLastSample = now;
    }
    debugEventKey = eventKey; debugForce = "";
}

function DrainDebugLog():String
{
    var result:String = debugQueue.join("\n---\n");
    if (debugDropped > 0) result = "droppedSnapshots="+debugDropped+"\n"+result;
    debugQueue = new Array(); debugDropped = 0;
    return result;
}
