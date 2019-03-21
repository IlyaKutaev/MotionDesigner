#include "stdafx.h"
#include "Range3D.h"
#include <Range.h>

Range3D::Range3D(QObject *parent)
	: QObject(parent)
{
	using namespace std;
	rangex = new Range<FLOAT_SMALL, pad_int>();
	rangey = new Range<FLOAT_SMALL, pad_int>();
	rangez = new Range<FLOAT_SMALL, pad_int>();
}

Range3D::Range3D() :
	Range3D(nullptr)
{

}

Range3D::~Range3D()
{
	delete rangex;
	delete rangey;
	delete rangez;
}

void Range3D::SetStart(QVector3D arg_start)
{
	rangex->LowerLimit = arg_start.x();
	rangey->LowerLimit = arg_start.y();
	rangez->LowerLimit = arg_start.z();
}

void Range3D::SetFinish(QVector3D arg_finish)
{
	rangex->UpperLimit = arg_finish.x();
	rangey->UpperLimit = arg_finish.y();
	rangez->UpperLimit = arg_finish.z();
}

QVector3D Range3D::Interpolate(FLOAT_SMALL parameter)
{
	QVector3D result;

	result.setX(rangex->Interpolate(parameter));
	result.setY(rangey->Interpolate(parameter));
	result.setZ(rangez->Interpolate(parameter));

	return result;
}
