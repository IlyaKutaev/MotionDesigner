#pragma once

#include <QObject>

class MotionBlur : public QObject
{
	Q_OBJECT

public:
	MotionBlur(QObject *parent);
	~MotionBlur();
};
