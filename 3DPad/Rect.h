#pragma once

#include <QObject>

class Rect : public QObject
{
	Q_OBJECT

public:
	Rect(QObject *parent);
	~Rect();
};
