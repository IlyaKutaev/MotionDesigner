// This is an independent project of an individual developer. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "stdafx.h"
#include "OpSpin.h"

OpSpin::OpSpin(QObject *parent)
	: QObject(parent)
{
}

OpSpin::~OpSpin()
{
}

void OpSpin::SetRadius(FLOAT_SMALL arg_radius)
{
	radius = arg_radius;
}

void OpSpin::SetAxis(QVector3D arg_axis)
{
	axis = arg_axis;
}

void OpSpin::SetAxis2(QVector3D arg_axis)
{
	start_point = arg_axis;
}

void OpSpin::SetDivCount(pad_int arg_div_count)
{
	m_div_count = arg_div_count;
}

void OpSpin::SetStartAngle(FLOAT_SMALL arg_angle)
{
	start_angle = arg_angle;
}

void OpSpin::SetEndAngle(FLOAT_SMALL arg_angle)
{
	end_angle = arg_angle;
}

void OpSpin::SetCenter(QVector3D arg_center)
{
	center = arg_center;
}

void OpSpin::SetAllParameters(FLOAT_SMALL arg_radius, QVector3D arg_axis, pad_int arg_div_count, FLOAT_SMALL arg_start_angle, FLOAT_SMALL arg_end_angle, QVector3D arg_center, QVector3D arg_axis2)
{
	radius = arg_radius;
	axis = arg_axis;
	m_div_count = arg_div_count;
	start_angle = arg_start_angle;
	end_angle = arg_end_angle;
	center = arg_center;
	start_point = arg_axis2;
}

QVector3D OpSpin::GetPoint(int point_index)
{
	QQuaternion rot = QQuaternion::fromAxisAndAngle(axis, start_angle + (end_angle - start_angle) * (static_cast<float>(point_index) / m_div_count));

	QVector3D point = rot.rotatedVector((start_point - center).normalized() * radius) + center;

	return point;
}
