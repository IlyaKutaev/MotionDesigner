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

	for (auto &point : mesh->uv_vertices)
	{
		(*stream) << "vt ";
		(*stream) << text2(point);
		(*stream) << "\n";
	}

	for (auto &normal : mesh->normals)
	{
		(*stream) << "vn ";
		(*stream) << text(normal);
		(*stream) << "\n";
	}

	int counter = 0;
	for (auto &face : mesh->faces)
	{
		(*stream) << "f ";
		for (auto i = 0; i < 4; i++)
		{
			(*stream) << QString::number(face.indicies[i] + 1);
			(*stream) << "/";
			(*stream) << QString::number(face.uv_indicies[i] + 1);
			(*stream) << "/";
			(*stream) << QString::number(face.indicies[i] + 1);
			(*stream) << QString(" ");
		}
		(*stream) << "\n";
		counter++;
	}

	(*stream) << "\n";

	stream->device()->close();
}

QString Wavefront::text(QVector3D vector)
{
	QString delimiter = " ";
	QVector3D vec = vector;

	if (std::abs(vec.x()) < 0.00001f) vec.setX(0);
	if (std::abs(vec.y()) < 0.00001f) vec.setY(0);
	if (std::abs(vec.z()) < 0.00001f) vec.setZ(0);

	QString out = QString::number(vec.x()) + delimiter + QString::number(vec.y()) + delimiter + QString::number(vec.z());

	return out;
}

QString Wavefront::text2(QVector3D vector)
{
	QString delimiter = " ";

	QVector3D vec = vector;
	if (std::abs(vec.x()) < 0.00001f) vec.setX(0);
	if (std::abs(vec.y()) < 0.00001f) vec.setY(0);
	if (std::abs(vec.z()) < 0.00001f) vec.setZ(0);

	QString out = QString::number(vec.x()) + delimiter + QString::number(vec.y());

	return out;
}
