

// Passenger fitting uses Target-local coordinates, ordinary HUD fitting uses
// root coordinates. A limit is never compared with a different space.
function GetLayoutSpace():MovieClip
{
    return compassPassengerMode && !dedicatedPanel ? _parent : _root;
}

// Candidate continuous band from manual root-space calibration at 1024x1024.
// Not a full-width or all-pose UV guarantee. Calibration/dedicated paths bypass it.
function GetSharedHudSafeTop():Number
{
    return Stage.height * 760 / 1024;
}

function GetSharedHudSafeBottom():Number
{
    return Stage.height * 960 / 1024;
}

function GetPassengerBounds():Object
{
    var config:Object = GetCompassPassengerConfig();
    var width:Number = Math.max(1,config.width);
    var height:Number = Math.max(1,config.height);
    var x:Number = config.offsetX-width*0.5;
    var y:Number = config.offsetY;
    if (anchorText != undefined)
    {
        x += anchorText._x+anchorText._width*0.5+offsetX;
        y += anchorText._y+anchorText._height+anchorGap+offsetY;
    }
    // This is a logical Stage constraint, not a measured VR mesh UV region.
    var corners:Array = [{x:12,y:GetSharedHudSafeTop()},{x:Stage.width-12,y:GetSharedHudSafeTop()},
        {x:Stage.width-12,y:GetSharedHudSafeBottom()},{x:12,y:GetSharedHudSafeBottom()}];
    var stage:Object = {xMin:Number.POSITIVE_INFINITY,yMin:Number.POSITIVE_INFINITY,
        xMax:Number.NEGATIVE_INFINITY,yMax:Number.NEGATIVE_INFINITY};
    for (var i:Number = 0; i < corners.length; i++)
    {
        _root.localToGlobal(corners[i]);
        _parent.globalToLocal(corners[i]);
        stage.xMin = Math.min(stage.xMin,corners[i].x);
        stage.yMin = Math.min(stage.yMin,corners[i].y);
        stage.xMax = Math.max(stage.xMax,corners[i].x);
        stage.yMax = Math.max(stage.yMax,corners[i].y);
    }
    width = Math.min(width,Math.max(1,stage.xMax-stage.xMin));
    height = Math.min(height,Math.max(1,stage.yMax-stage.yMin));
    x = Math.max(stage.xMin,Math.min(stage.xMax-width,x));
    // Inverse AABBs alone are not safe under rotation. Intersect the allowed
    // local Y interval at BOTH local X edges with every root rectangle edge.
    var origin:Object = {x:0,y:0};
    var bx:Object = {x:1,y:0};
    var by:Object = {x:0,y:1};
    _parent.localToGlobal(origin);_root.globalToLocal(origin);
    _parent.localToGlobal(bx);_root.globalToLocal(bx);
    _parent.localToGlobal(by);_root.globalToLocal(by);
    var lower:Number = stage.yMin;
    var upper:Number = stage.yMax;
    var names:Array = ["x","y"];
    var minimum:Array = [12,GetSharedHudSafeTop()];
    var maximum:Array = [Stage.width-12,GetSharedHudSafeBottom()];
    for (var edge:Number = 0; edge < 2; edge++)
    {
        var localX:Number = x+edge*width;
        for (var axis:Number = 0; axis < 2; axis++)
        {
            var key:String = names[axis];
            var base:Number = origin[key]+localX*(bx[key]-origin[key]);
            var slope:Number = by[key]-origin[key];
            if (Math.abs(slope) < 0.000001)
            {
                if (base < minimum[axis]-0.001 || base > maximum[axis]+0.001)
                    upper = lower;
            }
            else
            {
                var first:Number = (minimum[axis]-base)/slope;
                var last:Number = (maximum[axis]-base)/slope;
                lower = Math.max(lower,Math.min(first,last));
                upper = Math.min(upper,Math.max(first,last));
            }
        }
    }
    // No usable intersection: return an empty window rather than leak fragments.
    if (upper <= lower) return {xMin:x,yMin:lower,xMax:x+width,yMax:lower};
    height = Math.min(height,upper-lower);
    // Shift only inside the sampled band, never across its upper seam.
    y = Math.max(lower,Math.min(upper-height,y));
    return {xMin:x,yMin:y,xMax:x+width,yMax:y+height};
}

function GetViewportBounds():Object
{
    if (compassPassengerMode && !dedicatedPanel) return GetPassengerBounds();
    return {xMin:12,yMin:12,xMax:Stage.width-12,yMax:Stage.height};
}

function GetFullBoundsInSpace(a_space:MovieClip):Object
{
    if (entries.length == 0) return {xMin:0,yMin:0,xMax:0,yMax:0};
    var bounds:Object = entries[0].GetContentBounds(a_space);
    for (var i:Number = 1; i < entries.length; i++)
    {
        var next:Object = entries[i].GetContentBounds(a_space);
        bounds.xMin = Math.min(bounds.xMin,next.xMin);
        bounds.yMin = Math.min(bounds.yMin,next.yMin);
        bounds.xMax = Math.max(bounds.xMax,next.xMax);
        bounds.yMax = Math.max(bounds.yMax,next.yMax);
    }
    for (var k:Number = 0; k < entries.length; k++)
        bounds.yMax = Math.max(bounds.yMax,entries[k].GetRenderedBottomInSpace(a_space));
    return bounds;
}

function GetFullBoundsInRoot():Object
{
    return GetFullBoundsInSpace(_root);
}

// Record the geometry after fitting. A changed animation or font measurement
// invalidates the cache even when data and requested settings are unchanged.
function GetFitGeometry():String
{
    var bounds:Object = GetFullBoundsInSpace(GetLayoutSpace());
    var state:String = Math.round(bounds.xMin * 10) + "," + Math.round(bounds.yMin * 10) + "," +
        Math.round(bounds.xMax * 10) + "," + Math.round(bounds.yMax * 10);
    for (var i:Number = 0; i < entries.length; i++)
        state += ";" + entries[i]._currentframe + "," + entries[i].DetailBody.layoutWidth + "," + entries[i].DetailBody.layoutHeight;
    return state;
}

// The expensive width/scale search is cached. Geometry is sampled in root space.
function LayoutCandidate(a_scale:Number, a_width:Number):Object
{
    var y:Number = 0;
    for (var i:Number = 0; i < entries.length; i++)
    {
        var item:QuestItem = entries[i];
        item.ReflowWidth(a_width);
        item._xscale = item._yscale = SCALE * a_scale / 100;
        item._y = 0;
        var rect:Object = item.GetContentBounds(this);
        item._y = y - rect.yMin;
        y += rect.yMax - rect.yMin + 5;
    }
    UpdateAnchor();
    return GetFullBoundsInSpace(GetLayoutSpace());
}

// The layout solver uses the actual viewport boundary. Do not subtract a
// conservative VR guard band here: DetailBox height is already derived from
// its children and should only overflow when it reaches the real viewport.
function GetViewportBottom():Number
{
    return GetViewportBounds().yMax;
}

function GetViewportWidth():Number
{
    var b:Object = GetViewportBounds();
    return b.xMax-b.xMin;
}

function FitsHorizontal(a_bounds:Object):Boolean
{
    if (compassPassengerMode && !dedicatedPanel)
    {
        var viewport:Object = GetViewportBounds();
        return a_bounds.xMin-4 >= viewport.xMin && a_bounds.xMax+4 <= viewport.xMax;
    }
    return a_bounds.xMin-4 >= 20 && a_bounds.xMax+4 <= Stage.width-20 &&
        a_bounds.xMax-a_bounds.xMin+8 <= Stage.width*0.8;
}

function FitsViewport(a_bounds:Object):Boolean
{
    if (compassPassengerMode && !dedicatedPanel)
    {
        var viewport:Object = GetViewportBounds();
        if (!FitsHorizontal(a_bounds) || a_bounds.yMin-4 < viewport.yMin || a_bounds.yMax+4 > viewport.yMax)
            return false;
        var corners:Array = [{x:a_bounds.xMin-4,y:a_bounds.yMin-4},{x:a_bounds.xMax+4,y:a_bounds.yMin-4},
            {x:a_bounds.xMax+4,y:a_bounds.yMax+4},{x:a_bounds.xMin-4,y:a_bounds.yMax+4}];
        for (var i:Number = 0; i < corners.length; i++)
        {
            _parent.localToGlobal(corners[i]);
            _root.globalToLocal(corners[i]);
            if (corners[i].x < 12 || corners[i].x > Stage.width-12 ||
                corners[i].y < GetSharedHudSafeTop()-0.001 || corners[i].y > GetSharedHudSafeBottom()+0.001) return false;
        }
        return true;
    }
    // 20px includes filter gutters and small anchor-animation movement.
    return a_bounds.xMin-4 >= 20 && a_bounds.xMax+4 <= Stage.width - 20 &&
        a_bounds.yMin-4 >= 20 && a_bounds.yMax+4 <= GetViewportBottom() &&
        a_bounds.xMax - a_bounds.xMin + 8 <= Stage.width * 0.8;
}

function FitLayout():Void
{
    if (entries.length == 0 || anchorText == undefined) return;
    UpdateAnchor();
    var viewport:Object = GetViewportBounds();
    var anchor:Object = {x:anchorText._x + anchorText._width * 0.5 + offsetX,
        y:anchorText._y + anchorText._height + anchorGap + offsetY};
    _parent.localToGlobal(anchor);
    _root.globalToLocal(anchor);
    var key:String = Stage.width + "," + Stage.height + "," + TEXT_SCALE + "," + offsetX + "," + offsetY +
        "," + Math.floor(anchor.x) + "," + Math.floor(anchor.y) + "," +
        viewport.xMin + "," + viewport.yMin + "," + viewport.xMax + "," + viewport.yMax + "," + compassPassengerMode;
    // Basis lengths detect parent scaling even if the anchor does not move.
    var p0:Object = {x:0,y:0};
    var p1:Object = {x:100,y:100};
    localToGlobal(p0); localToGlobal(p1);
    key += "," + Math.round(p1.x-p0.x) + "," + Math.round(p1.y-p0.y);
    for (var i:Number = 0; i < entries.length; i++)
        key += ";" + entries[i]._name + ":" + entries[i].dataSignature + ":" + entries[i].ageIndex;
    var geometry:String = GetFitGeometry();
    if (fitKey == key && fitGeometry == geometry)
    {
        // A previously overflowing candidate is reusable only while its
        // actual geometry remains unchanged. Otherwise retry the solver.
        if (fitOverflow || FitsViewport(GetFullBoundsInSpace(GetLayoutSpace()))) return;
    }
    fitKey = key;
    fitRuns++;
    var maximumScale:Number = TEXT_SCALE;
    var minimumScale:Number = Math.min(90,TEXT_SCALE);
    if (compassPassengerMode && !dedicatedPanel)
    {
        maximumScale = Math.min(TEXT_SCALE,compassPassengerConfig.scale);
        minimumScale = Math.min(maximumScale,compassPassengerConfig.minScale);
    }
    effectiveScale = maximumScale;
    effectiveWidth = 1;
    fitOverflow = true;
    var natural:Object = LayoutCandidate(maximumScale,1);
    if (FitsViewport(natural))
    {
        fitOverflow = false;
        fitReason = "natural";
        fitGeometry = GetFitGeometry();
        return;
    }
    // The detail ornament has a fixed width. Widening the text alone would
    // draw beyond its borders, so keep the natural width and shrink the panel.
    if (FitsViewport(LayoutCandidate(minimumScale,effectiveWidth)))
    {
        var lo:Number = minimumScale;
        var hi:Number = maximumScale;
        for (var step:Number = 0; step < 8; step++)
        {
            var mid:Number = (lo+hi)*0.5;
            if (FitsViewport(LayoutCandidate(mid,effectiveWidth))) lo = mid;
            else hi = mid;
        }
        effectiveScale = Math.floor(lo*10)/10;
    }
    else effectiveScale = minimumScale;
    fitOverflow = !FitsViewport(LayoutCandidate(effectiveScale,effectiveWidth));
    fitReason = fitOverflow ? "minimum scale cannot fit" : "auto-shrink";
    fitGeometry = GetFitGeometry();
}

function TextBoundsInRoot(a_field:TextField):Object
{
    return TextBoundsInSpace(a_field,_root);
}

function TextBoundsInSpace(a_field:TextField,a_space:MovieClip):Object
{
    var points:Array = [{x:a_field._x,y:a_field._y},
        {x:a_field._x+a_field._width,y:a_field._y},
        {x:a_field._x,y:a_field._y+a_field._height},
        {x:a_field._x+a_field._width,y:a_field._y+a_field._height}];
    var bounds:Object = {xMin:Number.POSITIVE_INFINITY,yMin:Number.POSITIVE_INFINITY,
        xMax:Number.NEGATIVE_INFINITY,yMax:Number.NEGATIVE_INFINITY};
    for (var i:Number = 0; i < points.length; i++)
    {
        a_field._parent.localToGlobal(points[i]);
        a_space.globalToLocal(points[i]);
        bounds.xMin = Math.min(bounds.xMin,points[i].x);
        bounds.yMin = Math.min(bounds.yMin,points[i].y);
        bounds.xMax = Math.max(bounds.xMax,points[i].x);
        bounds.yMax = Math.max(bounds.yMax,points[i].y);
    }
    return bounds;
}

function UpdateViewportMask():Void
{
    if (viewportMask == undefined)
    {
        viewportMask = _parent.createEmptyMovieClip("QuestListViewportMask", _parent.getNextHighestDepth());
        this.setMask(viewportMask);
    }
    viewportMask.clear();
    if (entries.length == 0) return;
    var space:MovieClip = GetLayoutSpace();
    var viewport:Object = GetViewportBounds();
    // GetFullBoundsInSpace includes the rendered-bottom safety gutter. Use
    // unpadded content bounds here so the mask adds its own gutter only once.
    // Do not mutate a QuestItem's bounds object while accumulating the union.
    var bounds:Object = {xMin:Number.POSITIVE_INFINITY,yMin:Number.POSITIVE_INFINITY,
        xMax:Number.NEGATIVE_INFINITY,yMax:Number.NEGATIVE_INFINITY};
    for (var k:Number = 0; k < entries.length; k++)
    {
        var content:Object = entries[k].GetContentBounds(space);
        bounds.xMin = Math.min(bounds.xMin,content.xMin);
        bounds.yMin = Math.min(bounds.yMin,content.yMin);
        bounds.xMax = Math.max(bounds.xMax,content.xMax);
        bounds.yMax = Math.max(bounds.yMax,content.yMax);
    }
    if (overflowLabel != undefined && overflowLabel._visible)
    {
        var labelBounds:Object = TextBoundsInSpace(overflowLabel,space);
        bounds.xMin = Math.min(bounds.xMin, labelBounds.xMin);
        bounds.xMax = Math.max(bounds.xMax, labelBounds.xMax);
        bounds.yMax = Math.max(bounds.yMax, labelBounds.yMax);
    }
    var left:Number = Math.max(viewport.xMin,bounds.xMin-4);
    var top:Number = Math.max(viewport.yMin,bounds.yMin-4);
    var right:Number = Math.min(viewport.xMax,bounds.xMax+4);
    var bottom:Number = Math.min(viewport.yMax,bounds.yMax+4);
    if (left >= right || top >= bottom) return;
    var corners:Array = [{x:left,y:top},{x:right,y:top},
        {x:right,y:bottom},{x:left,y:bottom}];
    viewportMask.beginFill(0xFFFFFF,100);
    for (var i:Number = 0; i < corners.length; i++)
    {
        space.localToGlobal(corners[i]);
        if (compassPassengerMode && !dedicatedPanel)
        {
            _root.globalToLocal(corners[i]);
            corners[i].y = Math.max(GetSharedHudSafeTop(),Math.min(corners[i].y,GetSharedHudSafeBottom()));
            _root.localToGlobal(corners[i]);
        }
        viewportMask.globalToLocal(corners[i]);
        if (i == 0) viewportMask.moveTo(corners[i].x,corners[i].y);
        else viewportMask.lineTo(corners[i].x,corners[i].y);
    }
    viewportMask.lineTo(corners[0].x,corners[0].y);
    viewportMask.endFill();
}
