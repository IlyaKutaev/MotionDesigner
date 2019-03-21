#pragma once

#include <QObject>

class SpotLight : public QObject
{
	Q_OBJECT

public:
	SpotLight(QObject *parent);
	~SpotLight();
};
