#pragma once

#include <QObject>

class Hotkeys : public QObject
{
	Q_OBJECT

public:
	Hotkeys(QObject *parent);
	~Hotkeys();
};
