#pragma once

#include <QObject>

class Gradient : public QObject
{
	Q_OBJECT

public:
	Gradient(QObject *parent);
	~Gradient();
};
