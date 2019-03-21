#pragma once

#include <QObject>

class Remap : public QObject
{
	Q_OBJECT

public:
	Remap(QObject *parent);
	~Remap();
};
