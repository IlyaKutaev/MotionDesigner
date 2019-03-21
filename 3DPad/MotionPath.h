#pragma once

#include <QObject>

class MotionPath : public QObject
{
	Q_OBJECT

public:
	MotionPath(QObject *parent);
	~MotionPath();
};
