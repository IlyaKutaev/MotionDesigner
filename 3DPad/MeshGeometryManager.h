#ifndef MeshGeometryManager_h__
#define MeshGeometryManager_h__

#include <QObject>
#include <Pad_Numeric.h>
#include <VertexType.h>
#include <unordered_map>
#include <string>
#include <map>

class MeshGeometryManager
{
public:
	typedef std::unordered_map<std::string, Edge<pad_int>> EdgesMap;
	EdgesMap edges;
	size_t startup_pool_size = 1024 * 10;
	bool find_error = false;
private:
	std::map<size_t, Vertex<pad_int>> map_vertices;
	pad_int free_index = 0;
	std::vector<Vertex<pad_int>> vertices;
	std::vector<Face4<pad_int>> faces;
	std::vector<size_t> used_indicies;
	int surface_range_upper = CommonDivisions::div_primitive_maximum;

	int patch_parent_id = 0;
public:
	MeshGeometryManager();
	virtual ~MeshGeometryManager();
private:
	std::string IDHash(QUuid id);
public:
	EdgesMap::iterator GetEdge(QUuid edgeid);
	pad_int Create_Indexed_Vertex_For_2D_Surface(pad_int parent_id, pad_int child_id);
	int SetVertexPosition(pad_int parent_id, pad_int child_id, QVector3D position);
	int SetVertexNormal(pad_int parent_id, pad_int child_id, QVector3D normal);
	int SetVertexUV(pad_int parent_id, pad_int child_id, QVector3D uv);
	std::vector<Vertex<pad_int>> GetVertices();
	void AddFace(Face4<pad_int> face);
	std::vector<Face4<pad_int>> GetFaces();
	void SetSurfaceRange(int arg_range);
};

#endif // MeshGeometryManager_h__
