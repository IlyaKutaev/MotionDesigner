#pragma once

#include <QObject>

class Preferences : public QObject
{
	Q_OBJECT

public:
	Preferences(QObject *parent);
	~Preferences();
};
