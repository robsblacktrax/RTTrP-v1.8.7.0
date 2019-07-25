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

#ifndef LIGHTING_H
#define LIGHTING_H

// Remove if not needed
#ifdef _DEBUG
	#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
	#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif

#include "protocol_common.h"
#include "thirdParty_motion.h"

#pragma once



class ChannelBlock : Packet
{
public:
	uint16_t chanOffset, xFade;
	uint8_t value;

	ChannelBlock();
	ChannelBlock(std::vector<unsigned char> *data, uint16_t intSig, uint16_t fltSig);
	~ChannelBlock();

	void printModule();
};

class Spot : public Packet
{
	public:
		uint16_t size, spotID, spotOffset, channelStruct;
		std::vector<ChannelBlock*> *chanBlocks;

		Spot();
		Spot(std::vector<unsigned char> *data, uint16_t intSig, uint16_t fltSig);
		~Spot();

		void printModule();
};

class Universe : public Packet
{
	public:
		uint16_t size, universeID, numSpots;
		std::vector<Spot*> *spotList;

		Universe();
		Universe(std::vector<unsigned char> *data, uint16_t intSig, uint16_t fltSig);
		~Universe();

		void printModule();
};

class LightingOutput : public Packet
{
	public:
		uint16_t size;
		uint32_t lightSeuquence;
		uint8_t action;
		uint32_t holdTime;
		uint16_t numUniverses;
		std::vector<Universe*> *uniList;

		LightingOutput();
		LightingOutput(std::vector<unsigned char> *data, uint16_t intSig, uint16_t fltSig);
		~LightingOutput();

		void printModule();
};

// This is not currently in use
class LightingSync : public Packet
{
	public:
		uint16_t size;
		uint32_t deviceID, deviceSubID0, deviceSubID1, seqNum;

		LightingSync();
		LightingSync(std::vector<unsigned char> *data, uint16_t intSig, uint16_t fltSig);
		~LightingSync();

		void printModule();
};
#endif // LIGHTING_H
