#pragma once

#include <QObject>
#include <Pad_Numeric.h>
#include <VertexType.h>
#include <memory.h>

template <typename RangeType, typename RangeIntType>
class Range;

class Range3D : public QObject
{
	Q_OBJECT
private:
	Range<FLOAT_SMALL, pad_int> *rangex = nullptr;
	Range<FLOAT_SMALL, pad_int> *rangey = nullptr;
	Range<FLOAT_SMALL, pad_int> *rangez = nullptr;
public:
	Range3D();
	Range3D(QObject *parent);
	~Range3D();
public:
	void SetStart(QVector3D arg_start);
	void SetFinish(QVector3D arg_finish);
	QVector3D Interpolate(FLOAT_SMALL parameter);
};
