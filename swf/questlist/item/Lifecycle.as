

	public function SetSide(a_side:String):Void
	{
		this.TitleEndPiece.SideArt.gotoAndStop(a_side);
	}

	public function Show():Void
	{
		this.gotoAndPlay("FadeIn");
	}

	public function Remove():Void
	{
		this.gotoAndPlay("FadeOut");
	}
