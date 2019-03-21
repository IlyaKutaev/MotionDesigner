#pragma once

#include <QObject>

class Twist : public QObject
{
	Q_OBJECT

public:
	Twist(QObject *parent);
	~Twist();
};
