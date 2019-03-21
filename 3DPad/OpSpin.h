#pragma once

#include <QObject>
#include <Pad_Numeric.h>
#include <QVector3D>
#include <VertexType.h>

class OpSpin : public QObject
{
	Q_OBJECT
public:
private:
	FLOAT_SMALL radius = 0;
	QVector3D center;
	QVector3D axis;
	QVector3D start_point;
	pad_int m_div_count = 6;
	FLOAT_SMALL start_angle = 0;
	FLOAT_SMALL end_angle = 360;
public:
	OpSpin(QObject *parent);
	~OpSpin();
public:
	void SetRadius(FLOAT_SMALL arg_radius);
	void SetAxis(QVector3D arg_axis);
	void SetAxis2(QVector3D arg_axis);
	void SetDivCount(pad_int arg_div_count);
	void SetStartAngle(FLOAT_SMALL arg_angle);
	void SetEndAngle(FLOAT_SMALL arg_angle);
	void SetCenter(QVector3D arg_center);
	void SetAllParameters(FLOAT_SMALL arg_radius,
		QVector3D arg_axis,
		pad_int arg_div_count,
		FLOAT_SMALL arg_start_angle,
		FLOAT_SMALL arg_end_angle,
		QVector3D arg_center,
		QVector3D arg_start_point);
	QVector3D GetPoint(int point_index);
};
