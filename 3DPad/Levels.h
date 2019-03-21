#pragma once

#include <QObject>

class Levels : public QObject
{
	Q_OBJECT

public:
	Levels(QObject *parent);
	~Levels();
};
