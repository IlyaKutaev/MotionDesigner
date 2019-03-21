#pragma once

#include <QObject>

class Box : public QObject
{
	Q_OBJECT

public:
	Box(QObject *parent);
	~Box();
};
