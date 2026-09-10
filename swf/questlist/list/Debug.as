// Read-only geometry provider for Compass' single observer. No drawing or updates.
function GetDebugObservation():Object
{
    var full:Object = entries.length > 0 ? GetFullBoundsInSpace(this) : undefined;
    var shown:Object;
    var visibleRects:Array = new Array();
    var total:Number = 0; var visible:Number = 0;
    var animation:String = "";
    for (var i:Number = 0; i < entries.length; i++)
    {
        var item:QuestItem = entries[i];
        if (item._visible != false && item._alpha > 0 && item.DetailBox._visible != false && item.DetailBox._alpha > 0)
        {
            var rect:Object = item.GetContentBounds(this);
            rect.yMax = item.GetVisibleContentBottom(this);
            visibleRects.push(rect);
        }
        if (i < 8) animation += ";item"+i+"="+item._currentframe+","+item._alpha+
            ",box="+item.DetailBox._currentframe+","+item.DetailBox._alpha+","+item.DetailBox._x+","+item.DetailBox._y;
        total += item.ObjectiveItemList.length;
        for (var j:Number = 0; j < item.ObjectiveItemList.length; j++)
            if (item._visible != false && item._alpha > 0 && item.DetailBox._visible != false && item.DetailBox._alpha > 0 && item.ObjectiveItemList[j]._visible) visible++;
    }
    if (overflowLabel != undefined && overflowLabel._visible && overflowLabel._alpha > 0)
        visibleRects.push({xMin:overflowLabel._x,yMin:overflowLabel._y,
            xMax:overflowLabel._x+overflowLabel._width,yMax:overflowLabel._y+overflowLabel._height});
    for (var r:Number = 0; r < visibleRects.length; r++)
    {
        var next:Object = visibleRects[r];
        if (shown == undefined) shown = {xMin:next.xMin,yMin:next.yMin,xMax:next.xMax,yMax:next.yMax};
        else
        {
            shown.xMin = Math.min(shown.xMin,next.xMin); shown.yMin = Math.min(shown.yMin,next.yMin);
            shown.xMax = Math.max(shown.xMax,next.xMax); shown.yMax = Math.max(shown.yMax,next.yMax);
        }
    }
    return {full:full,shown:shown,shownVisible:shown != undefined,animation:animation,viewport:GetViewportBounds(),space:GetLayoutSpace(),
        key:entries.length+","+visible+","+total+","+fitRuns+","+omissionReason,
        details:"listSpace="+this+";listBounds=conservative-logical-union;configuredScale="+TEXT_SCALE+
            ";actualScale="+effectiveScale+";width="+effectiveWidth+";fit="+fitReason+
            ";omission="+omissionReason+";visibleRows="+visible+";totalRows="+total+
            ";contentLimit="+omissionLimit+";viewport=logical-not-UV"};
}
function GetDebugDetails(a_observer:MovieClip):String
{
    var result:String = "";
    for (var i:Number = 0; i < Math.min(8,entries.length); i++)
    {
        var item:QuestItem = entries[i];
        result += "\nitem="+i+";path="+item+";omittedRowDetails="+Math.max(0,item.ObjectiveItemList.length-24);
        if (a_observer != undefined)
        {
            var regions:Array = item.GetDiagnosticRegions();
            for (var j:Number = 0; j < regions.length; j++)
            {
                var source:Object = regions[j];
                var region:Object = a_observer.DebugRegion(source.name,source.clip,0,false,source.rect,source.clip);
                if (!source.visible) region.reason = "hidden-section";
                result += "\n"+a_observer.DebugRegionText(region);
            }
        }
    }
    return result+";omittedItemDetails="+Math.max(0,entries.length-8);
}

