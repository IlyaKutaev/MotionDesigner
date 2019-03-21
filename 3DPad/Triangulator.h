#pragma once

#include <QObject>

class Triangulator : public QObject
{
	Q_OBJECT

public:
	Triangulator(QObject *parent);
	~Triangulator();
};
