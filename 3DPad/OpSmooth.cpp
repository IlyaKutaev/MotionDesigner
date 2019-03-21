#include "stdafx.h"
#include "OpSmooth.h"

OpSmooth::OpSmooth(QObject *parent)
	: QObject(parent)
{
}

OpSmooth::~OpSmooth()
{
}

int OpSmooth::More(int times)
{
	for (int i = 0; i < times; i++)
	{
		divisions_count *= (sqrt(2.0f));
	}
	return divisions_count;
}
