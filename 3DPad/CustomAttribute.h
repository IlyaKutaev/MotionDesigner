#pragma once

#include <QObject>

class CustomAttribute : public QObject
{
	Q_OBJECT

public:
	CustomAttribute(QObject *parent);
	~CustomAttribute();
};
