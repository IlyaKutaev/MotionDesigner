#pragma once

#include <QObject>

class Distance : public QObject
{
	Q_OBJECT

public:
	Distance(QObject *parent);
	~Distance();
};
