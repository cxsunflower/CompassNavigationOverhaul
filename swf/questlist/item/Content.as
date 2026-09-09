

	public function SetQuestInfo(a_type:Number, a_title:String, a_description:String, a_isInSameLocation:Boolean, a_objectives:Array, a_ageIndex:Number):Void
	{
		// Keep artwork and only the miscellaneous heading.
		this.TitleEndPiece.gotoAndStop(a_type);
		this.TitleEndPiece._visible = true;
		this.TitleBracket._visible = true;
		var showTitle:Boolean = a_type == 6;
		this.TitleTextField.text = showTitle ? a_title.toUpperCase() : "";
		this.TitleTextField._visible = showTitle;
		var bracketFrame:Number = Math.max(1, Math.min(QuestItem.bracketOpenLongestNameFrame, Math.ceil(this.TitleTextField.textWidth * QuestItem.bracketOpenLongestNameFrame / this.TitleTextField._width)));
		this.TitleBracket.gotoAndStop(bracketFrame);
		// Journal description and objectives are separate sections, never substitutes.
		var details:String = a_description == undefined ? "" : a_description;
		// The original Header establishes the Box's immutable natural width.
		var bracketBounds:Object = this.TitleBracket.getBounds(this.Title);
		var endBounds:Object = this.TitleEndPiece.getBounds(this.Title);
		this.detailBounds = this.GetDetailContentBounds();
		var contentWidth:Number = this.detailBounds.xMax - this.detailBounds.xMin;
		var titleTop:Number = Math.min(this.TitleTextField._y, Math.min(bracketBounds.yMin, endBounds.yMin));
		var titleBottom:Number = Math.max(this.TitleTextField._y + this.TitleTextField._height, Math.max(bracketBounds.yMax, endBounds.yMax));
		this.naturalLayout = {left:this.detailBounds.xMin, width:contentWidth, top:titleTop,
			bottom:titleBottom, bodyTop:titleBottom + 4};
		this.DetailBox.layoutLeft = this.detailBounds.outerLeft - 4;
		this.DetailBox.layoutTop = titleTop;
		this.DetailBox.layoutWidth = this.detailBounds.outerRight - this.detailBounds.outerLeft + 8;
		this.Title.layoutWidth = this.DetailBox.layoutWidth;
		this.Title.layoutHeight = titleBottom - titleTop;
		this.DetailBody._x = this.naturalLayout.left;
		this.DetailBody._y = this.naturalLayout.bodyTop;
		this.DetailBody.layoutWidth = contentWidth;
		this.DescriptionTextField._x = 0;
		this.DescriptionTextField._y = 0;
		this.DescriptionTextField.wordWrap = true;
		this.DescriptionTextField.autoSize = false;
		this.DescriptionTextField.multiline = true;
		var descriptionFormat:TextFormat = this.GetReadableTextFormat();
		descriptionFormat.align = "left";
		descriptionFormat.color = 0xFFFFFF;
		this.DescriptionTextField.setNewTextFormat(descriptionFormat);
		this.DescriptionTextField.text = details;
		this.DescriptionTextField.setTextFormat(descriptionFormat);
		this.DescriptionTextField.textColor = 0xFFFFFF;
		// Keep a slightly lighter black outline for readability without thickening the white glyphs.
		this.DescriptionTextField.filters = [
			new flash.filters.GlowFilter(0x000000, 1, 3, 3, 3, 2, false, false)
		];
		this.descriptionVisible = details.length > 0;
		// Keep the complete journal text; the Box measures it during layout.

		// Rebuild only generated content; the original title artwork and animation remain intact.
		if (this.ObjectivesHeader != undefined)
		{
			this.ObjectivesHeader.removeMovieClip();
			this.ObjectivesHeader = undefined;
		}
		if (this.ObjectiveContainer != undefined)
		{
			this.ObjectiveContainer.removeMovieClip();
			this.ObjectiveContainer = undefined;
		}
		this.ObjectiveItemList = new Array();
		var rowData:Array = a_objectives == undefined ? new Array() : a_objectives;
		var visibleObjectives:Array = new Array();
		for (var i:Number = 0; i < rowData.length; i++)
		{
			var data:Object = rowData[i];
			if (data == undefined || data == null)
			{
				continue;
			}
			var objectiveText:String = typeof(data) == "string" ? String(data) : String(data.text);
			if (objectiveText != "" && objectiveText != "undefined" && objectiveText != "null")
			{
				visibleObjectives.push({text:objectiveText, completed:data.completed == true && data.failed != true, failed:data.failed == true, order:i});
			}
		}
		visibleObjectives.sort(this.CompareObjectiveState);
		if (visibleObjectives.length > 0)
		{
			// The supplied divider has a blank center. Keep its aspect ratio and add
			// a separate localized label instead of baking English into the artwork.
			this.ObjectivesHeader = this.DetailBody.createEmptyMovieClip("ObjectivesHeader", this.DetailBody.getNextHighestDepth());
			this.ObjectivesHeader._x = 0;
			this.ObjectivesHeader._y = 0;
			var dividerHeight:Number = 16;
			this.ObjectivesHeader.createTextField("Label", this.ObjectivesHeader.getNextHighestDepth(), 0, 0, contentWidth, 24);
			var label:TextField = this.ObjectivesHeader.Label;
			label.selectable = false;
			label.multiline = false;
			label.wordWrap = false;
			label.embedFonts = this.TitleTextField.embedFonts;
			label.textAutoSize = "none";
			var labelFormat:TextFormat = this.GetReadableTextFormat();
			labelFormat.align = "center";
			labelFormat.bold = false;
			labelFormat.color = 0xDDDDDD;
			labelFormat.size = Math.max(10, Number(labelFormat.size) * 0.85);
			this.objectivesLabelSize = Number(labelFormat.size);
			label.setNewTextFormat(labelFormat);
			label.text = this.objectivesLabel == undefined ? "$OBJECTIVES" : this.objectivesLabel;
			label.setTextFormat(labelFormat);
			label.textColor = 0xDDDDDD;
			label.filters = [new flash.filters.GlowFilter(0x000000, 1, 3, 3, 3, 2, false, false)];
			var dividerArt:MovieClip = this.ObjectivesHeader.createEmptyMovieClip("Art", this.ObjectivesHeader.getNextHighestDepth());
			this.DrawDividerWing(dividerArt, "Left", 1, dividerHeight, false);
			this.DrawDividerWing(dividerArt, "Right", 1, dividerHeight, true);
			// Match the existing quest-detail ornament; no extra gray expansion.
			dividerArt.filters = [];
			this.ObjectiveContainer = this.DetailBody.createEmptyMovieClip("ObjectiveContainer", this.DetailBody.getNextHighestDepth());
			this.ObjectiveContainer._x = 0;
			this.ObjectiveContainer._y = 0;
			for (var j:Number = 0; j < visibleObjectives.length; j++)
			{
				var objective:Object = visibleObjectives[j];
				var row:MovieClip = this.ObjectiveContainer.createEmptyMovieClip("objective" + j, this.ObjectiveContainer.getNextHighestDepth());
				row._x = 0;
				row._y = 0;
				var iconName:String = objective.completed ? "QuestObjectiveCompleted" : "QuestObjectivePending";
				var icon:MovieClip = row.attachMovie(iconName, "StateIcon", row.getNextHighestDepth());
				if (icon == undefined)
				{
					icon = this.DrawObjectiveIconFallback(row, objective.completed == true);
				}
				// Keep the original icon size and black outline; only the divider is strengthened.
				// stays readable on busy backgrounds. Row text starts at x=26, so the
				// 18px-wide icon (x=2..20) never overlaps it.
				icon._width = 18;
				icon._height = 27;
				icon._x = 2;
				icon._alpha = objective.failed ? 50 : 100;
				icon.filters = [
					new flash.filters.GlowFilter(0x000000, 1, 4, 4, 4, 2, false, false)
				];
				row.createTextField("TextFieldInstance", row.getNextHighestDepth(), 26, 0, Math.max(1, contentWidth - 26), 30);
				var field:TextField = row.TextFieldInstance;
				field.multiline = true;
				field.wordWrap = true;
				field.autoSize = false;
				field.selectable = false;
				field.embedFonts = this.TitleTextField.embedFonts;
				var objectiveFormat:TextFormat = this.GetReadableTextFormat();
				objectiveFormat.align = "left";
				objectiveFormat.color = objective.completed || objective.failed ? 0xBBBBBB : 0xFFFFFF;
				field.setNewTextFormat(objectiveFormat);
				field.text = objective.text;
				field.setTextFormat(objectiveFormat);
				field.textColor = objectiveFormat.color;
				field.filters = [new flash.filters.GlowFilter(0x000000, 1, 3, 3, 3, 2, false, false)];
				this.ObjectiveItemList.push(row);
			}
		}
		this.ageIndex = a_ageIndex;
		this.LayoutDetailBox();
	}



	// Include the full diamond and its filter gutter in the row's clipping unit.
	// Text-only height can be shorter than the 27px icon, leaving a cut-off tip.
	private function LayoutObjectiveRow(a_row:MovieClip):Void
	{
		var textHeight:Number = this.MeasureTextHeight(a_row.TextFieldInstance, 18);
		a_row.contentHeight = Math.max(textHeight, a_row.StateIcon._height) + 8;
		a_row.TextFieldInstance._y = (a_row.contentHeight - textHeight) * 0.5;
		a_row.StateIcon._y = (a_row.contentHeight - a_row.StateIcon._height) * 0.5;
	}
