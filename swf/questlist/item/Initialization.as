	public function QuestItem()
	{
		super();
		this.ObjectiveItemList = new Array();
		this.contentRect = {xMin:0, yMin:0, xMax:0, yMax:0};

		// The SWF wrapper is the animation target. Its original, unmodified
		// QuestTitle symbol is Header; retain Title as a compatibility reference.
		this.Title = this.DetailBox.Header;
		this.TitleTextField = this.Title.TitleTextField;
		// Keep the original title art outside the generated-content mask.
		// The current source has no description field, but hide one if an older
		// FLA supplies it so it cannot draw outside the new content container.
		if (this.Title.DescriptionTextField != undefined)
		{
			this.Title.DescriptionTextField._visible = false;
		}
		this.DetailBox.layoutLeft = 0;
		this.DetailBox.layoutTop = 0;
		this.DetailBox.layoutWidth = 0;
		this.DetailBox.layoutHeight = 0;
		this.DetailBody = this.DetailBox.createEmptyMovieClip("DetailBody", this.DetailBox.getNextHighestDepth());
		this.DetailBody.layoutWidth = 0;
		this.DetailBody.layoutHeight = 0;
		this.DetailBody.createTextField("DescriptionTextField", this.DetailBody.getNextHighestDepth(), 0, 0, this.TitleTextField._width, 40);
		this.DescriptionTextField = this.DetailBody.DescriptionTextField;
		this.DescriptionTextField.multiline = true;
		this.DescriptionTextField.wordWrap = true;
		this.DescriptionTextField._visible = false;
		this.DetailContentMask = this.DetailBox.createEmptyMovieClip("DetailContentMask", this.DetailBox.getNextHighestDepth());
		this.DetailBody.setMask(this.DetailContentMask);
		// Dynamic fields must inherit Skyrim's font and color (including translations).
		this.DescriptionTextField.setNewTextFormat(this.GetReadableTextFormat());
		this.DescriptionTextField.textColor = this.TitleTextField.textColor;
		this.DescriptionTextField.selectable = false;
		this.DescriptionTextField.embedFonts = this.TitleTextField.embedFonts;
		this.TitleEndPiece = this.Title.EndPiece;
		this.TitleBracket = this.Title.Bracket;
		// Match the quest-detail text outline so the ornament remains readable on busy backgrounds.
		this.TitleEndPiece.filters = [];
		this.TitleBracket.filters = [];

		this.TitleTextField.textAutoSize = "shrink";

		this.TitleEndPiece.gotoAndStop("Main");
		QuestItem.mainQuestFrame = this.TitleEndPiece._currentframe;

		this.TitleEndPiece.gotoAndStop("MagesGuild");
		QuestItem.magesGuildQuestFrame = this.TitleEndPiece._currentframe;

		this.TitleEndPiece.gotoAndStop("ThievesGuild");
		QuestItem.thievesGuildQuestFrame = this.TitleEndPiece._currentframe;

		this.TitleEndPiece.gotoAndStop("DarkBrotherhood");
		QuestItem.darkBrotherhoodQuestFrame = this.TitleEndPiece._currentframe;

		this.TitleEndPiece.gotoAndStop("Companion");
		QuestItem.companionQuestFrame = this.TitleEndPiece._currentframe;

		this.TitleEndPiece.gotoAndStop("Misc");
		QuestItem.miscQuestFrame = this.TitleEndPiece._currentframe;

		this.TitleEndPiece.gotoAndStop("Daedric");
		QuestItem.daedricQuestFrame = this.TitleEndPiece._currentframe;

		this.TitleEndPiece.gotoAndStop("Favor");
		QuestItem.favorQuestFrame = this.TitleEndPiece._currentframe;

		this.TitleEndPiece.gotoAndStop("CivilWar");
		QuestItem.civilWarQuestFrame = this.TitleEndPiece._currentframe;

		this.TitleEndPiece.gotoAndStop("DLC01");
		QuestItem.dlc01QuestFrame = this.TitleEndPiece._currentframe;

		this.TitleEndPiece.gotoAndStop("DLC02");
		QuestItem.dlc02QuestFrame = this.TitleEndPiece._currentframe;

		this.TitleBracket.gotoAndStop("longest name");
		QuestItem.bracketOpenLongestNameFrame = this.TitleBracket._currentframe;
	}

	// Measure wrapped text at its assigned width, then freeze the field size.
	// textHeight excludes the usual two-pixel TextField gutters on each side.
	// Use the configured font alias explicitly. A blank title can return an
	// incomplete format, and the active Chinese font pack supplies Normal only.
	private function GetReadableTextFormat():TextFormat
	{
		var format:TextFormat = this.TitleTextField.getTextFormat();
		format.font = "$EverywhereMediumFont";
		format.bold = false;
		format.italic = false;
		if (isNaN(Number(format.size)) || Number(format.size) <= 0)
		{
			format.size = 24;
		}
		return format;
	}

	private function MeasureTextHeight(a_field:TextField, a_minHeight:Number):Number
	{
		a_field.autoSize = false;
		var height:Number = a_field.textHeight + 4;
		if (isNaN(height) || !isFinite(height))
		{
			height = a_minHeight;
		}
		a_field._height = Math.max(a_minHeight, Math.ceil(height));
		return a_field._height;
	}
