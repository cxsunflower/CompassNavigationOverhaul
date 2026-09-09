class CompassMarkerInfo extends MovieClip
{
	static var UNITS_TO_METERS:Number = 0.01428;
	static var UNITS_TO_FEET:Number = 0.046875;

	// Instances
	var HeightIndicatorInstance:MovieClip;
	var Distance:MovieClip;
	var Target:MovieClip;

	// References
	var Movie:MovieClip;

	// Variables
	var Index:Number;
	var Objective:String;
	var Location:String;
	var UseMetricUnits:Boolean;
	var NameScale:Number;
	var DistanceScale:Number;
	var NameCenter:Number;
	var DistanceCenter:Number;
	var HeightBaseScaleX:Number;
	var HeightBaseScaleY:Number;

	public function CompassMarkerInfo()
	{
		this.Index = -1;
		this.NameScale = 100;
		this.DistanceScale = 100;
		this.Distance.TextFieldInstance.autoSize = "center";
	}

	public function SetTextScale(a_scale:Number):Void
	{
		this._xscale = a_scale;
		this._yscale = a_scale;
	}

	public function SetNameScale(a_scale:Number):Void
	{
		if (!isNaN(a_scale) && isFinite(a_scale))
		{
			this.NameScale = Math.max(25, Math.min(150, a_scale));
		}
		this.ApplyTextScales();
		this.ApplyNameViewportGuard();
	}

	public function SetDistanceScale(a_scale:Number):Void
	{
		if (!isNaN(a_scale) && isFinite(a_scale))
		{
			this.DistanceScale = Math.max(25, Math.min(150, a_scale));
		}
		this.ApplyTextScales();
		this.ApplyNameViewportGuard();
	}

	public function ApplyTextScales():Void
	{
		// this.Target and this.Distance are timeline-animated: never scale their containers.
		// Scaling this.Target would also scale its embedded QuestItemList.
		if (this.Target.TextFieldInstance != undefined)
		{
			if (this.NameCenter == undefined)
			{
				this.NameCenter = this.Target.TextFieldInstance._x + this.Target.TextFieldInstance._width * 0.5;
			}
			this.Target.TextFieldInstance._xscale = this.NameScale;
			this.Target.TextFieldInstance._yscale = this.NameScale;
			this.Target.TextFieldInstance._x = this.NameCenter - this.Target.TextFieldInstance._width * 0.5;
		}
		if (this.Distance.TextFieldInstance != undefined)
		{
			if (this.DistanceCenter == undefined)
			{
				this.DistanceCenter = this.Distance.TextFieldInstance._x + this.Distance.TextFieldInstance._width * 0.5;
			}
			this.Distance.TextFieldInstance._xscale = this.DistanceScale;
			this.Distance.TextFieldInstance._yscale = this.DistanceScale;
			var arrowWidth:Number = 0;
			var arrowGap:Number = 0;
			if (this.Distance.HeightIndicatorInstance != undefined)
			{
				// The authored arrow is about 35%, not 100%. Cache its base once
				// per instance so name changes and frame updates cannot compound it.
				if (this.HeightIndicatorInstance != this.Distance.HeightIndicatorInstance)
				{
					this.HeightIndicatorInstance = this.Distance.HeightIndicatorInstance;
					this.HeightBaseScaleX = this.HeightIndicatorInstance._xscale;
					this.HeightBaseScaleY = this.HeightIndicatorInstance._yscale;
				}
				this.HeightIndicatorInstance._xscale = this.HeightBaseScaleX * this.DistanceScale / 100;
				this.HeightIndicatorInstance._yscale = this.HeightBaseScaleY * this.DistanceScale / 100;
				if (this.HeightIndicatorInstance._alpha > 0 && this.HeightIndicatorInstance._visible != false)
				{
					arrowWidth = this.HeightIndicatorInstance._width;
					arrowGap = arrowWidth / 3;
				}
			}
			// autoSize centers text changes, but does not anchor explicit scaling.
			// Center the complete visible readout at the original distance anchor.
			this.Distance.TextFieldInstance._x = this.DistanceCenter -
				(this.Distance.TextFieldInstance._width + arrowGap + arrowWidth) * 0.5;
			if (this.HeightIndicatorInstance != undefined)
			{
				var arrowBounds:Object = this.HeightIndicatorInstance.getBounds(this.Distance);
				this.HeightIndicatorInstance._x += this.Distance.TextFieldInstance._x +
					this.Distance.TextFieldInstance._width + arrowGap - arrowBounds.xMin;
			}
		}
	}

	public function ApplyNameViewportGuard():Void
	{
		var field:TextField = this.Target.TextFieldInstance;
		if (field == undefined) return;
		var points:Array = [{x:field._x,y:field._y},{x:field._x+field._width,y:field._y},
			{x:field._x,y:field._y+field._height},{x:field._x+field._width,y:field._y+field._height}];
		var top:Number = Number.POSITIVE_INFINITY;
		var bottom:Number = Number.NEGATIVE_INFINITY;
		for (var i:Number = 0; i < points.length; i++)
		{
			this.Target.localToGlobal(points[i]);
			_root.globalToLocal(points[i]);
			top = Math.min(top,points[i].y);
			bottom = Math.max(bottom,points[i].y);
		}
		var safeBottom:Number = Stage.height - Math.max(20,Stage.height*0.08);
		// Only gate the name; preserve the timeline and its alpha/combat gating.
		field._visible = isFinite(top) && isFinite(bottom) && top >= 12 && bottom + 4 <= safeBottom;
	}

	public function onEnterFrame():Void
	{
		// Reapply after child creation and keep arrow placement aligned with autoSize text.
		this.ApplyTextScales();
		this.ApplyNameViewportGuard();
	}

	public function SetDistanceAndHeightDifference(a_distance:Number, a_heightDifference:Number):Void
	{
		if (this.UseMetricUnits)
		{
			this.Distance.TextFieldInstance.text = String(Math.floor(a_distance * CompassMarkerInfo.UNITS_TO_METERS)) + " m";
		}
		else
		{
			this.Distance.TextFieldInstance.text = String(Math.floor(a_distance * CompassMarkerInfo.UNITS_TO_FEET)) + " ft ";
		}

		// Height like 3 or 4 floors. Measured in Skyrim units.
		if (a_heightDifference > 840)
		{
			this.Distance.HeightIndicatorInstance._alpha = Math.max(this.Movie._alpha, 75);
			this.Distance.HeightIndicatorInstance.gotoAndStop("Above");
		}
		else if (a_heightDifference < -840)
		{
			this.Distance.HeightIndicatorInstance._alpha = Math.max(this.Movie._alpha, 75);
			this.Distance.HeightIndicatorInstance.gotoAndStop("Below");
		}
		else
		{
			this.Distance.HeightIndicatorInstance._alpha = 0;
		}
		// Measure after selecting the arrow frame/visibility for this update.
		this.ApplyTextScales();
		this.ApplyNameViewportGuard();
	}
}
