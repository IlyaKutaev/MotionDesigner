#pragma once

#include <QObject>
#include <QtGlobal>
#include <Pad_Numeric.h>
#include <VertexType.h>

class MeshPtr : public QObject
{
	Q_OBJECT
public:
	std::vector<QVector3D>	vertices;
	std::vector<Face4<pad_int>> faces;
	std::vector<QVector3D> normals;
private:
	bool error = false;
	size_t size = 0;
public:
	MeshPtr(QObject *parent);
	~MeshPtr();
public:
	bool HasError();
	size_t GetSize();
};
