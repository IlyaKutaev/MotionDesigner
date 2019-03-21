#include "stdafx.h"
#include "Cylinder.h"
#include <MeshGeometryManager.h>
#include <Patch_Divide_Parallel.h>
#include <VertexType.h>
#include <OpSpin.h>
#include <PolyCombiner_Patch.h>

using namespace std;

Cylinder::Cylinder(QObject *parent)
	: QObject(parent)
{
}

Cylinder::~Cylinder()
{
}

void Cylinder::SetRecommendedParameters()
{
	div_count = 8;
	div_height = 5;
	radius = 25;
	height = 100;
	radius_vector = QVector3D(0, 0, 200);
}

void Cylinder::Create()
{
	PolyCombiner_Patch *poly_combiner(new PolyCombiner_Patch());

	vector<Patch_Divide_Parallel<PolyCombiner_Patch> *> patches;

	OpSpin *spin0(new OpSpin(this));
	OpSpin *spin1(new OpSpin(this));

	const QVector3D cylinder_pivot;

	spin0->SetAllParameters(radius, QVector3D(0, 1, 0), div_count, 0, 360, cylinder_pivot, cylinder_pivot + radius_vector);
	spin1->SetAllParameters(radius, QVector3D(0, 1, 0), div_count, 0, 360, cylinder_pivot + QVector3D(0, height, 0), cylinder_pivot + QVector3D(0, height, 0) + radius_vector);

	auto geometry_manager(poly_combiner->geometry_manager);

	geometry_manager->SetSurfaceRange(div_count);

	for (auto i = 0; i < div_count; i++)
	{
		Patch_Divide_Parallel<PolyCombiner_Patch> *patch(new Patch_Divide_Parallel<PolyCombiner_Patch>());

		patch->SetPolyCombiner(poly_combiner);
		patch->SetSurfaceCoordinates(i);

		patch->SetBoundPoints(spin0->GetPoint(i), spin0->GetPoint(i + 1), spin1->GetPoint(i), spin1->GetPoint(i + 1));

		patch->Create(div_height);

		patches.push_back(patch);
	}

	vertices = geometry_manager->GetVertices();
	faces = geometry_manager->GetFaces();
}
