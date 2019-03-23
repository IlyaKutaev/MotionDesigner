// This is an independent project of an individual developer. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include <QObject>
#include <qglobal.h>
#include <Pad_Numeric.h>
#include <VertexType.h>

class Cylinder;
class MeshPtr;

class Export : public QObject
{
	Q_OBJECT
private:
	Cylinder *cylinder = nullptr;
public:
	Export(QObject *parent);
	~Export();
public:
	void ExportObject(MeshPtr *mesh, QString filename);
	void Test();
};