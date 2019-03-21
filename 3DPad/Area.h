#pragma once

#include <QObject>

class Area : public QObject
{
	Q_OBJECT

public:
	Area(QObject *parent);
	~Area();
};
