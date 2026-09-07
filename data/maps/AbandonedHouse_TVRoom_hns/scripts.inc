AbandonedHouse_TVRoom_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION AbandonedHouse_TVRoom_OnTransition
	.byte 0

AbandonedHouse_TVRoom_OnTransition::
	goto_if_unset FLAG_HIDE_ROTOM, AbandonedHouse_TVRoom_EventScript_AddTVGlow
	end

AbandonedHouse_TVRoom_EventScript_AddTVGlow::
	setmetatile 23, 50, 0x325, TRUE
	end

AbandonedHouse_TVRoom_EventScript_Item_RotomCatalog::
	finditem ITEM_ROTOM_CATALOG
	end

AbandonedHouse_TVRoom_EventScript_CheckTV::
	goto_if_unset FLAG_HIDE_ROTOM, AbandonedHouse_TVRoom_EventScript_TVInteract
	release
	end

AbandonedHouse_TVRoom_EventScript_TVInteract::
	msgbox AbandonedHouse_TVRoom_TVText_Rotom, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, AbandonedHouse_TVRoom_EventScript_Rotom
	case NO, AbandonedHouse_TVRoom_EventScript_PlayerOrRotomRan
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
	setflag FLAG_HIDE_ROTOM
	setmetatile 23, 50, 0x314, TRUE
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

AbandonedHouse_TVRoom_EventScript_PlayerOrRotomRan::
	release
	end

AbandonedShip_TVRoom_EventScript_NoRotom::
	msgbox AbandonedHouse_TVRoom_TVText_NoRotom, MSGBOX_DEFAULT
	release
	end

AbandonedHouse_TVRoom_TVText_Rotom::
	.string "Inside the TV...\p"
	.string "There appears to be a POKéMON...?\n"
	.string "The POKéMON looks like it wants to\p"
	.string "come out. Want to touch the TV?$"

AbandonedHouse_TVRoom_TVText_NoRotom::
	.string "The POKéMON has left the TV.\n"
