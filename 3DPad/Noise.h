#pragma once

#include <QObject>

class Noise : public QObject
{
	Q_OBJECT

public:
	Noise(QObject *parent);
	~Noise();
};
