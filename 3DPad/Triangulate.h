#pragma once

#include <QObject>

class Triangulate : public QObject
{
	Q_OBJECT

public:
	Triangulate(QObject *parent);
	~Triangulate();
};
