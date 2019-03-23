#pragma once

#include <QObject>
#include <vector>
#include <VertexType.h>
#include <Pad_Numeric.h>

class Cylinder : public QObject
{
	Q_OBJECT
public:
	std::vector<Vertex<pad_int>> vertices;
	std::vector<Face4<pad_int>> faces;
	std::vector<UVVertex> uv_vertices;

	pad_int div_count = 0;
	pad_int div_height = 2;
	FLOAT_SMALL radius = 0;
	FLOAT_SMALL height = 0;;
	QVector3D radius_vector;
public:
	Cylinder(QObject *parent);
	~Cylinder();
public:
	void SetRecommendedParameters();
	void Create();
};
