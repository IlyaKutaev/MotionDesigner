// This is an independent project of an individual developer. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "stdafx.h"
#include "Export.h"
# include <cstdlib>
# include <iostream>
# include <fstream>
# include <iomanip>
# include <cmath>
# include <ctime>
# include <cstring>
# include <Cylinder.h>
#include <FreeMemory.h>
#include <OpSmooth.h>
#include <Wavefront.h>
#include <MeshPtr.h>
#include <CheckDisk.h>

using namespace std;

Export::Export(QObject *parent)
	: QObject(parent)
{
}

Export::~Export()
{
}

void Export::ExportObject(Data &data)
{
	ofstream output;
	int text_num = 0;
	int vertex = 0;
	double w = 0;


	output.open(data.output_filename.c_str());

	if (!output) return;
	text_num = 0;

	output << "# " << data.output_filename << "\n";
	output << "# created by MotionDesigner I0\n";
	output << "\n";
	output << "g Group001\n";


	if (0 < data.node_num)
	{
		output << "\n";
	}

	w = 1.0;
	for (auto node = 0; node < data.node_num; node++)
	{
		output << "v";
		for (auto i = 0; i < 3; i++)
		{
			output << " " << std::setprecision(10) << data.node_xyz[i + 3 * node];
		}
		output << "\n";
	}
	if (0 < data.normal_num)
	{
		output << "\n";

		for (auto normal = 0; normal < data.normal_num; normal++)
		{
			output << "vn";
			for (auto i = 0; i < 3; i++)
			{
				output << " " << std::setprecision(10) << data.normal_vector[i + normal * 3];
			}
			output << "\n";
		}
	}
	if (0 < data.face_num)
	{
		output << "\n";
	}

	for (auto face = 0; face < data.face_num; face++)
	{
		output << "f";
		for (vertex = 0; vertex < data.face_order[face]; vertex++)
		{
			auto n = data.face_node[vertex + face * data.order_max];
			output << " " << std::setprecision(10) << n;
			if (0 < data.normal_num)
			{
				output << "//" << std::setprecision(10) << data.vertex_normal[vertex + face * data.order_max];
			}
		}
		output << "\n";
	}

	output.close();

}

void Export::ExportObjectNew(MeshPtr *mesh, QString filename)
{
	Wavefront *wavefront = new Wavefront(this);

	wavefront->Export(filename, mesh);

	wavefront->deleteLater();
}

Export::Data Export::SerializePrimitive(std::vector<Vertex<pad_int>> vertices, std::vector<Face4<pad_int>> faces)
{
	vector<int> face_node;
	vector<int> face_order;+
	vector<double> node_xyz;
	vector<double> normal_vector;
	vector<int> vertex_normal_ids;

	auto face_count = 0;
	auto normal_num = 0;
	auto order_max = 0;
	auto verts_count = 0;

	int index_offset = 0;
	int node_xyz_offset = 0;
	int vertex_normal_id = 0;

	vector<int> normal_ids;
	int normal_id = 0;

	const auto faces_count = faces.size();
	const auto vertices_count = vertices.size();
	const auto normals_count = 1;
	const auto max_face_size = 3;

	Data data;

	while (true)
	{
		try {
			for (auto &face : faces)
			{
				face_node.push_back(face.Index(0, 0) + 1);
				face_node.push_back(face.Index(0, 1) + 1);
				face_node.push_back(face.Index(0, 2) + 1);
				face_node.push_back(face.Index(1, 0) + 1);
				face_node.push_back(face.Index(1, 1) + 1);
				face_node.push_back(face.Index(1, 2) + 1);

				vertex_normal_ids.push_back(face.Index(0, 0) + 1);
				vertex_normal_ids.push_back(face.Index(0, 1) + 1);
				vertex_normal_ids.push_back(face.Index(0, 2) + 1);
				vertex_normal_ids.push_back(face.Index(1, 0) + 1);
				vertex_normal_ids.push_back(face.Index(1, 1) + 1);
				vertex_normal_ids.push_back(face.Index(1, 2) + 1);
			}

			break;
		}
		catch (const std::bad_alloc&)
		{
			face_node.clear();
			for (int i = 0; i < 10; i++)
			{
				if (!FreeMemory::Instance().FreeMyMemory())
				{
					data.error = true;
					return data;
				}
			}

			continue;
		}
	}
	face_count += faces_count * 2;
	index_offset += vertices.size();

	for (int i = 0; i < faces_count * 2; i++)
	{
		face_order.push_back(3);
	}
	verts_count += vertices_count;

	while (true)
	{
		try {
			for (auto &vertex : vertices)
			{
				node_xyz.push_back(vertex.position.x);
				node_xyz.push_back(vertex.position.y);
				node_xyz.push_back(vertex.position.z);

				normal_vector.push_back(vertex.normal.x);
				normal_vector.push_back(vertex.normal.y);
				normal_vector.push_back(vertex.normal.z);
			}

			break;
		}
		catch (const std::bad_alloc&)
		{
			node_xyz.clear();
			for (int i = 0; i < 10; i++)
			{
				if (!FreeMemory::Instance().FreeMyMemory())
				{
					data.error = true;
					return data;
				}
			}

			continue;
		}
	}

	order_max = max_face_size;

	data.node_num = verts_count;
	data.face_num = face_count;
	data.normal_num = verts_count;
	data.order_max = order_max;
	data.node_xyz = node_xyz;
	data.face_order = face_order;
	data.face_node = face_node;
	data.normal_vector = normal_vector;
	data.vertex_normal = vertex_normal_ids;

	return data;
}

void Export::Test()
{
#ifndef _DEBUG 
	return;
#endif
	cylinder = new Cylinder(this);
	
	cylinder->SetRecommendedParameters();

	OpSmooth *smooth = new OpSmooth(this);

	smooth->divisions_count = 8;

	cylinder->div_count = smooth->More(3);

	cylinder->Create();

	auto data = SerializePrimitive(cylinder->vertices, cylinder->faces);

	if (data.error) return;

	data.output_filename = "A://Tests//test.obj";

	MeshPtr *ptr = new MeshPtr(this);

	for (auto &vertex : cylinder->vertices)
	{
		ptr->vertices.push_back(vertex.GetPosition());
		ptr->normals.push_back(vertex.GetNormal());
	}

	ptr->faces = cylinder->faces;

	ExportObjectNew(nullptr, "A://Tests//test.obj");
}
