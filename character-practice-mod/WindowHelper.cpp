/**************************************************************************************
 *   WindowHelper.cpp  --  This file is part of Character Practice Mod.               *
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
#include "WindowHelper.h"

bool WindowHelper::FindSA2Window() {
	HandleData data = { GetCurrentProcessId(), NULL };
	EnumWindows(WindowHelper::EnumWindowCallback, (LPARAM)&data);

	WindowHelper::SA2Window = data.window;
	return WindowHelper::SA2Window != NULL;
}

BOOL CALLBACK WindowHelper::EnumWindowCallback(HWND hWnd, LPARAM lParam) {
	HandleData& data = *(HandleData*)lParam;
	unsigned long processId = 0;
	GetWindowThreadProcessId(hWnd, &processId);
	if (data.processId != processId || !WindowHelper::IsMainWindow(hWnd)) {
		return TRUE;
	}

	data.window = hWnd;
	return FALSE;
}

bool WindowHelper::IsMainWindow(HWND hWnd) {
	return GetWindow(hWnd, GW_OWNER) == (HWND)0 && IsWindowVisible(hWnd);
}

void WindowHelper::FatalError(LPCWSTR title, LPCWSTR body) {
	MessageBox(WindowHelper::SA2Window, body, title, MB_OK|MB_ICONERROR|MB_APPLMODAL);
	exit(EXIT_FAILURE);
}