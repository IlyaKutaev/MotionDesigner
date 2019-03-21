#pragma once

#include <QObject>

class Blur : public QObject
{
	Q_OBJECT

public:
	Blur(QObject *parent);
	~Blur();
};
