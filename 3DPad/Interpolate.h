#pragma once

#include <QObject>

class Interpolate : public QObject
{
	Q_OBJECT

public:
	Interpolate(QObject *parent);
	~Interpolate();
};
