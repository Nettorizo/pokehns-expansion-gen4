AbandonedHouse_TVRoom_hns_MapScripts::
	.byte 0

AbandonedHouse_TVRoom_EventScript_Item_RotomCatalog::
	finditem ITEM_ROTOM_CATALOG
	release
	end

AbandonedHouse_TVRoom_EventScript_CheckTV::
	checkflag FLAG_HIDE_ROTOM
	goto_if_eq VAR_RESULT, FALSE, AbandonedHouse_TVRoom_EventScript_TVInteract
	goto_if_eq VAR_RESULT, TRUE, AbandonedHouse_TVRoom_TVText_NoRotom
	release
	end

AbandonedHouse_TVRoom_EventScript_TVInteract::
	msgbox AbandonedHouse_TVRoom_TVText_Rotom, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, AbandonedHouse_TVRoom_EventScript_PlayerOrRotomRan
	case YES, AbandonedHouse_TVRoom_EventScript_Rotom
	case MULTI_B_PRESSED, AbandonedHouse_TVRoom_EventScript_PlayerOrRotomRan

AbandonedHouse_TVRoom_EventScript_Rotom::
	lock
	faceplayer
	playmoncry SPECIES_ROTOM, CRY_MODE_ENCOUNTER
	delay 20
	waitmoncry
	seteventmon SPECIES_ROTOM, 50
	special BattleSetup_StartLegendaryBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, AbandonedHouse_TVRoom_EventScript_PlayerOrRotomRan
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_ABANDONEDHOUSE_TVROOM_GLOW
	setflag FLAG_HIDE_ROTOM
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

AbandonedHouse_TVRoom_EventScript_PlayerOrRotomRan::
	release
	end

AbandonedHouse_TVRoom_TVText_Rotom::
	.string "Inside the TV...\p"
	.string "There appears to be a POKéMON...?\n"
	.string "The POKéMON appears as if it will come\p"
	.string "out. Want to thump the TV?$"

AbandonedHouse_TVRoom_TVText_NoRotom::
	.string "The POKéMON has left the TV.\n"
