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
	div_count = 16;
	div_height = 6;
	radius = 200;
	height = 2200;
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

	Range<FLOAT_SMALL, pad_int> rangeuv0;

	rangeuv0.LowerLimit = 0;
	rangeuv0.UpperLimit = 1;

	float circumference = 2 * 3.1415926f * radius;
	float aspect = height / circumference;

	float theight = aspect;
	float twidth = 1;

	float offset = 0;
	if (aspect > 1)
	{
		theight = 1;
		twidth = 1 / aspect;
		offset = (1 - (rangeuv0.Interpolate(1) * twidth) / 2) - 0.5f;
	}

	for (auto i = 0; i < div_count; i++)
	{
		FLOAT_SMALL t = static_cast<float>(i) / static_cast<float>(div_count);
		FLOAT_SMALL t1 = static_cast<float>(i + 1) / static_cast<float>(div_count);

		Patch_Divide_Parallel<PolyCombiner_Patch> *patch(new Patch_Divide_Parallel<PolyCombiner_Patch>());

		patch->SetPolyCombiner(poly_combiner);
		patch->SetSurfaceCoordinates(i);


		patch->SetBoundPoints(spin0->GetPoint(i), spin0->GetPoint(i + 1), spin1->GetPoint(i), spin1->GetPoint(i + 1));

		auto uv0 = QVector3D(rangeuv0.Interpolate(t ) * twidth + offset, 0, 0);
		auto uv1 = QVector3D(rangeuv0.Interpolate(t1) * twidth + offset, 0, 0);
		auto uv2 = QVector3D(rangeuv0.Interpolate(t ) * twidth + offset, theight, 0);
		auto uv3 = QVector3D(rangeuv0.Interpolate(t1) * twidth + offset, theight, 0);

		patch->Set_UV_BoundPoints(uv0, uv1, uv2, uv3);

		patch->Create(div_height);

		patches.push_back(patch);
	}

	vertices = geometry_manager->GetVertices();
	faces = geometry_manager->GetFaces();
	uv_vertices = geometry_manager->GetUVVertices();
}
