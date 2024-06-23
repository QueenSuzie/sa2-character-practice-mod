/**************************************************************************************
 *   RushSequence.cpp  --  This file is part of Character Practice Mod.               *
 *                                                                                    *
 *   Copyright (C) 2024 Queen Suzie                                                   *
 *                                                                                    *
 *   Character Practice Mod is free software: you can redistribute it and/or modify   *
 *   it under the terms of the GNU General Public License as published                *
 *   by the Free Software Foundation, either version 3 of the License,                *
 *   or (at your option) any later version.                                           *
 *                                                                                    *
 *   Character Practice Mod is distributed in the hope that it will be useful,        *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty                      *
 *   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.                          *
 *   See the GNU General Public License for more details.                             *
 *                                                                                    *
 *   You should have received a copy of the GNU General Public License                *
 *   along with this program.  If not, see http://www.gnu.org/licenses/.              *
 *                                                                                    *
 *************************************************************************************/

#include "pch.h"
#include "RushSequence.h"

SeqSection RushSequence::PracticeOverrides[12][11] = {
	{
		SeqStage(Characters_Sonic, LevelIDs_CityEscape),
		SeqStage(Characters_Sonic, LevelIDs_MetalHarbor),
		SeqStage(Characters_Sonic, LevelIDs_GreenForest),
		SeqStage(Characters_Sonic, LevelIDs_PyramidCave),
		SeqStage(Characters_Sonic, LevelIDs_CrazyGadget),
		SeqStage(Characters_Sonic, LevelIDs_FinalRush),
		SeqTitle
	},
	{
		SeqStage(Characters_Sonic, LevelIDs_CityEscape),
		SeqStage(Characters_Sonic, LevelIDs_BigFoot),
		SeqStage(Characters_Sonic, LevelIDs_MetalHarbor),
		SeqStage(Characters_Sonic, LevelIDs_SonicVsShadow1),
		SeqStage(Characters_Sonic, LevelIDs_GreenForest),
		SeqStage(Characters_Sonic, LevelIDs_PyramidCave),
		SeqStage(Characters_Sonic, LevelIDs_EggGolemS),
		SeqStage(Characters_Sonic, LevelIDs_CrazyGadget),
		SeqStage(Characters_Sonic, LevelIDs_FinalRush),
		SeqStage(Characters_Sonic, LevelIDs_SonicVsShadow2),
		SeqTitle
	},
	{
		SeqStage(Characters_MechTails, LevelIDs_PrisonLane),
		SeqStage(Characters_MechTails, LevelIDs_MissionStreet),
		SeqStage(Characters_MechTails, LevelIDs_HiddenBase),
		SeqStage(Characters_MechTails, LevelIDs_EternalEngine),
		SeqTitle
	},
	{
		SeqStage(Characters_MechTails, LevelIDs_TailsVsEggman1),
		SeqStage(Characters_MechTails, LevelIDs_PrisonLane),
		SeqStage(Characters_MechTails, LevelIDs_MissionStreet),
		SeqStage(Characters_MechTails, LevelIDs_HiddenBase),
		SeqStage(Characters_MechTails, LevelIDs_EternalEngine),
		SeqStage(Characters_MechTails, LevelIDs_TailsVsEggman2),
		SeqTitle
	},
	{
		SeqStage(Characters_Knuckles, LevelIDs_WildCanyon),
		SeqStage(Characters_Knuckles, LevelIDs_PumpkinHill),
		SeqStage(Characters_Knuckles, LevelIDs_AquaticMine),
		SeqStage(Characters_Knuckles, LevelIDs_DeathChamber),
		SeqStage(Characters_Knuckles, LevelIDs_MeteorHerd),
		SeqTitle
	},
	{
		SeqStage(Characters_Knuckles, LevelIDs_WildCanyon),
		SeqStage(Characters_Knuckles, LevelIDs_PumpkinHill),
		SeqStage(Characters_Knuckles, LevelIDs_AquaticMine),
		SeqStage(Characters_Knuckles, LevelIDs_DeathChamber),
		SeqStage(Characters_Knuckles, LevelIDs_KingBoomBoo),
		SeqStage(Characters_Knuckles, LevelIDs_MeteorHerd),
		SeqStage(Characters_Knuckles, LevelIDs_KnucklesVsRouge),
		SeqTitle
	},
	{
		SeqStage(Characters_Shadow, LevelIDs_RadicalHighway),
		SeqStage(Characters_Shadow, LevelIDs_WhiteJungle),
		SeqStage(Characters_Shadow, LevelIDs_SkyRail),
		SeqStage(Characters_Shadow, LevelIDs_FinalChase),
		SeqTitle
	},
	{
		SeqStage(Characters_Shadow, LevelIDs_HotShot),
		SeqStage(Characters_Shadow, LevelIDs_RadicalHighway),
		SeqStage(Characters_Shadow, LevelIDs_WhiteJungle),
		SeqStage(Characters_Shadow, LevelIDs_SonicVsShadow1),
		SeqStage(Characters_Shadow, LevelIDs_SkyRail),
		SeqStage(Characters_Shadow, LevelIDs_FinalChase),
		SeqStage(Characters_Shadow, LevelIDs_SonicVsShadow2),
		SeqTitle
	},
	{
		SeqStage(Characters_MechEggman, LevelIDs_IronGate),
		SeqStage(Characters_MechEggman, LevelIDs_SandOcean),
		SeqStage(Characters_MechEggman, LevelIDs_LostColony),
		SeqStage(Characters_MechEggman, LevelIDs_WeaponsBed),
		SeqStage(Characters_MechEggman, LevelIDs_CosmicWall),
		SeqTitle
	},
	{
		SeqStage(Characters_MechEggman, LevelIDs_IronGate),
		SeqStage(Characters_MechEggman, LevelIDs_SandOcean),
		SeqStage(Characters_MechEggman, LevelIDs_LostColony),
		SeqStage(Characters_MechEggman, LevelIDs_WeaponsBed),
		SeqStage(Characters_MechEggman, LevelIDs_TailsVsEggman1),
		SeqStage(Characters_MechEggman, LevelIDs_EggGolemE),
		SeqStage(Characters_MechEggman, LevelIDs_CosmicWall),
		SeqStage(Characters_MechEggman, LevelIDs_TailsVsEggman2),
		SeqTitle
	},
	{
		SeqStage(Characters_Rouge, LevelIDs_DryLagoon),
		SeqStage(Characters_Rouge, LevelIDs_EggQuarters),
		SeqStage(Characters_Rouge, LevelIDs_SecurityHall),
		SeqStage(Characters_Rouge, LevelIDs_MadSpace),
		SeqTitle
	},
	{
		SeqStage(Characters_Rouge, LevelIDs_DryLagoon),
		SeqStage(Characters_Rouge, LevelIDs_EggQuarters),
		SeqStage(Characters_Rouge, LevelIDs_SecurityHall),
		SeqStage(Characters_Rouge, LevelIDs_FlyingDog),
		SeqStage(Characters_Rouge, LevelIDs_MadSpace),
		SeqStage(Characters_Rouge, LevelIDs_KnucklesVsRouge),
		SeqTitle
	}
};

void RushSequence::Init(int hero, int dark, int all) {
	if (
		(hero < 0 || hero >= RushSequence::PracticeOverridesSize) ||
		(dark < 0 || dark >= RushSequence::PracticeOverridesSize) ||
		(all < 0 || all >= RushSequence::PracticeOverridesSize)
	) {
		WindowHelper::FatalError(L"Character Practice Mod: Invalid Configuration",
			L"One or more of the configuration values for\n"
			L"the Character Practice Mod were invalid!\n\n"
			L"Please reconfigure the mod."
		);
	}

	WritePointer((void*)0x458830, RushSequence::PracticeOverrides[hero]);
	WritePointer((void*)0x458851, RushSequence::PracticeOverrides[dark]);
	WritePointer((void*)0x458872, RushSequence::PracticeOverrides[all]);
}

void MemCopyProtected(void* pDst, const void* pSrc, size_t nb) {
	DWORD old_prot;
	VirtualProtect(pDst, nb, PAGE_EXECUTE_READWRITE, &old_prot);
	memcpy(pDst, pSrc, nb);
}