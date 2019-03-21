#pragma once

#include <QObject>

class UnsharpMask : public QObject
{
	Q_OBJECT

public:
	UnsharpMask(QObject *parent);
	~UnsharpMask();
};
