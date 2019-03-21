#pragma once

#include <QObject>

class Lambert : public QObject
{
	Q_OBJECT

public:
	Lambert(QObject *parent);
	~Lambert();
};
