#pragma once

#include <QObject>

class AutoBack : public QObject
{
	Q_OBJECT

public:
	AutoBack(QObject *parent);
	~AutoBack();
};
