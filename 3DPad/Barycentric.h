#pragma once

#include <QObject>

class Barycentric : public QObject
{
	Q_OBJECT

public:
	Barycentric(QObject *parent);
	~Barycentric();
};
