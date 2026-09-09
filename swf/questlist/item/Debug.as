

	// Diagnostic-only geometry. Every rectangle is expressed in its own clip's
	// local coordinates; the caller transforms all four corners to root space.
	// Never use this list, its labels or rendered debug bounds for layout.
	public function GetLayoutDebugRegions():Array
	{
		var regions:Array = new Array();
		if (this.naturalLayout == undefined) return regions;
		var full:Boolean = this._visible != false && this.DetailBox._visible != false;
		var width:Number = this.DetailBody.layoutWidth;
		var headerRect:Object = {xMin:this.DetailBox.layoutLeft, yMin:this.DetailBox.layoutTop,
			xMax:this.DetailBox.layoutLeft + this.DetailBox.layoutWidth, yMax:this.naturalLayout.bottom};
		regions.push({name:"Box", clip:this.DetailBox, rect:this.contentRect, visible:full, color:0xFF3030});
		regions.push({name:"Header", clip:this.DetailBox, rect:headerRect, visible:full, color:0xFF8844});
		regions.push({name:"Body", clip:this.DetailBody, rect:{xMin:0,yMin:0,xMax:width,yMax:this.DetailBody.layoutHeight},
			visible:full, color:0xFF5555});
		var maskRect:Object = {xMin:this.DetailBody._x-4,yMin:this.DetailBody._y-4,
			xMax:this.DetailBody._x+width+4,yMax:this.DetailBody._y+this.DetailBody.layoutHeight+4};
		regions.push({name:"Body mask", clip:this.DetailBox, rect:maskRect, visible:full, color:0x00DDEE});
		regions.push({name:"Bracket", clip:this.Title, rect:this.TitleBracket.getBounds(this.Title),
			visible:full && this.TitleBracket._visible != false, color:0xFF8844});
		regions.push({name:"EndPiece", clip:this.Title, rect:this.TitleEndPiece.getBounds(this.Title),
			visible:full && this.TitleEndPiece._visible != false, color:0xFF8844});
		if (this.TitleTextField._visible)
		{
			regions.push({name:"Title text", clip:this.Title, rect:{xMin:this.TitleTextField._x,yMin:this.TitleTextField._y,
				xMax:this.TitleTextField._x+this.TitleTextField._width,yMax:this.TitleTextField._y+this.TitleTextField._height},
				visible:full, color:0xFF8844});
		}
		if (this.descriptionVisible)
		{
			regions.push({name:"Description", clip:this.DetailBody, rect:{xMin:this.DescriptionTextField._x,yMin:this.DescriptionTextField._y,
				xMax:this.DescriptionTextField._x+this.DescriptionTextField._width,yMax:this.DescriptionTextField._y+this.DescriptionTextField._height},
				visible:full && this.DescriptionTextField._visible, color:0xFF5555});
		}
		if (this.ObjectivesHeader != undefined)
		{
			regions.push({name:"OBJECTIVES", clip:this.ObjectivesHeader, rect:{xMin:0,yMin:0,xMax:width,yMax:this.ObjectivesHeader.contentHeight},
				visible:full && this.ObjectivesHeader._visible, color:0xFF5555});
		}
		// Bound debug work without dropping any actual objectives or changing their state.
		for (var i:Number = 0; i < Math.min(24,this.ObjectiveItemList.length); i++)
		{
			var row:MovieClip = this.ObjectiveItemList[i];
			regions.push({name:"Row" + i, clip:row, rect:{xMin:0,yMin:0,xMax:width,yMax:row.contentHeight},
				visible:full && row._visible, color:0xFF5555});
		}
		return regions;
	}
