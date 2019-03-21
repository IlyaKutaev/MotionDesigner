// This is an independent project of an individual developer. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "stdafx.h"
#include "PolyCombiner_Patch.h"

PolyCombiner_Patch::PolyCombiner_Patch() :
	IPolyCombiner<MeshGeometryManager>()
{

}

PolyCombiner_Patch::~PolyCombiner_Patch()
{

}

void PolyCombiner_Patch::CombineEdges(QUuid edgeid0, QUuid edgeid1)
{
	auto iter0 = IPolyCombiner::geometry_manager->GetEdge(edgeid0);
	if (IPolyCombiner::geometry_manager->find_error) return;
	auto iter1 = IPolyCombiner::geometry_manager->GetEdge(edgeid1);
	if (IPolyCombiner::geometry_manager->find_error) return;

	auto hash = iter0->second.edge_twin_hash;
	iter0->second.edge_twin_hash = iter1->second.edge_twin_hash;
	iter1->second.edge_twin_hash = hash;
}

int PolyCombiner_Patch::GetIndexFor2DSurface(pad_int parent_index, pad_int chlid_index)
{
	return IPolyCombiner::geometry_manager->Create_Indexed_Vertex_For_2D_Surface(parent_index, chlid_index);
}

void PolyCombiner_Patch::AddFace(Face4<pad_int> face)
{
	IPolyCombiner::geometry_manager->AddFace(face);
}

int PolyCombiner_Patch::SetVertexPosition(pad_int parent_id, pad_int child_id, QVector3D position)
{
	return IPolyCombiner::geometry_manager->SetVertexPosition(parent_id,child_id, position);
}

int PolyCombiner_Patch::SetVertexNormal(pad_int parent_id, pad_int child_id, QVector3D normal)
{
	return IPolyCombiner::geometry_manager->SetVertexNormal(parent_id, child_id, normal);
}

int PolyCombiner_Patch::SetVertexUV(pad_int parent_id, pad_int child_id, QVector3D uv)
{
	return IPolyCombiner::geometry_manager->SetVertexUV(parent_id, child_id, uv);
}
