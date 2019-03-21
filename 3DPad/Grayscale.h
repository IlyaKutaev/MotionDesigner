#pragma once

#include <QObject>

class Grayscale : public QObject
{
	Q_OBJECT

public:
	Grayscale(QObject *parent);
	~Grayscale();
};
