// This is an independent project of an individual developer. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#ifndef Patch_Divide_Parallel_h__
#define Patch_Divide_Parallel_h__

#pragma once

#include <QObject>
#include <Pad_Numeric.h>
#include <VertexType.h>
#include <Range.h>
#include <vector>
#include <Range3D.h>
#include <memory.h>

template <typename PolyCombiner>
class Patch_Divide_Parallel
{
private:
	typedef Range<FLOAT_BIG, pad_int> range_optimal;
	Vertex<pad_int> vertex0;
	Vertex<pad_int> vertex1;
	Vertex<pad_int> vertex2;
	Vertex<pad_int> vertex3;
	PolyCombiner *poly_combiner = nullptr;

	Range3D *position0 = nullptr;
	Range3D *position1 = nullptr;
public:
	std::vector<Face4<pad_int>> faces;
	//std::vector<Vertex<pad_int>> vertices;
private:
	QVector3D anchor0, anchor1, anchor2, anchor3;
	QVector3D anchorUV0, anchorUV1, anchorUV2, anchorUV3;
	int norm_define_level = 0;
	QVector3D normal_def_level_0;
	QVector3D normal_def_level_1;
	pad_int vertex_parent_id = 0;
	pad_int vertex_child_id = 0;
public:
	explicit Patch_Divide_Parallel();
	explicit Patch_Divide_Parallel(QObject *parent);
	~Patch_Divide_Parallel();
public:
	void SetBoundPoints(QVector3D range0_0, QVector3D range0_1, QVector3D range1_0, QVector3D range1_1);
	void Set_UV_BoundPoints(QVector3D range0_0, QVector3D range0_1, QVector3D range1_0, QVector3D range1_1);
	void Create(pad_int divisions_count);
	int GetNormDefineLevel()
	{
		return norm_define_level;
	}
	QVector3D GetNormal_Level0()
	{
		return normal_def_level_0;
	}
	void SetSurfaceCoordinates(pad_int parent_id);
	void SetPolyCombiner(PolyCombiner *combiner);
private:
	QVector3D Interpolate(range_optimal rangex, range_optimal rangey, range_optimal rangez, FLOAT_SMALL parameter);
};

template <typename PolyCombiner>
QVector3D Patch_Divide_Parallel<PolyCombiner>::Interpolate(range_optimal rangex, range_optimal rangey, range_optimal rangez, FLOAT_SMALL parameter)
{
	QVector3D result;

	result.setX(rangex.Interpolate(i1));
	result.setY(rangey.Interpolate(i1));
	result.setZ(rangez.Interpolate(i1));

	return result;
}

template <typename PolyCombiner>
void Patch_Divide_Parallel<PolyCombiner>::Set_UV_BoundPoints(QVector3D range0_0, QVector3D range0_1, QVector3D range1_0, QVector3D range1_1)
{
	anchorUV0 = range0_0;
	anchorUV1 = range0_1;
	anchorUV2 = range1_0;
	anchorUV3 = range1_1;
}

template <typename PolyCombiner>
void Patch_Divide_Parallel<PolyCombiner>::SetPolyCombiner(PolyCombiner *combiner)
{
	poly_combiner = combiner;
}

template <typename PolyCombiner>
void Patch_Divide_Parallel<PolyCombiner>::SetSurfaceCoordinates(pad_int parent_id)
{
	vertex_parent_id = parent_id;
}

template <typename PolyCombiner>
void Patch_Divide_Parallel<PolyCombiner>::SetBoundPoints(QVector3D range0_0, QVector3D range0_1, QVector3D range1_0, QVector3D range1_1)
{
	anchor0 = range0_0;
	anchor1 = range0_1;
	anchor2 = range1_0;
	anchor3 = range1_1;
}

template <typename PolyCombiner>
Patch_Divide_Parallel<PolyCombiner>::Patch_Divide_Parallel()
{

}

template <typename PolyCombiner>
void Patch_Divide_Parallel<PolyCombiner>::Create(pad_int divisions_count)
{
	auto position0 = make_unique<Range3D>();
	auto position1 = make_unique<Range3D>();

	position0->SetStart(anchor0);
	position0->SetFinish(anchor2);
	position1->SetStart(anchor1);
	position1->SetFinish(anchor3);

	auto uv0 = make_unique<Range3D>();
	auto uv1 = make_unique<Range3D>();

	uv0->SetStart(anchorUV0);
	uv0->SetFinish(anchorUV2);
	uv1->SetStart(anchorUV1);
	uv1->SetFinish(anchorUV3);

	int id = 0;

	typedef Vertex<pad_int> vertex_type;

	int divisions_count_corrected = divisions_count + 1;

	float i1 = 0;

	vertex_type vert;
	vertex_type vert1;

	QVector3D opt_vec = position0->Interpolate(i1);
	QVector3D opt_vec1 = position1->Interpolate(i1);

	Face4<pad_int> face;

	normal_def_level_0 = QVector3D::crossProduct((anchor1 - anchor0).normalized(), (anchor2 - anchor0).normalized()).normalized();

	normal_def_level_1 = normal_def_level_0;

	vertex_child_id = 0;

	int index0 = poly_combiner->SetVertexPosition(vertex_parent_id, vertex_child_id, opt_vec);
	int index2 = poly_combiner->SetVertexNormal(vertex_parent_id, vertex_child_id, normal_def_level_1);

	face.indicies[ccw_0] = index0;

	vert << opt_vec;
	vert1 << opt_vec1;

	int index1 = poly_combiner->SetVertexPosition(vertex_parent_id + 1, vertex_child_id, opt_vec1);

	face.indicies[ccw_1] = index1;
	index2 = poly_combiner->SetVertexNormal(vertex_parent_id + 1, vertex_child_id++, normal_def_level_1);
	faces.push_back(face);

	for (auto i = 1; i < divisions_count_corrected - 1; ++i)
	{
		i1 = static_cast<float>(i) / static_cast<float>(divisions_count);

		QVector3D vec = position0->Interpolate(i1);

		vertex_type vert01;

		vert01 << vec;

		int index0 = poly_combiner->SetVertexPosition(vertex_parent_id, vertex_child_id, vec);
		poly_combiner->SetVertexNormal(vertex_parent_id, vertex_child_id, normal_def_level_1);

		faces[faces.size() - 1].indicies[ccw_2] = index0;

		QVector3D vecb = position1->Interpolate(i1);

		int index1 = poly_combiner->SetVertexPosition(vertex_parent_id + 1, vertex_child_id, vecb);
		poly_combiner->SetVertexNormal(vertex_parent_id + 1, vertex_child_id++, normal_def_level_1);

		vertex_type vert02;
		vert02 << vecb;

		faces[faces.size() - 1].indicies[ccw_3] = index1;

		poly_combiner->AddFace(faces.at(faces.size() - 1));

		int prev1 = id++;

		//--
		Face4<pad_int> face2;

		face2.normal_x = normal_def_level_1.x();
		face2.normal_y = normal_def_level_1.y();
		face2.normal_z = normal_def_level_1.z();

		face2.indicies[ccw_0] = index0;
		face2.indicies[ccw_1] = index1;

		faces.push_back(face2);
	}

	Face4<pad_int> face2 = faces.at(faces.size() - 1);

	i1 = static_cast<float>(divisions_count_corrected - 1) / static_cast<float>(divisions_count);

	QVector3D vec = position0->Interpolate(i1);

	vertex_type vert01;

	index0 = poly_combiner->SetVertexPosition(vertex_parent_id, vertex_child_id, vec);

	vert01 << vec;
	face2.indicies[ccw_2] = index0;


	QVector3D vecb = position1->Interpolate(i1);

	index1 = poly_combiner->SetVertexPosition(vertex_parent_id + 1, vertex_child_id, vecb);

	index2 = poly_combiner->SetVertexNormal(vertex_parent_id, vertex_child_id, normal_def_level_1);
	index2 = poly_combiner->SetVertexNormal(vertex_parent_id + 1, vertex_child_id, normal_def_level_1);

	vertex_type vert02;
	vert02 << vecb;

	face2.indicies[ccw_3] = index1;

	poly_combiner->AddFace(face2);
}

template <typename PolyCombiner>
Patch_Divide_Parallel<PolyCombiner>::~Patch_Divide_Parallel()
{

}

template <typename PolyCombiner>
Patch_Divide_Parallel<PolyCombiner>::Patch_Divide_Parallel(QObject *parent)
{

}

#endif // Patch_Divide_Parallel_h__
