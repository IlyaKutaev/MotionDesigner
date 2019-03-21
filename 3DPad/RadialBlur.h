#pragma once

#include <QObject>

class RadialBlur : public QObject
{
	Q_OBJECT

public:
	RadialBlur(QObject *parent);
	~RadialBlur();
};
