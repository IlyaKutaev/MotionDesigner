#pragma once

#include <QObject>
#include <d3d11_1.h>

class Position;

class Mesh : public QObject
{
	Q_OBJECT
public:
#pragma pack(push, 1)
	struct VertexType
	{
		float x = 0;
		float y = 0;
		float z = 0;
		float r = 0;
		float g = 0;
		float b = 0;
		float a = 0;
		VertexType(float xx, float yy, float zz, float rr, float gg, float bb, float aa) :
			x(xx), y(yy), z(zz), r(rr), g(gg), b(bb), a(aa)
		{}
		VertexType() {}
	};
#pragma pack(pop)
//	D3D11_PRIMITIVE_TOPOLOGY topology = D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
	Position *parent_node = nullptr;

private:
	int index_count = 0;
public:
public:
	Mesh(QObject *parent);
	~Mesh();
// 	bool InitializeBuffers(ID3D11Device* device);
// 	int GetIndexCount();
};
