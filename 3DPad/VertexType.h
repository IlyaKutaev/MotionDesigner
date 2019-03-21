#ifndef VertexType_h__
#define VertexType_h__
#pragma once
#include <vector>

#define PAD_BETA_2019
#define PAD_SAFE
#include "Pad_Numeric.h"
#include <array>
#include <bitset>
#include <QUuid>
#include <QVector>

typedef long double FLOAT_HUGE;
typedef double FLOAT_BIG;
typedef float FLOAT_SMALL;

constexpr auto ccw_0 = 0;
constexpr auto ccw_1 = 1;
constexpr auto ccw_2 = 3;
constexpr auto ccw_3 = 2;

#pragma pack(push, 1)
//////////////////////////////////////////////////////////////////////////
template <typename VectorType, typename WType>
struct Vector
{
	typedef VectorType ft;
	typedef WType wt;
	ft x{}, y{}, z{};
	wt w{};

	explicit Vector() {}
	explicit Vector(VectorType xx, VectorType yy, VectorType, WType ww = 0) :
		x(xx), y(yy), z(zz), w(ww)
	{}
	Vector(const Vector& p)
	{
		x = p.x;
		y = p.y;
		z = p.z;
		w = p.w;
	}
	ft& operator=(const ft& b)
	{
		using namespace std;
		swap(b.x, x);
		swap(b.y, y);
		swap(b.z, z);
		swap(b.w, w);
		return this;
	}
	Vector(Vector&& b)
	{
		using namespace std;
		x(move(b.x));
		y(move(b.y));
		z(move(b.z));
		w(move(b.w));
	}
	Vector& operator=(Vector&& b)
	{
		using namespace std;
		swap(b.x, x);
		swap(b.y, y);
		swap(b.z, z);
		swap(b.w, w);
		return *this;
	}

	inline size_t vertex_size()
	{
		constexr size = 3 * sizeof(VectorType) + sizeof(WType);
		return size;
	}
};
//////////////////////////////////////////////////////////////////////////
typedef Vector<FLOAT_BIG, FLOAT_SMALL> VECTOR_BIG;
typedef Vector<FLOAT_SMALL, FLOAT_SMALL> VECTOR_SMALL;

template <typename VertexIntegerType>
struct Vertex
{
	typedef VertexIntegerType Vertex_Int;

	Vertex_Int vertex_id = 0;
	VECTOR_BIG position;
	VECTOR_SMALL uv_set_0;
#ifdef PAD_BETA_2019
	VECTOR_SMALL uv_set_1;
#endif
	VECTOR_SMALL color;
	VECTOR_BIG normal;
#ifdef PAD_BETA_2019
	VECTOR_BIG tangent;
	VECTOR_BIG binormal;
#endif
	explicit Vertex() {}
	explicit Vertex(VECTOR_BIG arg_position,
		VECTOR_SMALL arg_uv0,
		VECTOR_SMALL arg_color,
		VECTOR_BIG arg_normal) :
		position(arg_position),
		uv_set_0(arg_uv0),
		color(arg_color),
		normal(arg_normal)
	{}
#ifdef PAD_BETA_2019
	explicit Vertex(VECTOR_BIG arg_position,
		VECTOR_SMALL arg_uv0,
		VECTOR_SMALL arg_uv1,
		VECTOR_SMALL arg_color,
		VECTOR_BIG arg_normal,
		VECTOR_BIG arg_tangent,
		VECTOR_BIG arg_binormal) :
		position(arg_position),
		uv_set_0(arg_uv0),
		uv_set_1(arg_uv1),
		color(arg_color),
		normal(arg_normal),
		tangent(arg_tangent),
		binormal(arg_binormal)
	{}
#endif
	Vertex(const Vertex& p)
	{
		auto mx = p.position.x;
		auto my = p.position.y;
		auto mz = p.position.z;
		auto mw = p.position.w;

		auto muv0x = p.uv_set_0.x;
		auto muv0y = p.uv_set_0.y;
		auto muv0z = p.uv_set_0.z;
		auto muv0w = p.uv_set_0.w;

		auto mcolorx = p.color.x;
		auto mcolory = p.color.y;
		auto mcolorz = p.color.z;
		auto mcolorw = p.color.w;

		auto mnx = p.normal.x;
		auto mny = p.normal.y;
		auto mnz = p.normal.z;
		auto mnw = p.normal.w;

		position.x = mx;
		position.y = my;
		position.z = mz;
		position.w = mw;

		uv_set_0.x = muv0x;
		uv_set_0.y = muv0y;
		uv_set_0.z = muv0z;
		uv_set_0.w = muv0w;

		color.x = mcolorx;
		color.y = mcolory;
		color.z = mcolorz;
		color.w = mcolorw;

		normal.x = mnx;
		normal.y = mny;
		normal.z = mnz;
		normal.w = mnw;
#ifdef PAD_BETA_2019
		auto muv1x = p.uv_set_1.x;
		auto muv1y = p.uv_set_1.y;
		auto muv1z = p.uv_set_1.z;
		auto muv1w = p.uv_set_1.w;

		auto mtangentx = p.tangent.x;
		auto mtangenty = p.tangent.y;
		auto mtangentz = p.tangent.z;
		auto mtangetnw = p.tangent.w;

		auto mbnormx = p.binormal.x;
		auto mbnormy = p.binormal.y;
		auto mbnormz = p.binormal.z;
		auto mbnormw = p.binormal.w;

		uv_set_1.x = muv1x;
		uv_set_1.y = muv1y;
		uv_set_1.z = muv1z;
		uv_set_1.w = muv1w;

		tangent.x = mtangentx;
		tangent.y = mtangenty;
		tangent.z = mtangentz;
		tangent.w = mtangetnw;

		binormal.x = mbnormx;
		binormal.y = mbnormy;
		binormal.z = mbnormz;
		binormal.w = mbnormw;
#endif
		vertex_id = p.vertex_id;
	}

	Vertex& operator=(const Vertex& b)
	{
		position.x = b.position.x;
		position.y = b.position.y;
		position.z = b.position.z;
		position.w = b.position.w;

		uv_set_0.x = b.uv_set_0.x;
		uv_set_0.y = b.uv_set_0.y;
		uv_set_0.z = b.uv_set_0.z;
		uv_set_0.w = b.uv_set_0.w;

		color.x = b.color.x;
		color.y = b.color.y;
		color.z = b.color.z;
		color.w = b.color.w;

		normal.x = b.normal.x;
		normal.y = b.normal.y;
		normal.z = b.normal.z;
		normal.w = b.normal.w;

#ifdef PAD_BETA_2019
		uv_set_1.x = b.uv_set_1.x;
		uv_set_1.y = b.uv_set_1.y;
		uv_set_1.z = b.uv_set_1.z;
		uv_set_1.w = b.uv_set_1.w;

		tangent.x = b.tangent.x;
		tangent.y = b.tangent.y;
		tangent.z = b.tangent.z;
		tangent.w = b.tangent.w;

		binormal.x = b.binormal.x;
		binormal.y = b.binormal.y;
		binormal.z = b.binormal.z;
		binormal.w = b.binormal.w;
#endif
		vertex_id = p.vertex_id;

		return *this;
	}
	//////////////////////////////////////////////////////////////////////////
	Vertex(Vertex&& b)
	{
		position.x = b.position.x;
		position.y = b.position.y;
		position.z = b.position.z;
		position.w = b.position.w;

		uv_set_0.x = b.uv_set_0.x;
		uv_set_0.y = b.uv_set_0.y;
		uv_set_0.z = b.uv_set_0.z;
		uv_set_0.w = b.uv_set_0.w;

		color.x = b.color.x;
		color.y = b.color.y;
		color.z = b.color.z;
		color.w = b.color.w;

		normal.x = b.normal.x;
		normal.y = b.normal.y;
		normal.z = b.normal.z;
		normal.w = b.normal.w;

#ifdef PAD_BETA_2019
		uv_set_1.x = b.uv_set_1.x;
		uv_set_1.y = b.uv_set_1.y;
		uv_set_1.z = b.uv_set_1.z;
		uv_set_1.w = b.uv_set_1.w;

		tangent.x = b.tangent.x;
		tangent.y = b.tangent.y;
		tangent.z = b.tangent.z;
		tangent.w = b.tangent.w;

		binormal.x = b.binormal.x;
		binormal.y = b.binormal.y;
		binormal.z = b.binormal.z;
		binormal.w = b.binormal.w;
#endif		
		vertex_id = b.vertex_id;

	}
	Vertex& operator=(Vertex&& b)
	{
		using namespace std;

		swap(position.x, b.position.x);
		swap(position.y, b.position.y);
		swap(position.z, b.position.z);
		swap(position.w, b.position.w);

		swap(uv_set_0.x, b.uv_set_0.x);
		swap(uv_set_0.y, b.uv_set_0.y);
		swap(uv_set_0.z, b.uv_set_0.z);
		swap(uv_set_0.w, b.uv_set_0.w);

		swap(color.x, b.color.x);
		swap(color.y, b.color.y);
		swap(color.z, b.color.z);
		swap(color.w, b.color.w);
		swap(normal.x, b.normal.x);
		swap(normal.y, b.normal.y);
		swap(normal.z, b.normal.z);
		swap(normal.w, b.normal.w);

#ifdef PAD_BETA_2019
		swap(uv_set_1.x, b.uv_set_1.x);
		swap(uv_set_1.y, b.uv_set_1.y);
		swap(uv_set_1.z, b.uv_set_1.z);
		swap(uv_set_1.w, b.uv_set_1.w);
		swap(tangent.x, b.tangent.x);
		swap(tangent.y, b.tangent.y);
		swap(tangent.z, b.tangent.z);
		swap(tangent.w, b.tangent.w);
		swap(binormal.x, b.binormal.x);
		swap(binormal.y, b.binormal.y);
		swap(binormal.z, b.binormal.z);
		swap(binormal.w, b.binormal.w);
#endif
		vertex_id = p.vertex_id;

		return *this;
	}
	bool operator==(const Vertex& b) const
	{
#ifdef PAD_SAFE
		size_t id0 = static_cast<size_t>(vertex_id);
		size_t id1 = static_cast<size_t>(b.vertex_id);
		return (id0 == id1);
#elif
		return vertex_id = b.vertex_id;
#endif			
	}
	bool operator!=(const Vertex& b) const
	{
#ifdef PAD_SAFE
		size_t id0 = static_cast<size_t>(vertex_id);
		size_t id1 = static_cast<size_t>(b.vertex_id);
		return (id0 != id1);
#elif
		return (vertex_id != b.vertex_id)
#endif
	}
	void align(const Vertex& b)
	{
		position = b.position;
	}

	void setPosition(QVector3D pos)
	{
		position.x = pos.x();
		position.y = pos.y();
		position.z = pos.z();
	}
	void SetNormal(QVector3D norm)
	{
		normal.x = norm.x();
		normal.y = norm.y();
		normal.z = norm.z();
	}
	void SetUV(QVector3D uv)
	{
		uv_set_0.x = uv.x();
		uv_set_0.y = uv.y();
		uv_set_0.z = uv.z();
	}
	QVector3D GetNormal()
	{
		return QVector3D(normal.x, normal.y, normal.z);
	}
	void operator<<(QVector3D arg_position)
	{
		position.x = arg_position.x();
		position.y = arg_position.y();
		position.z = arg_position.z();
		position.w = 1.0f;
	}
	
	QVector3D GetPosition()
	{
		return QVector3D(position.x, position.y, position.z);
	}
	QVector3D GetUV(int set)
	{
		return QVector3D(uv_set_0.x(), uv_set_0.y(), uv_set_0.z());
	}
};
//////////////////////////////////////////////////////////////////////////
template <typename FaceIntType>
struct Face16
{
public:
	typedef FaceIntType ft;
	ft face_id = 0;
public:
	std::array<ft, 16> indicies;
	std::bitset<8> control_word;
	char count = 0;
	char start_index = 0;
	explicit Face16()
	{
	}
	explicit Face16(FaceIntType arg_id) :
		face_id(arg_id)
	{
	}
	FaceIntType RandomIndex()
	{
		start_index = rand() % 16;
		return static_cast<FaceIntType>(start_index);
	}
	void AddIndex(FaceIntType index)
	{
		if (count > 15) return;

		indicies[count++] = index;
	}
	FaceIntType TraverceIndicies()
	{
		if (0 == count) return -1;
		start_index = (start_index + 1) % count;
		return start_index;
	}
};
template <typename FaceIntType>
struct Face4
{
public:
	typedef FaceIntType ft;
	ft face_id = 0;
	std::array<ft, 4> indicies;
	FLOAT_SMALL normal_x = 0;
	FLOAT_SMALL normal_y = 0;
	FLOAT_SMALL normal_z = 0;
public:
	//std::bitset<8> flags0;

	Face4()
	{
		indicies.fill(0);
		//flags0.set(0, 1);
	}
	Face4(FaceIntType arg_id) :
		face_id(arg_id)
	{
		indicies.fill(0);
		//flags0.set(0, 1);
	}
	Face16<pad_int> Grow()
	{
		Face16 out;
		out.face_id = face_id;
		for (auto t = 0; t < 4; t++)
		{
			out[t] = indicies[t];
		}
		return out;
	}
	void SwapDiagonal()
	{
		//flags0.flip(0);
	}
public:
	FaceIntType Index(int tri_id, int index_id)
	{
		if (tri_id == 0)
		{
			if (index_id == 0) return indicies[0];
			if (index_id == 1) return indicies[1];
			if (index_id == 2) return indicies[3];
		}
		else
		{
			if (index_id == 0) return indicies[1];
			if (index_id == 1) return indicies[2];
			if (index_id == 2) return indicies[3];
		}
		return -1;
	}
};

template <typename EdgeIntegerType>
struct Edge
{
	typedef EdgeIntegerType et;
	et edge_id = 0;
	QUuid edge_twin_hash = 0;
	QUuid income_vertex_hash = 0;

	QUuid edge_hash;
	explicit Edge();
	explicit Edge(et error) :edge_id(error) {}
	explicit Edge(EdgeIntegerType arg_edgeid, EdgeIntegerType arg_edge_twin_id, EdgeIntegerType arg_verex_id);
	Edge(const Edge<EdgeIntegerType>& p);
	EdgeIntegerType& operator=(const EdgeIntegerType& b);
	Edge(Edge&& b);
	//	Edge& operator=(Edge&& b);
};

template <typename EdgeIntegerType>
Edge<EdgeIntegerType>::Edge(const Edge<EdgeIntegerType>& p)
{
	edge_id = p.edge_id;
	edge_twin_hash = p.edge_twin_id;
	vertex_hash = p.vertex_id;
}

template <typename EdgeIntegerType>
Edge<EdgeIntegerType>::Edge(Edge&& b)
{
	using namespace std;
	edge_id(move(b.edge_id));
	edge_twin_hash(move(b.edge_twin_id));
	vertex_hash(move(b.vertex_id));
}

template <typename EdgeIntegerType>
EdgeIntegerType& Edge<EdgeIntegerType>::operator=(const EdgeIntegerType& b)
{
	using namespace std;
	swap(b.edge_id, edge_id);
	swap(b.edge_twin_id, edge_twin_hash);
	swap(b.vertex_id, vertex_hash);
	return *this;
}

//template <typename EdgeIntegerType>
//Edge<EdgeIntegerType>::Edge(const Edge& p)
//{
//	edge_id = p.edge_id;
//	edge_twin_id = p.edge_twin_id;
//	vertex_id = p.vertex_id;
//}

template <typename EdgeIntegerType>
Edge<EdgeIntegerType>::Edge(EdgeIntegerType arg_edgeid,
	EdgeIntegerType arg_edge_twin_id,
	EdgeIntegerType arg_vertex_id) :
	edge_id(arg_edgeid),
	edge_twin_hash(arg_edge_twin_id),
	vertex_hash(arg_vertex_id)
{
	edge_hash = QUuid::createUuid();
}

template <typename EdgeIntegerType>
Edge<EdgeIntegerType>::Edge()
{

}

#pragma pack(pop)

#endif // VertexType_h__
