

	public function GetContentBounds(a_space:MovieClip):Object
	{
		// Stable bounds do not depend on fades or the rows currently hidden by
		// the height limit. Transform all four corners for nested transforms.
		return this.GetDetailBoxBounds(a_space);
	}

	private function TransformBounds(a_clip:MovieClip, a_rect:Object, a_space:MovieClip):Object
	{
		var rect:Object = a_rect;
		var corners:Array = [
			{x:rect.xMin, y:rect.yMin}, {x:rect.xMax, y:rect.yMin},
			{x:rect.xMin, y:rect.yMax}, {x:rect.xMax, y:rect.yMax}
		];
		var bounds:Object = {xMin:Number.POSITIVE_INFINITY, yMin:Number.POSITIVE_INFINITY,
			xMax:Number.NEGATIVE_INFINITY, yMax:Number.NEGATIVE_INFINITY};
		for (var i:Number = 0; i < corners.length; i++)
		{
			var point:Object = corners[i];
			a_clip.localToGlobal(point);
			if (a_space != undefined) a_space.globalToLocal(point);
			bounds.xMin = Math.min(bounds.xMin, point.x);
			bounds.yMin = Math.min(bounds.yMin, point.y);
			bounds.xMax = Math.max(bounds.xMax, point.x);
			bounds.yMax = Math.max(bounds.yMax, point.y);
		}
		return bounds;
	}

	private function GetDetailBoxBounds(a_space:MovieClip):Object
	{
		return this.TransformBounds(this.DetailBox, this.contentRect, a_space);
	}

	// AS2 TextField is not MovieClip: it has no getBounds/localToGlobal API.
	private function DisplayBounds(a_clip:Object, a_space:MovieClip):Object
	{
		var field:Boolean = typeof(a_clip.text) == "string";
		var transform:MovieClip = field ? a_clip._parent : a_clip;
		var rect:Object = field ? {xMin:a_clip._x,yMin:a_clip._y,
			xMax:a_clip._x+a_clip._width,yMax:a_clip._y+a_clip._height} : a_clip.getBounds(a_clip);
		return this.TransformBounds(transform, rect, a_space);
	}

	private function ClipBottom(a_clip:Object):Number
	{
		return this.DisplayBounds(a_clip,undefined).yMax;
	}

	public function GetRowClipState(a_space:MovieClip):String
	{
		var state:String = "";
		for (var i:Number = 0; i < this.ObjectiveItemList.length; i++)
		{
			var row:MovieClip = this.ObjectiveItemList[i];
			var icon:Object = row.StateIcon.getBounds(a_space);
			var text:Object = this.DisplayBounds(row.TextFieldInstance,a_space);
			state += " row" + i + "[visible=" + row._visible + ",h=" + row.contentHeight +
				",icon=" + icon.xMin + "," + icon.yMin + "," + icon.xMax + "," + icon.yMax +
				",text=" + text.xMin + "," + text.yMin + "," + text.xMax + "," + text.yMax + "]";
		}
		return state;
	}

	public function GetRenderedBottom():Number
	{
		return this.GetRenderedBottomInSpace(undefined);
	}

	// All height decisions can use the same coordinate space as the safe-area
	// solver. The original no-argument-space API still returns global pixels.
	public function GetRenderedBottomInSpace(a_space:MovieClip):Number
	{
		return this.GetDetailBoxBounds(a_space).yMax + 4;
	}

	public function GetHeaderBottomInSpace(a_space:MovieClip):Number
	{
		var headerRect:Object = {xMin:this.DetailBox.layoutLeft, yMin:this.DetailBox.layoutTop,
			xMax:this.DetailBox.layoutLeft + this.DetailBox.layoutWidth, yMax:this.naturalLayout.bottom};
		return this.TransformBounds(this.DetailBox, headerRect, a_space).yMax + 4;
	}

	public function HasOmittedContent():Boolean
	{
		if (this.descriptionVisible && !this.DescriptionTextField._visible) return true;
		for (var i:Number = 0; i < this.ObjectiveItemList.length; i++)
		{
			if (!this.ObjectiveItemList[i]._visible) return true;
		}
		return false;
	}

	// The omission label belongs immediately after the last complete visible
	// section, not at the bottom of the entire viewport. Original Header art is
	// always part of the visible extent, even when every generated row is hidden.
	public function GetVisibleContentBottom(a_space:MovieClip):Number
	{
		var bottom:Number = this.GetHeaderBottomInSpace(a_space) - 4;
		if (this.DescriptionTextField._visible)
		{
			bottom = Math.max(bottom, this.DisplayBounds(this.DescriptionTextField, a_space).yMax);
		}
		if (this.ObjectivesHeader != undefined && this.ObjectivesHeader._visible)
		{
			bottom = Math.max(bottom, this.TransformBounds(this.ObjectivesHeader, {xMin:0, yMin:0,
				xMax:this.DetailBody.layoutWidth, yMax:this.ObjectivesHeader.contentHeight}, a_space).yMax);
		}
		for (var i:Number = 0; i < this.ObjectiveItemList.length; i++)
		{
			var row:MovieClip = this.ObjectiveItemList[i];
			if (row._visible)
			{
				bottom = Math.max(bottom, this.TransformBounds(row, {xMin:0, yMin:0,
					xMax:this.DetailBody.layoutWidth, yMax:row.contentHeight}, a_space).yMax);
			}
		}
		return bottom + 4;
	}

	public function ApplyHeightLimit(a_maxGlobalY:Number, a_space:MovieClip):Void
	{
		// Hide complete sections rather than clipping halfway through a line.
		// A hidden row never makes a later row visible again.
		this.DescriptionTextField._visible = this.descriptionVisible && this.DisplayBounds(this.DescriptionTextField, a_space).yMax + 4 <= a_maxGlobalY;
		var canShowHeader:Boolean = false;
		if (this.ObjectivesHeader != undefined)
		{
			var headerBottom:Number = this.TransformBounds(this.ObjectivesHeader, {xMin:0, yMin:0,
				xMax:this.DetailBody.layoutWidth, yMax:this.ObjectivesHeader.contentHeight}, a_space).yMax;
			canShowHeader = headerBottom + 4 <= a_maxGlobalY;
		}
		var canShowRows:Boolean = canShowHeader && (!this.descriptionVisible || this.DescriptionTextField._visible);
		var visibleRows:Number = 0;
		for (var i:Number = 0; i < this.ObjectiveItemList.length; i++)
		{
			var row:MovieClip = this.ObjectiveItemList[i];
			var rowBottom:Number = this.TransformBounds(row, {xMin:0, yMin:0,
				xMax:this.DetailBody.layoutWidth, yMax:row.contentHeight}, a_space).yMax;
			row._visible = canShowRows && rowBottom + 4 <= a_maxGlobalY;
			canShowRows = row._visible;
			if (row._visible)
			{
				visibleRows++;
			}
		}
		if (this.ObjectivesHeader != undefined)
		{
			this.ObjectivesHeader._visible = canShowHeader && visibleRows > 0;
		}
	}
