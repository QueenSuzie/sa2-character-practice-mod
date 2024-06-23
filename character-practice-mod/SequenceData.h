/**************************************************************************************
 *   SequenceData.h  --  This file is part of Character Practice Mod.                 *
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

DataPointer(byte, StorySequenceIndex, 0x1DEB31E);
DataPointer(uint8_t, CurrentSequenceNo, 0x1DEB320);

typedef struct {
    uint8_t type;
    uint8_t player_num;
    uint8_t stage_num;
    int16_t event_num[4];
} SeqSection;

enum {
    SEQ_TYPE_EVENT,
    SEQ_TYPE_STAGE,
    SEQ_TYPE_TITLE,
    SEQ_TYPE_ENDING
};

#define NO_EVENT -1
#define FUNC_CHOOSER(_f0, _f1, _f2, _f3, _f4, _f5, _f6, _f7, _f8, _f9, _f10, _f11, _f12, _f13, _f14, _f15, _f16, ...) _f16
#define FUNC_RECOMPOSER(argsWithParentheses) FUNC_CHOOSER argsWithParentheses
#define CHOOSE_FROM_ARG_COUNT(F, ...) FUNC_RECOMPOSER((__VA_ARGS__, \
            F##_16, F##_15, F##_14, F##_13, F##_12, F##_11, F##_10, F##_9, F##_8,\
            F##_7, F##_6, F##_5, F##_4, F##_3, F##_2, F##_1, ))
#define NO_ARG_EXPANDER(FUNC) ,,,,,,,,,,,,,,,,FUNC ## _0
#define MACRO_CHOOSER(FUNC, ...) CHOOSE_FROM_ARG_COUNT(FUNC, NO_ARG_EXPANDER __VA_ARGS__ (FUNC))
#define MULTI_MACRO(FUNC, ...) MACRO_CHOOSER(FUNC, __VA_ARGS__)(__VA_ARGS__)

#define SeqEvent(...) MULTI_MACRO(SEQEVENT, __VA_ARGS__)
#define SEQEVENT_0() SEQEVENT_1(NO_EVENT)
#define SEQEVENT_1(EventOne) SEQEVENT_2(EventOne, NO_EVENT)
#define SEQEVENT_2(EventOne, EventTwo) \
			SEQEVENT_3(EventOne, EventTwo, NO_EVENT)
#define SEQEVENT_3(EventOne, EventTwo, EventThree) \
			SEQEVENT_4(EventOne, EventTwo, EventThree, NO_EVENT)
#define SEQEVENT_4(EventOne, EventTwo, EventThree, EventFour) \
			{ SEQ_TYPE_EVENT, Characters_Sonic, LevelIDs_BasicTest, { EventOne, EventTwo, EventThree, EventFour } }

#define SeqStage(CharacterID, StageID) { SEQ_TYPE_STAGE, CharacterID, StageID, { -1, -1, -1, -1 } }
#define SeqCredits { SEQ_TYPE_ENDING, Characters_Sonic, LevelIDs_BasicTest, { -1, -1, -1, -1 } }
#define SeqTitle { SEQ_TYPE_TITLE }