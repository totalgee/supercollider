/*
	SuperCollider real time audio synthesis system
    Copyright (c) 2002 James McCartney. All rights reserved.
	http://www.audiosynth.com

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/


#ifndef _SC_GraphDef_
#define _SC_GraphDef_

#include "SC_SynthDef.h"
#include "HashTable.h"

struct ParamSpec
{
	int32 mName[kSCNameLen];
	int32 mIndex;
	int32 mHash;
};

struct GraphDef
{
	NodeDef mNodeDef;
	
	int32 mNumControls;
	
	int32 mNumWires;
	int32 mNumConstants;
	int32 mNumUnitSpecs;
	int32 mNumWireBufs;
	int32 mNumCalcUnits;
	
	float32 *mInitialControlValues;
	float32 *mConstants;

	struct UnitSpec *mUnitSpecs;
	
	size_t mWiresAllocSize, mUnitsAllocSize, mCalcUnitsAllocSize;
	size_t mControlAllocSize, mMapControlsAllocSize;
	
	int32 mNumParamSpecs;
	ParamSpec *mParamSpecs;
	HashTable<ParamSpec, Malloc> *mParamSpecTable;
	
	int mRefCount;
	struct GraphDef* mNext;
};
typedef struct GraphDef GraphDef;

GraphDef* GraphDef_Recv(World *inWorld, char *buffer, GraphDef *inList);
GraphDef* GraphDef_Load(struct World *inWorld, const char *filename, GraphDef* inList);
GraphDef* GraphDef_LoadDir(struct World *inWorld, char *dirname, GraphDef* inList);
void GraphDef_DeleteMsg(struct World *inWorld, GraphDef *inDef);
void GraphDef_Dump(GraphDef *inGraphDef);
int32 GetHash(ParamSpec* inParamSpec);
int32* GetKey(ParamSpec* inParamSpec);

#endif
