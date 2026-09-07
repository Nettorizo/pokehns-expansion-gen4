LakeOfRageLowTide_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LakeofRageLowTide_EventScript_AzureFluteCheck
	.byte 0

LakeofRageLowTide_EventScript_AzureFluteCheck::
	checkitem ITEM_AZURE_FLUTE
	goto_if_eq VAR_RESULT, FALSE, LakeofRageLowTide_EventScript_NoAzureFlute
	goto_if_eq VAR_RESULT, TRUE, LakeofRageLowTide_EventScript_PlayerOrLakeTrioRan
	release
	end

LakeofRageLowTide_EventScript_NoAzureFlute::
	setflag FLAG_HIDE_UXIE
	setflag FLAG_HIDE_MESPRIT
	setflag FLAG_HIDE_AZELF
	removeobject LOCALID_LAKEOFRAGE_LOWTIDE_UXIE
	removeobject LOCALID_LAKEOFRAGE_LOWTIDE_MESPRIT
	removeobject LOCALID_LAKEOFRAGE_LOWTIDE_AZELF
	release
	end

LakeofRageLowTide_EventScript_Uxie::
	lock
	faceplayer
	playmoncry SPECIES_UXIE, CRY_MODE_ENCOUNTER
	msgbox LakeofRageLowTide_Text_Uxie
	delay 20
	waitmoncry
	seteventmon SPECIES_UXIE, 50
	special BattleSetup_StartLegendaryBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, LakeofRageLowTide_EventScript_PlayerOrLakeTrioRan
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_LAKEOFRAGE_LOWTIDE_UXIE
	setflag FLAG_HIDE_UXIE
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

LakeofRageLowTide_EventScript_Mesprit::
	lock
	faceplayer
	playmoncry SPECIES_MESPRIT, CRY_MODE_ENCOUNTER
	msgbox LakeofRageLowTide_Text_Mesprit
	delay 20
	waitmoncry
	seteventmon SPECIES_MESPRIT, 50
	special BattleSetup_StartLegendaryBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, LakeofRageLowTide_EventScript_PlayerOrLakeTrioRan
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_LAKEOFRAGE_LOWTIDE_MESPRIT
	setflag FLAG_HIDE_MESPRIT
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

LakeofRageLowTide_EventScript_Azelf::
	lock
	faceplayer
	playmoncry SPECIES_AZELF, CRY_MODE_ENCOUNTER
	msgbox LakeofRageLowTide_Text_Azelf
	delay 20
	waitmoncry
	seteventmon SPECIES_AZELF, 50
	special BattleSetup_StartLegendaryBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, LakeofRageLowTide_EventScript_PlayerOrLakeTrioRan
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_LAKEOFRAGE_LOWTIDE_AZELF
	setflag FLAG_HIDE_AZELF
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

LakeofRageLowTide_EventScript_PlayerOrLakeTrioRan::
	release
	end

LakeOfRageLowTide_EventScript_Sage::
	msgbox LakeOfRageLowTide_Text_Sage, MSGBOX_NPC
	end

LakeofRageLowTide_Text_Uxie::
	.string "Kyouuuun!$"

LakeofRageLowTide_Text_Mesprit::
	.string "Kyauun.$"

LakeofRageLowTide_Text_Azelf::
	.string "Kyuuun...$"

LakeOfRageLowTide_Text_Sage::
	.string "This cave contains a POKéMON\n"
	.string "too strong for an ordinary\l"
	.string "trainer.$"

