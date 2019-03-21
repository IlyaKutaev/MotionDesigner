#pragma once

#include <QObject>

class MeshManager : public QObject
{
	Q_OBJECT

public:
	MeshManager(QObject *parent);
	~MeshManager();
};
