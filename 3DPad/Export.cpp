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

void Export::ExportObject(MeshPtr *mesh, QString filename)
{
	Wavefront *wavefront = new Wavefront(this);

	wavefront->Export(filename, mesh);

	wavefront->deleteLater();
}

void Export::Test()
{
#ifndef _DEBUG 
	return;
#endif
	Cylinder* cylinder = new Cylinder(this);
	
	cylinder->SetRecommendedParameters();

	OpSmooth *smooth = new OpSmooth(this);

	cylinder->div_count = smooth->More(2);

	cylinder->Create();

	MeshPtr *ptr = new MeshPtr(this);

	for (auto &vertex : cylinder->vertices)
	{
		ptr->vertices.push_back(vertex.GetPosition());
		ptr->normals.push_back(vertex.GetNormal());
	}
	for (auto &uv : cylinder->uv_vertices)
	{
		ptr->uv_vertices.push_back(uv.GetUV());
	}
	ptr->faces = cylinder->faces;
	
	ExportObject(ptr, "A://Tests//test.obj");
}
