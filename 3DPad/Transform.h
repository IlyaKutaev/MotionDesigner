#ifndef IncludeGuard_3DPad_Transform
#define IncludeGuard_3DPad_Transform

#include <QObject>
#include <QQuaternion>
#include <QVector3D>
#include "_3DPad_Common.h"

class Transform : public QObject
{
	Q_OBJECT
public:
	Q_PROPERTY(QVector3D  Position READ  GetPosition WRITE SetPosition)
	Q_PROPERTY(QQuaternion  Orientation READ GetOrientation WRITE SetOrientation)
	Q_PROPERTY(QVector3D  Scale READ GetScale WRITE SetScale)
	Q_PROPERTY(padid  TargetNodeID READ  GetTargetID WRITE SetTargetID)
	Q_PROPERTY(padid  AimNodeID READ  GetAimID WRITE SetAimID)
private:
	QVector3D Position;
	QQuaternion Orientation;
	QVector3D Scale;
	padid TargetNodeID;
	padid AimNodeID;
public:
	QVector3D GetPosition()
	{
		return Position;
	}
	QQuaternion GetOrientation()
	{
		return Orientation;
	}
	QVector3D GetScale()
	{
		return Scale;
	}
	padid GetTargetID()
	{
		return TargetNodeID;
	}
	padid GetAimID()
	{
		return AimNodeID;
	}
public:
	void SetPosition(QVector3D Pos)
	{
		Position = Pos;
	}
	void SetOrientation(QQuaternion orient)
	{
		Orientation = Orientation;
	}
	void SetScale(QVector3D scale)
	{
		Scale = scale;
	}
	void SetTargetID(padid id)
	{
		TargetNodeID = id;
	}
	void SetAimID(padid id)
	{
		AimNodeID = id;
	}
private:

};

#endif // ZTRANSFORM_H
