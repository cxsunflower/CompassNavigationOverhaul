

function AddQuest(a_type:Number, a_title:String, a_description:String, a_isInSameLocation:Boolean, a_objectives:Array, a_ageIndex:Number):Void
{
	questItem = attachMovie("QuestItem", "questItem" + getNextHighestDepth(), getNextHighestDepth(), { _xscale:SCALE * TEXT_SCALE / 100, _yscale:SCALE * TEXT_SCALE / 100 });

	entries.push(questItem);

	questItem._visible = false;
	questItem.SetQuestInfo(a_type, a_title, a_description, a_isInSameLocation, a_objectives, a_ageIndex);
    fitKey = "";
	questItem.gotoAndStop("IdleHide");
}

// Reconcile native snapshots without restarting unchanged quest animations.
function SyncQuests(a_quests:Array):Void
{
    var next:Array = new Array();
    var nextByKey:Object = new Object();
    for (var i:Number = 0; i < a_quests.length; i++)
    {
        var data:Object = a_quests[i];
        var key:String = String(data.key);
        var item:QuestItem = entriesByKey[key];
        var isNew:Boolean = item == undefined;
        if (isNew)
        {
            item = attachMovie("QuestItem", "questItem" + getNextHighestDepth(), getNextHighestDepth(), { _xscale:SCALE * TEXT_SCALE / 100, _yscale:SCALE * TEXT_SCALE / 100 });
            item._visible = false;
            item.questKey = key;
            item.gotoAndStop("IdleHide");
        }
        if (isNew || item.dataSignature != data.signature)
        {
            item.SetQuestInfo(data.type, data.title, data.description, data.isInSameLocation, data.objectives, data.ageIndex);
            if (data.side != undefined && data.side != "")
            {
                item.SetSide(data.side);
            }
            item.dataSignature = data.signature;
        }
        next.push(item);
        nextByKey[key] = item;
    }
    for (var j:Number = 0; j < entries.length; j++)
    {
        var previous:QuestItem = entries[j];
        if (nextByKey[previous.questKey] == undefined)
        {
            previous._visible = false;
            previous.removeMovieClip();
        }
    }
    entries = next;
    entriesByKey = nextByKey;
    questItem = entries.length > 0 ? entries[entries.length - 1] : undefined;
    UpdateAnchor();
}

function ShowQuest():Void
{
	questItem.Show();
}

function RemoveQuest():Void
{
	questItem._visible = false;
	questItem.removeMovieClip();
}

function ShowAllQuests():Void
{
	for (var i:Number = 0; i < entries.length; i++)
	{
		questItem = entries[i];

		if (!questItem.isBeingShown)
		{
			questItem.Show();
		}
	}
}

function RemoveAllQuests():Void
{
	for (var i:Number = 0; i < entries.length; i++)
	{
		questItem = entries[i];
		if (!questItem.isBeingShown)
		{
			questItem._alpha = 0;
		}
		questItem._visible = false;
	questItem.removeMovieClip();
	}

	entries.splice(0, entries.length);
    entriesByKey = new Object();
    questItem = undefined;
}

function ByAgeThenMiscellaneousQuests(a_questItem1:QuestItem, a_questItem2:QuestItem):Number
{
	if (a_questItem1.TitleEndPiece._currentframe != QuestItem.miscQuestFrame &&
		a_questItem2.TitleEndPiece._currentframe == QuestItem.miscQuestFrame)
	{
		return -1;
	}
	else if (a_questItem1.TitleEndPiece._currentframe == QuestItem.miscQuestFrame &&
			 a_questItem2.TitleEndPiece._currentframe != QuestItem.miscQuestFrame)
	{
		return 1;
	}
	else if (a_questItem1.ageIndex > a_questItem2.ageIndex)
	{
		return -1;
	}
	else if (a_questItem1.ageIndex < a_questItem2.ageIndex)
	{
		return 1;
	}

	return 0;
}
