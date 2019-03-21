#pragma once

#include <QObject>

class Outline : public QObject
{
	Q_OBJECT

public:
	Outline(QObject *parent);
	~Outline();
};
