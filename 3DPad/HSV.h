#pragma once

#include <QObject>

class HSV : public QObject
{
	Q_OBJECT

public:
	HSV(QObject *parent);
	~HSV();
};
