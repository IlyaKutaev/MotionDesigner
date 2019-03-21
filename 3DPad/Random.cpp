// This is an independent project of an individual developer. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "stdafx.h"
#include "Random.h"

Random::Random(QObject *parent)
	: QObject(parent)
{
	state = new uint64_t();
	*state = 3651614973;
	*state = *state * 174624;
}

Random::~Random()
{
	delete state;
}

uint64_t Random::GetRandomValue()
{
	return xorshift64();
}

uint64_t Random::xorshift64()
{
	uint64_t x = *state;
	x ^= x << 13;
	x ^= x >> 7;
	x ^= x << 17;
	*state = x;
	
	uint64_t v0 = 3651614973;

	return x;

}

