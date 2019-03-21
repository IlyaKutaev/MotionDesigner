#pragma once

#include <QObject>

class Squash : public QObject
{
	Q_OBJECT

public:
	Squash(QObject *parent);
	~Squash();
};
