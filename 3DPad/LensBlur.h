#pragma once

#include <QObject>

class LensBlur : public QObject
{
	Q_OBJECT

public:
	LensBlur(QObject *parent);
	~LensBlur();
};
