#pragma once

#include <QObject>

class Checker : public QObject
{
	Q_OBJECT

public:
	Checker(QObject *parent);
	~Checker();
};
