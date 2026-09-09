

function GetAnchorState():String
{
    return "parent=" + _parent + "; text=" + anchorText + "; count=" + entries.length +
        "; list=" + _x + "," + _y + "; label=" + anchorText._x + "," + anchorText._y +
        "; labelHeight=" + anchorText._height + "; panelScale=" + TEXT_SCALE + "; offset=" + offsetX + "," + offsetY +
        "; effective=" + effectiveScale + "; widthFactor=" + effectiveWidth + "; overflow=" + fitOverflow + "; fitRuns=" + fitRuns + "; stage=" + Stage.width + "," + Stage.height + "; globalBounds=" + GetGlobalContentState() + GetClipDiagnostics();
}

// Explicit on-demand diagnostic. Refresh one layout frame before sampling so
// a settings reload does not log the stale, pre-reflow scale or row visibility.
// This is never called by the normal per-frame rendering path.
function GetLayoutSnapshot():String
{
    if (entries.length > 0 && anchorText != undefined) Update();
    return GetAnchorState();
}

// Sampled only by the native anchor/settings logs; never emit per-frame logs.
function GetClipDiagnostics():String
{
    var state:String = "; viewportBottom=" + GetViewportBottom() + "; rootScale=" + _root._xscale + "," + _root._yscale +
        "; band=candidate; sharedHudSafeTopRoot=" + GetSharedHudSafeTop() +
        "; sharedHudSafeBottomRoot=" + GetSharedHudSafeBottom() +
        "; layoutSpace=" + (compassPassengerMode && !dedicatedPanel ? "Target" : "root") +
        "; safeLimitLocal=" + lastSafeLimit + "; contentLimitLocal=" + omissionLimit +
        "; visibleBottomLocal=" + lastVisibleBottom + "; fitReason=" + fitReason +
        "; omissionReason=" + omissionReason + "; fitGeometry=" + fitGeometry;
    if (viewportMask != undefined)
    {
        var mask:Object = viewportMask.getBounds(_root);
        state += "; mask=" + mask.xMin + "," + mask.yMin + "," + mask.xMax + "," + mask.yMax;
    }
    for (var i:Number = 0; i < entries.length; i++)
        state += "; item" + i + "[visible=" + entries[i]._visible + ",renderedBottomGlobal=" +
            entries[i].GetRenderedBottom() + ",renderedBottomRoot=" + entries[i].GetRenderedBottomInSpace(_root) +
            ",headerBottomRoot=" + entries[i].GetHeaderBottomInSpace(_root) +
            ",headerHeight=" + entries[i].Title.layoutHeight + ",bodyHeight=" + entries[i].DetailBody.layoutHeight +
            ",bodyWidth=" + entries[i].DetailBody.layoutWidth + ",omitted=" + entries[i].HasOmittedContent() +
            "]" + entries[i].GetRowClipState(_root);
    state += "; omissionVisible=" + (overflowLabel != undefined && overflowLabel._visible) +
        "; layoutDebug=" + layoutDebugEnabled + "; debugState=[" + GetLayoutDebugState() + "]";
    return state;
}

function GetGlobalContentState():String
{
    if (entries.length == 0) return "empty";
    var bounds:Object = GetFullBoundsInRoot();
    return bounds.xMin + "," + bounds.yMin + "," + bounds.xMax + "," + bounds.yMax;
}
