#pragma once

#include <QObject>

class DirectLight : public QObject
{
	Q_OBJECT

public:
	DirectLight(QObject *parent);
	~DirectLight();
};
