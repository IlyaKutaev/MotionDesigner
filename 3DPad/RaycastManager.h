#pragma once

#include <QObject>

class RaycastManager : public QObject
{
	Q_OBJECT

public:
	RaycastManager(QObject *parent);
	~RaycastManager();
};
