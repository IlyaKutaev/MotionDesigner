#pragma once

#include <QObject>

class Pivot : public QObject
{
	Q_OBJECT

public:
	Pivot(QObject *parent);
	~Pivot();
};
