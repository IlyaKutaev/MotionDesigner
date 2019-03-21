// This is an independent project of an individual developer. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "stdafx.h"
#include "Position.h"
#include "SharedNodeProperties.h"

Position::Position(QObject *parent)
	: QObject(parent)
{
	properties = new SharedNodeProperties(this);
}

Position::~Position()
{
}

void Position::SetParent(Position *parent_)
{
	parent = parent_;
}

Position * Position::GetParent()
{
	return parent;
}

void Position::AddToChildren(Position *newchild)
{
	children << newchild;
}

void Position::Connect(Position *newparent, Position *newchild)
{
	newchild->SetParent(newparent);
	newparent->AddToChildren(newchild);
}

void Position::Detach()
{
	parent = nullptr;
}

void Position::RotateX(float angle)
{
	rot_x += angle;
}

void Position::RotateX(double angle)
{
	rot_x += angle;
}

void Position::RotateY(float angle)
{
	rot_y += angle;
}

void Position::RotateY(double angle)
{
	rot_y += angle;
}

void Position::RotateZ(float angle)
{
	rot_z += angle;
}

void Position::RotateZ(double angle)
{
	rot_z += angle;
}

void Position::Rotate(float x, float y, float z)
{
	rot_x += x;
	rot_y += y;
	rot_z += z;
}

void Position::Rotate(double x, double y, double z)
{
	rot_x += x;
	rot_y += y;
	rot_z += z;
}

void Position::SetRotationOrder(RotationOrder order)
{
	rotation_order = order;
}

float Position::GetRotationX()
{
	return rot_x;
}

float Position::GetRotationY()
{
	return rot_y;
}

float Position::GetRotationZ()
{
	return rot_z;
}

void Position::SetPosition(QVector3D position_)
{
	position = position_;
}

void Position::SetPosition(float x, float y, float z)
{
	position = QVector3D(x, y, z);
}

void Position::SetPosition(double x, double y, double z)
{
	position = QVector3D(x, y, z);
}

QVector3D Position::GetPosition()
{
	return position;
}

void Position::Move(float x, float y, float z)
{
	position += QVector3D(x, y, z);
}

void Position::Move(double x, double y, double z)
{
	position += QVector3D(x, y, z);
}

void Position::Move(QVector3D distance)
{
	position += distance;
}

void Position::SetScale(float x, float y, float z)
{
	scale = QVector3D(x, y, z);
}

void Position::SetScale(double x, double y, double z)
{
	scale = QVector3D(x, y, z);
}

void Position::SetScale(QVector3D amount)
{
	scale = amount;
}

void Position::Scale(float x, float y, float z)
{
	scale = QVector3D(scale.x() * x, scale.y() * y, scale.z() * z);
}

void Position::Scale(double x, double y, double z)
{
	scale = QVector3D(scale.x() * x, scale.y() * y, scale.z() * z);
}

void Position::Scale(QVector3D amount)
{
	scale = QVector3D(scale.x() * amount.x(), scale.y() * amount.y(), scale.z() * amount.z());
}

QVector3D Position::GetScale()
{
	return scale;
}

void Position::EnableNode(bool yes)
{
	properties->node_state = (yes ? SharedNodeProperties::NodeState::normal : SharedNodeProperties::NodeState::disabled);
}

bool Position::IsEnabled()
{
	return (properties->node_state == SharedNodeProperties::normal ? true : false);
}

QUuid Position::GetGuid()
{
	return (properties->guid);
}

void Position::Rename(QString name_)
{
	properties->name = name_;
}

QString Position::GetName()
{
	return properties->name;
}

void Position::Update()
{
	if (properties->name.compare("cam_spin0") == 0 && abs(rot_x) > 2) 
	{
		int stop = 0;
	}
	if (!parent)
	{
		world_matrix.setToIdentity();
	}
	else
	{
		world_matrix.setToIdentity();
		world_matrix.scale(scale);
		QQuaternion rotx = QQuaternion::fromAxisAndAngle(1, 0, 0, rot_x);
		QQuaternion roty = QQuaternion::fromAxisAndAngle(0, 1, 0, rot_y);
		QQuaternion rotz = QQuaternion::fromAxisAndAngle(0, 0, 1, rot_z);

		QQuaternion rot;
		switch (rotation_order)
		{
		case xyz:
			rot = rotx * roty * rotz;
			break;
		case xzy:
			rot = rotx * rotz * roty;
			break;
		case yxz:
			rot = roty * rotx * rotz;
			break;
		case yzx:
			rot = roty * rotz * rotx;
			break;
		case zxy:
			rot = rotz * rotx * roty;
			break;
		case  zyx:
			rot = rotz * roty * rotx;
			break;
		}

		world_matrix.rotate(rot);
		world_matrix.translate(position);

		derived_matrix = parent->derived_matrix * world_matrix;
	}

	for (auto &it : children)
	{
		it->Update();
	}
}
