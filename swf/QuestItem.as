// Source modules are expanded by tools/questlist_source.py before JPEXS import.

class QuestItem extends MovieClip
{
	// Static variables
	static public var mainQuestFrame:Number;
	static public var magesGuildQuestFrame:Number;
	static public var thievesGuildQuestFrame:Number;
	static public var darkBrotherhoodQuestFrame:Number;
	static public var companionQuestFrame:Number;
	static public var miscQuestFrame:Number;
	static public var daedricQuestFrame:Number;
	static public var favorQuestFrame:Number;
	static public var civilWarQuestFrame:Number;
	static public var dlc01QuestFrame:Number;
	static public var dlc02QuestFrame:Number;
	static private var bracketOpenLongestNameFrame:Number;

	// Instances
	var Title:MovieClip;
	var ObjectiveItemList:Array;

	// References
	private var TitleTextField:TextField;
	private var DescriptionTextField:TextField;
	public var TitleEndPiece:MovieClip;
	private var TitleBracket:MovieClip;
	private var ObjectivesHeader:MovieClip;
	private var ObjectiveContainer:MovieClip;
	private var DetailBox:MovieClip;
	private var DetailBody:MovieClip;
	private var DetailContentMask:MovieClip;
	private var detailBounds:Object;
	private var contentRect:Object;
	private var descriptionVisible:Boolean;
	private var naturalLayout:Object;
	private var objectivesLabelSize:Number;
	public var questKey:String;
	public var dataSignature:String;
	public var objectivesLabel:String;

	// Variables
	public var isBeingShown:Boolean;
	public var ageIndex:Number;

	// @include "item/Initialization.as"

	// @include "item/Artwork.as"

	// @include "item/Content.as"

	// @include "item/Layout.as"

	// @include "item/Geometry.as"

	// @include "item/Debug.as"

	// @include "item/Lifecycle.as"

}
