#pragma once

#include <QObject>

class Spline : public QObject
{
	Q_OBJECT

public:
	Spline(QObject *parent);
	~Spline();
};
