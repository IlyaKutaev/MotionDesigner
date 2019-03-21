#ifndef PolyCombiner_Patch_h__
#define PolyCombiner_Patch_h__

#include "IPolyCombiner.h"
#include <MeshGeometryManager.h>
#include <VertexType.h>
#include <QUuid>

class PolyCombiner_Patch : public IPolyCombiner<MeshGeometryManager>
{
public:
	PolyCombiner_Patch();
	virtual ~PolyCombiner_Patch();
private:
	pad_int error = -844;
public:
	virtual void CombineEdges(QUuid edgeid0, QUuid edgeid1) override;
	virtual int SetVertexPosition(pad_int parent_id, pad_int child_id, QVector3D position) override;
	virtual int SetVertexNormal(pad_int parent_id, pad_int child_id, QVector3D normal);
	virtual int SetVertexUV(pad_int parent_id, pad_int child_id, QVector3D uv);
	virtual int GetIndexFor2DSurface(pad_int parent_index, pad_int chlid_index) override;
	virtual void AddFace(Face4<pad_int> face) override;
};

#endif // PolyCombiner_Patch_h__
