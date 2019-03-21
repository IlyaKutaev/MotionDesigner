#pragma once

#include <QObject>

class FBX : public QObject
{
	Q_OBJECT

public:
	FBX(QObject *parent);
	~FBX();
};
