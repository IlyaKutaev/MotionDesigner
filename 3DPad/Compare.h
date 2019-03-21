#pragma once

#include <QObject>

class Compare : public QObject
{
	Q_OBJECT

public:
	Compare(QObject *parent);
	~Compare();
};
