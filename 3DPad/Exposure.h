#pragma once

#include <QObject>

class Exposure : public QObject
{
	Q_OBJECT

public:
	Exposure(QObject *parent);
	~Exposure();
};
