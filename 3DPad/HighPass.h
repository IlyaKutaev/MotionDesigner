#pragma once

#include <QObject>

class HighPass : public QObject
{
	Q_OBJECT

public:
	HighPass(QObject *parent);
	~HighPass();
};
