#pragma once

#include <QObject>

class Spin : public QObject
{
	Q_OBJECT

public:
	Spin(QObject *parent);
	~Spin();
};
