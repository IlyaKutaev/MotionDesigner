#include "stdafx.h"
#include "Wavefront.h"
#include <MeshPtr.h>
#include <CheckDisk.h>

Wavefront::Wavefront(QObject *parent)
	: QObject(parent)
{
}

Wavefront::~Wavefront()
{
}

void Wavefront::Export(QString filename, MeshPtr *mesh)
{
	auto check = new CheckDisk(filename, this);

	if (!check->CheckDiskForOutput(mesh->GetSize())) return;

	filename = filename.toLower();

	QTextStream *stream = new QTextStream(new QFile(filename));

	if (!stream->device()->open(QIODevice::WriteOnly)) return;

	int id = 0;
	QString comment = "#";
	(*stream) << comment + filename;
	(*stream) << comment + "created by MotionDesigner";
	(*stream) << '\n';
	(*stream) << QString("g Group") + QString::number(id++) + "\n";

	(*stream) << "\n";

	for (auto &point : mesh->vertices)
	{
		(*stream) << "v ";
		(*stream) << text(point);
		(*stream) << "\n";
	}

	for (auto &normal : mesh->normals)
	{
		(*stream) << "vn ";
		(*stream) << text(normal);
		(*stream) << "\n";
	}

	for (auto &face : mesh->faces)
	{
		(*stream) << "f ";
		for (auto i = 0; i < 4; i++)
		{
			(*stream) << QString::number(face.indicies[i]);
			(*stream) << "//";
			(*stream) << QString::number(face.indicies[i]);
			(*stream) << QString(" ");
		}
		(*stream) << "\n";
	}

	(*stream) << "\n";

	stream->device()->close();
}

QString Wavefront::text(QVector3D vector)
{
	QString delimiter = " ";
	QString out = QString::number(vector.x()) + delimiter + QString::number(vector.y()) + delimiter + QString::number(vector.z());

	return out;
}