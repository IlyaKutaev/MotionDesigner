#pragma once

#include <QObject>

class ResetTransform : public QObject
{
	Q_OBJECT

public:
	ResetTransform(QObject *parent);
	~ResetTransform();
};
