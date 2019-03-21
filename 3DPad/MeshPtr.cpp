#include "stdafx.h"
#include "MeshPtr.h"

MeshPtr::MeshPtr(QObject *parent)
	: QObject(parent)
{
}

MeshPtr::~MeshPtr()
{
}

bool MeshPtr::HasError()
{
	return error;
}

size_t MeshPtr::GetSize()
{
	size = vertices.size() * sizeof(QVector3D) + faces.size() * sizeof(Face4<pad_int>) + normals.size() * sizeof(QVector3D);
	return size;
}
