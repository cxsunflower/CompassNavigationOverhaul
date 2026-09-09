

	// The title text field covers only the ornament's center gap. Its width,
	// and especially the widened panel width, must not define the detail area.
	// Measure the actual imported ornament after selecting the quest type.
	private function GetDetailContentBounds():Object
	{
		var bracket:Object = this.TitleBracket.getBounds(this.Title);
		var end:Object = this.TitleEndPiece.getBounds(this.Title);
		var left:Number = Math.min(bracket.xMin, end.xMin);
		var right:Number = Math.max(bracket.xMax, end.xMax);
		if (!isFinite(left) || !isFinite(right) || right - left < 48)
		{
			left = this.TitleTextField._x;
			right = left + this.TitleTextField._width;
		}
		// Reserve room for the original ornament tips, text gutters and Glow.
		var inset:Number = Math.min(12, Math.max(0, (right - left - 32) * 0.5));
		return {xMin:left + inset, xMax:right - inset, outerLeft:left, outerRight:right};
	}

	// The Box owns its logical width and height; MovieClip._width is a rendered
	// bound and must never be used as a layout property or assigned to resize it.
	// This mask is only a final guard for unbreakable words and filter pixels.
	private function UpdateDetailMask():Void
	{
		if (this.naturalLayout == undefined) return;
		var left:Number = this.DetailBody._x - 4;
		var right:Number = left + this.DetailBody.layoutWidth + 8;
		var top:Number = this.DetailBody._y - 4;
		var bottom:Number = top + this.DetailBody.layoutHeight + 8;
		var mask:MovieClip = this.DetailContentMask;
		mask.clear();
		mask.beginFill(0xFFFFFF, 100);
		mask.moveTo(left, top);
		mask.lineTo(right, top);
		mask.lineTo(right, bottom);
		mask.lineTo(left, bottom);
		mask.lineTo(left, top);
		mask.endFill();
	}

	// One layout pass owns the Header and every generated child's position.
	// The outer Box keeps the original animation and full ornament width; the
	// Body owns the inset text width. Neither uses rendered MovieClip dimensions.
	private function LayoutDetailBox():Void
	{
		var box:MovieClip = this.DetailBox;
		var body:MovieClip = this.DetailBody;
		var width:Number = body.layoutWidth;
		// Preserve the original Header's local artwork and its position in the
		// wrapper. Only the Body moves when its natural inset changes.
		body._y = this.naturalLayout.bodyTop;
		var y:Number = 0;
		this.DescriptionTextField._x = 0;
		this.DescriptionTextField._y = 0;
		this.DescriptionTextField._width = width;
		this.MeasureTextHeight(this.DescriptionTextField, 4);
		this.DescriptionTextField._visible = this.descriptionVisible;
		if (this.descriptionVisible) y = this.DescriptionTextField._height;
		if (this.ObjectivesHeader != undefined)
		{
			if (this.descriptionVisible) y += 6;
			var header:MovieClip = this.ObjectivesHeader;
			header._x = 0;
			header._y = y;
			this.ResizeObjectivesHeader();
			y += header.contentHeight + 5;
			for (var i:Number = 0; i < this.ObjectiveItemList.length; i++)
			{
				var row:MovieClip = this.ObjectiveItemList[i];
				row._x = 0;
				row._y = y;
				row.TextFieldInstance._width = Math.max(1, width - 26);
				this.LayoutObjectiveRow(row);
				y += row.contentHeight + 5;
			}
			y -= 5;
		}
		body.layoutHeight = Math.max(0, y);
		box.layoutHeight = Math.max(this.naturalLayout.bottom, body._y + body.layoutHeight) - box.layoutTop;
		this.contentRect = {xMin:box.layoutLeft, yMin:box.layoutTop,
			xMax:box.layoutLeft + box.layoutWidth, yMax:box.layoutTop + box.layoutHeight};
		this.UpdateDetailMask();
	}

	// Compatibility with the list's width API. Never widen beyond the ornament.
	// A narrower request changes only the Box's logical width, never its scale.
	public function ReflowWidth(a_factor:Number):Void
	{
		if (this.naturalLayout == undefined || isNaN(a_factor) || !isFinite(a_factor)) return;
		var minimumFactor:Number = Math.min(1, 48 / this.naturalLayout.width);
		a_factor = Math.max(minimumFactor, Math.min(1, a_factor));
		var width:Number = this.naturalLayout.width * a_factor;
		if (this.DetailBody.layoutWidth == width) return;
		this.DetailBody.layoutWidth = width;
		this.DetailBody._x = this.naturalLayout.left + (this.naturalLayout.width - width) * 0.5;
		this.LayoutDetailBox();
	}
