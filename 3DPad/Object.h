#pragma once

#include <QObject>

class Object : public QObject
{
	Q_OBJECT

public:
	Object(QObject *parent);
	~Object();
};
