

	// Step 2 fallback artwork keeps layout testable before the supplied assets
	// are imported in the next step. Linkage assets take precedence when present.
	private function DrawDividerFallback(a_parent:MovieClip, a_width:Number, a_height:Number):MovieClip
	{
		var art:MovieClip = a_parent.createEmptyMovieClip("Art", a_parent.getNextHighestDepth());
		var centerY:Number = Math.max(1, a_height * 0.5);
		var centerX:Number = a_width * 0.5;
		var gapHalf:Number = Math.max(34, a_width * 0.15);
		art.lineStyle(1.5, 0xBBBBBB, 100);
		art.moveTo(0, centerY);
		art.lineTo(centerX - gapHalf, centerY);
		art.moveTo(centerX + gapHalf, centerY);
		art.lineTo(a_width, centerY);
		return art;
	}

	// Reuse the supplied art, masking each side separately so the center gap
	// follows the translated label without stretching the entire ornament.
	private function DrawDividerWing(a_parent:MovieClip, a_name:String, a_width:Number, a_height:Number, a_right:Boolean):MovieClip
	{
		var wing:MovieClip = a_parent.createEmptyMovieClip(a_name, a_parent.getNextHighestDepth());
		wing.layoutHeight = a_height;
		var art:MovieClip = wing.attachMovie("QuestObjectivesDivider", "Art", wing.getNextHighestDepth());
		if (art == undefined)
		{
			wing.lineStyle(1.5, 0xBBBBBB, 100);
			wing.moveTo(0, a_height * 0.5);
			wing.lineTo(a_width, a_height * 0.5);
			return wing;
		}
		wing.rightSide = a_right;
		var sourceWidth:Number = a_right ? 735 : 734;
		art._xscale = 100 * a_width / sourceWidth;
		art._yscale = 100 * a_height / 63;
		art._x = a_right ? -1313 * a_width / sourceWidth : 0;
		var maskClip:MovieClip = wing.createEmptyMovieClip("Mask", wing.getNextHighestDepth());
		maskClip.beginFill(0xFFFFFF, 100);
		maskClip.moveTo(0, 0);
		maskClip.lineTo(a_width, 0);
		maskClip.lineTo(a_width, a_height);
		maskClip.lineTo(0, a_height);
		maskClip.lineTo(0, 0);
		maskClip.endFill();
		art.setMask(maskClip);
		return wing;
	}

	private function ResizeDividerWing(a_wing:MovieClip, a_width:Number):Void
	{
		// Never resize the wrapper: its bounds can include the hidden center of the source.
		if (a_wing.Art == undefined)
		{
			a_wing.clear();
			a_wing.lineStyle(1.5, 0xBBBBBB, 100);
			a_wing.moveTo(0, a_wing.layoutHeight * 0.5);
			a_wing.lineTo(a_width, a_wing.layoutHeight * 0.5);
			return;
		}
		var sourceWidth:Number = a_wing.rightSide ? 735 : 734;
		a_wing.Art._xscale = 100 * a_width / sourceWidth;
		a_wing.Art._x = a_wing.rightSide ? -1313 * a_width / sourceWidth : 0;
		a_wing.Mask._width = a_width;
	}

	private function CompareObjectiveState(a:Object, b:Object):Number
	{
		var rankA:Number = a.failed ? 2 : (a.completed ? 1 : 0);
		var rankB:Number = b.failed ? 2 : (b.completed ? 1 : 0);
		if (rankA != rankB)
		{
			return rankA - rankB;
		}
		// Native snapshots are in objective-index order, not completion-time order.
		// Reverse completed history; keep active and failed groups stable.
		return rankA == 1 ? b.order - a.order : a.order - b.order;
	}

	private function DrawObjectiveIconFallback(a_parent:MovieClip, a_completed:Boolean):MovieClip
	{
		var icon:MovieClip = a_parent.createEmptyMovieClip("StateIcon", a_parent.getNextHighestDepth());
		icon.lineStyle(1.5, 0xFFFFFF, 100);
		if (a_completed)
		{
			icon.beginFill(0xFFFFFF, 100);
		}
		icon.moveTo(6, 0);
		icon.lineTo(12, 9);
		icon.lineTo(6, 18);
		icon.lineTo(0, 9);
		icon.lineTo(6, 0);
		if (a_completed)
		{
			icon.endFill();
		}
		return icon;
	}

	private function ResizeObjectivesHeader():Void
	{
		var a_width:Number = this.DetailBody.layoutWidth;
		var header:MovieClip = this.ObjectivesHeader;
		var label:TextField = header.Label;
		var format:TextFormat = label.getTextFormat();
		// Re-measure from the original size, never from a previously shrunk label.
		format.size = this.objectivesLabelSize;
		label.setTextFormat(format);
		var gap:Number = 6;
		var minWing:Number = Math.min(24, a_width * 0.1);
		var maxLabelWidth:Number = Math.max(1, a_width - 2 * (gap + minWing));
		var measuredWidth:Number = label.textWidth + 6;
		if (measuredWidth > maxLabelWidth)
		{
			format.size = Number(format.size) * maxLabelWidth / measuredWidth;
			label.setTextFormat(format);
			measuredWidth = label.textWidth + 6;
		}
		label._width = Math.min(maxLabelWidth, Math.ceil(measuredWidth));
		label._x = (a_width - label._width) * 0.5;
		this.MeasureTextHeight(label, 4);
		var wing:Number = Math.max(0, label._x - gap);
		this.ResizeDividerWing(header.Art.Left, wing);
		this.ResizeDividerWing(header.Art.Right, wing);
		header.Art.Right._x = a_width - wing;
		header.contentHeight = Math.max(20, Math.max(16, label._height));
		header.Art._y = (header.contentHeight - 16) * 0.5;
		label._y = (header.contentHeight - label._height) * 0.5;
	}
