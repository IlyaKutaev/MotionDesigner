#include <stdafx.h>
#include "MeshGeometryManager.h"

MeshGeometryManager::MeshGeometryManager()
{
	edges.reserve(ContainerStartupCapacity::capacity_optimal);
}


MeshGeometryManager::~MeshGeometryManager()
{
}

std::string MeshGeometryManager::IDHash(QUuid id)
{
	return id.toString().toStdString();
}

MeshGeometryManager::EdgesMap::iterator MeshGeometryManager::GetEdge(QUuid edgeid)
{
	find_error = false;
	using namespace std;

	auto iter = edges.find(edgeid.toString().toStdString());

	if (iter == edges.end()) 
	{
		find_error = true;
	}

	return iter;
}

pad_int MeshGeometryManager::Create_Indexed_Vertex_For_2D_Surface(pad_int parent_id, pad_int child_id)
{
	if (patch_parent_id > surface_range_upper - 1)
	{
		patch_parent_id = 0;
	}
	const auto index = (patch_parent_id + 1) * CommonDivisions::div_primitive_maximum + child_id;

	auto iter = map_vertices.find(index);

	if (iter == map_vertices.end())
	{
		Vertex<pad_int> vertex;
		vertex.vertex_id = free_index++;
		map_vertices.insert(std::make_pair(index, vertex));
		used_indicies.push_back(index);
		return vertex.vertex_id;
	}

	auto vertex = iter->second;
	return vertex.vertex_id;
}

int MeshGeometryManager::SetVertexPosition(pad_int parent_id, pad_int child_id, QVector3D position)
{
	patch_parent_id = parent_id;
	int index = Create_Indexed_Vertex_For_2D_Surface(patch_parent_id, child_id);
	auto iter = map_vertices.find((patch_parent_id  + 1)* CommonDivisions::div_primitive_maximum + child_id);
	if (iter == map_vertices.end()) return -1;

	iter->second.setPosition(position);

	return index;
}

int MeshGeometryManager::SetVertexNormal(pad_int parent_id, pad_int child_id, QVector3D normal)
{
	patch_parent_id = parent_id;
	int index = Create_Indexed_Vertex_For_2D_Surface(patch_parent_id, child_id);
	auto iter = map_vertices.find((patch_parent_id + 1)* CommonDivisions::div_primitive_maximum + child_id);
	if (iter == map_vertices.end()) return -1;

	auto normalold = iter->second.GetNormal();

	auto norm = (normalold + normal).normalized();
	iter->second.SetNormal(norm);

	return index;
}

int MeshGeometryManager::SetVertexUV(pad_int parent_id, pad_int child_id, QVector3D uv)
{
	patch_parent_id = parent_id;
	int index = Create_Indexed_Vertex_For_2D_Surface(patch_parent_id, child_id);
	auto iter = map_vertices.find((patch_parent_id + 1)* CommonDivisions::div_primitive_maximum + child_id);
	if (iter == map_vertices.end()) return -1;

	iter->second.SetUV(uv);

	return index;
}

std::vector<Vertex<pad_int>> MeshGeometryManager::GetVertices()
{
	if (!vertices.empty()) return vertices;

	for (auto &index : used_indicies)
	{
		Vertex<pad_int> vertex;
		auto iter = map_vertices.find(index);

		vertex.vertex_id = iter->second.vertex_id;
		vertex.setPosition(iter->second.GetPosition());
		vertex.SetNormal(iter->second.GetNormal());
		vertices.push_back(vertex);
	}

	return vertices;
}

void MeshGeometryManager::AddFace(Face4<pad_int> face)
{
	faces.push_back(face);
}

std::vector<Face4<pad_int>> MeshGeometryManager::GetFaces()
{
	return faces;
}

void MeshGeometryManager::SetSurfaceRange(int arg_range)
{
	surface_range_upper = arg_range;
}

