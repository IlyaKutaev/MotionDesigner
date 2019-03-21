#ifndef IPolyCombiner_h__
#define IPolyCombiner_h__

#include <QObject>
#include <QtGlobal>
#include <Pad_Numeric.h>
#include <VertexType.h>
#include <QUuid>

template <typename GeometryManagerType>
class IPolyCombiner
{
public:
	GeometryManagerType *geometry_manager = nullptr;
public:
	explicit IPolyCombiner();
	virtual ~IPolyCombiner();
public:
	virtual void CombineEdges(QUuid edgeid0, QUuid edgeid1) = 0;
	virtual int SetVertexPosition(pad_int parent_id, pad_int child_id, QVector3D position) = 0;
	virtual int GetIndexFor2DSurface(pad_int parent_index, pad_int chlid_index) = 0;
	virtual void AddFace(Face4<pad_int> face) = 0;
};

template <typename GeometryManagerType>
IPolyCombiner<GeometryManagerType>::IPolyCombiner()
{
	geometry_manager = new GeometryManagerType();
}

template <typename GeometryManagerType>
IPolyCombiner<GeometryManagerType>::~IPolyCombiner()
{

}

#endif // IPolyCombiner_h__
