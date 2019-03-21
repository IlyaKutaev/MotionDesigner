#pragma once

#include <QObject>

class Displace : public QObject
{
	Q_OBJECT

public:
	Displace(QObject *parent);
	~Displace();
};
