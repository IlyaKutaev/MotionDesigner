#pragma once

#include <QObject>

class OpSmooth : public QObject
{
	Q_OBJECT
public:
	int divisions_count = 8;
public:
	OpSmooth(QObject *parent);
	~OpSmooth();
public:
	int More(int times);
};
