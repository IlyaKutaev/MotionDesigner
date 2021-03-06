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

	auto range_uv0 = make_unique<Range3D>();
	auto range_uv1 = make_unique<Range3D>();

	range_uv0->SetStart(anchorUV0);
	range_uv0->SetFinish(anchorUV2);
	range_uv1->SetStart(anchorUV1);
	range_uv1->SetFinish(anchorUV3);

	int id = 0;

	typedef Vertex<pad_int> vertex_type;

	int divisions_count_corrected = divisions_count + 1;

	float i1 = 0;

	vertex_type vert;
	vertex_type vert1;

	QVector3D opt_vec = position0->Interpolate(i1);
	QVector3D opt_vec1 = position1->Interpolate(i1);

	QVector3D uv_vec = range_uv0->Interpolate(i1);
	QVector3D uv_vec1 = range_uv1->Interpolate(i1);

	Face4<pad_int> face;

	normal_def_level_0 = QVector3D::crossProduct((anchor1 - anchor0).normalized(), (anchor2 - anchor0).normalized()).normalized();

	normal_def_level_1 = normal_def_level_0;

	vertex_child_id = 0;

	int pos_index0 = poly_combiner->SetVertexPosition(vertex_parent_id, vertex_child_id, opt_vec);
	int norm_index1 = poly_combiner->SetVertexNormal(vertex_parent_id, vertex_child_id, normal_def_level_1);
	int uv_index0 = poly_combiner->SetVertexUV(vertex_parent_id, vertex_child_id, uv_vec);

	face.indicies[ccw_0] = pos_index0;
	face.uv_indicies[ccw_0] = uv_index0;


	int pos_index1 = poly_combiner->SetVertexPosition(vertex_parent_id + 1, vertex_child_id, opt_vec1);
	norm_index1 = poly_combiner->SetVertexNormal(vertex_parent_id + 1, vertex_child_id, normal_def_level_1);
	int uv_index1 = poly_combiner->SetVertexUV(vertex_parent_id + 1, vertex_child_id++, uv_vec1);

	face.indicies[ccw_1] = pos_index1;
	face.uv_indicies[ccw_1] = uv_index1;


	for (auto i = 1; i < divisions_count_corrected - 1; ++i)
	{
		i1 = static_cast<float>(i) / static_cast<float>(divisions_count_corrected - 1);

		QVector3D vec = position0->Interpolate(i1);
		QVector3D uv0 = range_uv0->Interpolate(i1);

		vertex_type vert01;

		vert01 << vec;

		QVector3D pos1 = position1->Interpolate(i1);
		QVector3D uv1 = range_uv1->Interpolate(i1);

		int index0 = poly_combiner->SetVertexPosition(vertex_parent_id, vertex_child_id, vec);
		int index1 = poly_combiner->SetVertexPosition(vertex_parent_id + 1, vertex_child_id, pos1);

		poly_combiner->SetVertexNormal(vertex_parent_id, vertex_child_id, normal_def_level_1);
		poly_combiner->SetVertexNormal(vertex_parent_id + 1, vertex_child_id, normal_def_level_1);

		int uv_index0 = poly_combiner->SetVertexUV(vertex_parent_id, vertex_child_id, uv0);
		int uv_index1 = poly_combiner->SetVertexUV(vertex_parent_id + 1, vertex_child_id++, uv1);

		if (!faces.empty())
		{
			face = faces.at(faces.size() - 1);
		}
		face.indicies[ccw_2] = index0;
		face.indicies[ccw_3] = index1;

		face.uv_indicies[ccw_2] = uv_index0;
		face.uv_indicies[ccw_3] = uv_index1;

		vertex_type vert02;
		vert02 << pos1;

		faces.push_back(face);

		poly_combiner->AddFace(face);

		//--
		Face4<pad_int> face2;

		face2.normal_x = normal_def_level_1.x();
		face2.normal_y = normal_def_level_1.y();
		face2.normal_z = normal_def_level_1.z();

		face2.indicies[ccw_0] = index0;
		face2.indicies[ccw_1] = index1;
		face2.uv_indicies[ccw_0] = uv_index0;
		face2.uv_indicies[ccw_1] = uv_index1;

		faces.push_back(face2);
	}

	Face4<pad_int> face2 = faces.at(faces.size() - 1);

	i1 = static_cast<float>(divisions_count_corrected - 1) / static_cast<float>(divisions_count);

	QVector3D pos1 = position0->Interpolate(i1);
	QVector3D uv1 = range_uv0->Interpolate(i1);
	QVector3D pos2 = position1->Interpolate(i1);
	QVector3D uv2 = range_uv1->Interpolate(i1);

	vertex_type vert01;

	pos_index0 = poly_combiner->SetVertexPosition(vertex_parent_id, vertex_child_id, pos1);
	pos_index1 = poly_combiner->SetVertexPosition(vertex_parent_id + 1, vertex_child_id, pos2);

	norm_index1 = poly_combiner->SetVertexNormal(vertex_parent_id, vertex_child_id, normal_def_level_1);
	norm_index1 = poly_combiner->SetVertexNormal(vertex_parent_id + 1, vertex_child_id, normal_def_level_1);

	uv_index0 = poly_combiner->SetVertexUV(vertex_parent_id, vertex_child_id, uv1);
	uv_index1 = poly_combiner->SetVertexUV(vertex_parent_id + 1, vertex_child_id++, uv2);

	face2.indicies[ccw_2] = pos_index0;
	face2.indicies[ccw_3] = pos_index1;
	face2.uv_indicies[ccw_2] = uv_index0;
	face2.uv_indicies[ccw_3] = uv_index1;

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
