/**************************************************************************************
 *   main.cpp  --  This file is part of Character Practice Mod.                       *
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

DataArray(LevelCutscene, LevelCutscenes, 0x173A808, 16);

extern "C" {
	__declspec(dllexport) void __cdecl Init(const char* path, const HelperFunctions& helperFunctions) {
		if (!WindowHelper::FindSA2Window()) {
			return;
		}

		const IniFile* config = new IniFile(std::string(path) + "\\config.ini");

		bool no_mini_cutscenes = config->getBool("General", "disable_cutscenes", true);
		int hero = config->getInt("General", "hero_rush", 0);
		int dark = config->getInt("General", "dark_rush", 2);
		int all = config->getInt("General", "all_rush", 4);

		delete config;

		RushSequence::Init(hero, dark, all);
		if (no_mini_cutscenes) {
			for (unsigned short i = 0; i < LevelCutscenes.size(); i++) {
				LevelCutscenes[i].Character = 50;
			}
		}
	}

	__declspec(dllexport) ModInfo SA2ModInfo = { ModLoaderVer }; // This is needed for the Mod Loader to recognize the DLL.
}