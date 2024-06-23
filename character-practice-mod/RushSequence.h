/**************************************************************************************
 *   RushSequence.h  --  This file is part of Character Practice Mod.                 *
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

#pragma once

void MemCopyProtected(void*, const void*, size_t);

#define WriteMemory(waddr, daddr, size) MemCopyProtected((void*)(waddr), (void*)(daddr), (size_t)(size))

#define WritePData(addr, data, type) { type _v_ = (type)(data); WriteMemory((addr), &_v_, sizeof(type)); }
#define WritePointer(addr, ptr) WritePData((addr), (ptr), void*)

class RushSequence {
	public:
		static void Init(int, int, int);
		static inline const unsigned short PracticeOverridesSize = 12;
		static SeqSection PracticeOverrides[RushSequence::PracticeOverridesSize][11];
};

