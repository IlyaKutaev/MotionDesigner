#pragma once

#include <QObject>

class Measure : public QObject
{
	Q_OBJECT

public:
	Measure(QObject *parent);
	~Measure();
};
