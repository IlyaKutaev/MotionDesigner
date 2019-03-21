#pragma once

#include <QObject>

class NormalMap : public QObject
{
	Q_OBJECT

public:
	NormalMap(QObject *parent);
	~NormalMap();
};
