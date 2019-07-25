/*MIT License

#Copyright(c) 2019 CAST Group of Companies Inc

#Permission is hereby granted, free of charge, to any person obtaining a copy
#of this software and associated documentation files(the "Software"), to deal
#in the Software without restriction, including without limitation the rights
#to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
#copies of the Software, and to permit persons to whom the Software is
#furnished to do so, subject to the following conditions :

#The above copyright notice and this permission notice shall be included in all
#copies or substantial portions of the Software.

#THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
#IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
#FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
#AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
#LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
#OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
#SOFTWARE. */

#ifndef RTTRP_H
#define RTTRP_H

#include "protocol_common.h"
#include "thirdParty_motion.h"
#include "lighting.h"

// Remove if not needed
#ifdef _DEBUG
	#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
	#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif

#pragma once

using namespace std;

class RTTrP
{
	public:
		uint16_t intHeader, fltHeader, version;
		uint32_t pID;
		uint8_t pForm;
		uint16_t pktSize;
		uint32_t context;
		uint8_t numMods;
		vector<unsigned char> data;

		RTTrP();
		RTTrP(vector<unsigned char>);
		~RTTrP();

		void printHeader(void);
};

class RTTrPM
{
	public:
		RTTrP *header;
		Trackable *trackable;
		CentroidMod *centroidMod;
		vector<LEDModule*> *ledMod;
		QuatModule *quatMod;
		EulerModule *eulerMod;
		CentroidAccVelMod *cavMod;
		vector<LEDAccVelMod*> *lavMod;
		vector<unsigned char> *data;
		vector<uint8_t> pkType;

		RTTrPM();
		~RTTrPM();

		void printPacket(void);
};

class RTTrPL
{
	public:
		RTTrP *header;
		LightingOutput *lightOut;
		LightingSync *sync;

		RTTrPL();
		RTTrPL(RTTrPL* toCopy);
		~RTTrPL();

		void printModule(void);
};

#endif // RTTRP_H
