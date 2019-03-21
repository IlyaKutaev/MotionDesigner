#pragma once

#include <QObject>

class PositionGizmo : public QObject
{
	Q_OBJECT

public:
	PositionGizmo(QObject *parent);
	~PositionGizmo();
};
