#pragma once

#include <QObject>
#include <QMatrix4x4>

class SharedNodeProperties;

class Position : public QObject
{
	Q_OBJECT
public:
	enum RotationOrder
	{
		xyz,
		yzx,
		zxy,
		zyx,
		yxz,
		xzy,
		count
	};
	struct RotationLimit
	{
		bool enabled = false;
		double min = 0;
		double max = 0;
	};
	QMatrix4x4 derived_matrix;
private:
	Position *parent = nullptr;
	QVector<Position *> children;
	QMatrix4x4 world_matrix;
	double rot_x = 0, rot_y = 0, rot_z = 0;
	RotationOrder rotation_order = xyz;
	RotationLimit limit_x, limit_y, limit_z;
	QQuaternion orientation;
	QVector3D position;
	QVector3D scale = QVector3D(1, 1, 1);
	SharedNodeProperties *properties = nullptr;
public:
	Position(QObject *parent);
	~Position();
public:
	void SetParent(Position *parent_);
	Position *GetParent();
	void AddToChildren(Position *newchild);
	static void Connect(Position *newparent, Position *newchild);
	void Detach();
	void RotateX(float angle);
	void RotateY(float angle);
	void RotateZ(float angle);
	void Rotate(float x, float y, float z);
	void RotateX(double angle);
	void RotateY(double angle);
	void RotateZ(double angle);
	void Rotate(double x, double y, double z);
	void SetRotationOrder(RotationOrder order);
	float GetRotationX();
	float GetRotationY();
	float GetRotationZ();
	void SetPosition(float x, float y, float z);
	void SetPosition(double x, double y, double z);
	void SetPosition(QVector3D position_);
	QVector3D GetPosition();
	void Move(float x, float y, float z);
	void Move(double x, double y, double z);
	void Move(QVector3D distance);
	void SetScale(float x, float y, float z);
	void SetScale(double x, double y, double z);
	void SetScale(QVector3D amount);
	void Scale(float x, float y, float z);
	void Scale(double x, double y, double z);
	void Scale(QVector3D amount);
	QVector3D GetScale();
	void EnableNode(bool yes);
	bool IsEnabled();
	QUuid GetGuid();
	void Rename(QString name_);
	QString GetName();
	void Update();
};
