#pragma once

#include <QObject>
#include <Pad_Numeric.h>

class MeshPtr;

class Wavefront : public QObject
{
	Q_OBJECT
public:

public:
	Wavefront(QObject *parent);
	~Wavefront();
public:
	void Export(QString filename, MeshPtr *mesh);
private:
	QString text(QVector3D vector);
};
