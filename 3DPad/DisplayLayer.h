#pragma once

#include <QObject>

class DisplayLayer : public QObject
{
	Q_OBJECT

public:
	DisplayLayer(QObject *parent);
	~DisplayLayer();
};
