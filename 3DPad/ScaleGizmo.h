#pragma once

#include <QObject>

class ScaleGizmo : public QObject
{
	Q_OBJECT

public:
	ScaleGizmo(QObject *parent);
	~ScaleGizmo();
};
