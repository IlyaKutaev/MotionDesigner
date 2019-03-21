#pragma once

#include <QObject>

class ColorBalance : public QObject
{
	Q_OBJECT

public:
	ColorBalance(QObject *parent);
	~ColorBalance();
};
