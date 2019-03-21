#pragma once

#include <QObject>

class Tweak : public QObject
{
	Q_OBJECT

public:
	Tweak(QObject *parent);
	~Tweak();
};
