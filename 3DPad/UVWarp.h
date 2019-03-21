#pragma once

#include <QObject>

class UVWarp : public QObject
{
	Q_OBJECT

public:
	UVWarp(QObject *parent);
	~UVWarp();
};
