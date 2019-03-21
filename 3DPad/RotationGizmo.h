#pragma once

#include <QObject>

class RotationGizmo : public QObject
{
	Q_OBJECT

public:
	RotationGizmo(QObject *parent);
	~RotationGizmo();
};
