#pragma once

#include <QObject>

class Plane : public QObject
{
	Q_OBJECT

public:
	Plane(QObject *parent);
	~Plane();
};
