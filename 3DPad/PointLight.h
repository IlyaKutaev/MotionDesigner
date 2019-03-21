#pragma once

#include <QObject>

class PointLight : public QObject
{
	Q_OBJECT

public:
	PointLight(QObject *parent);
	~PointLight();
};
