#include "stdafx.h"
#include "CheckDisk.h"

CheckDisk::CheckDisk(QObject *parent)
	: QObject(parent)
{
}

CheckDisk::CheckDisk(QString arg_filename, QObject *parent):
	filename(arg_filename),QObject(parent)
{

}

CheckDisk::~CheckDisk()
{
}

bool CheckDisk::CheckDiskForOutput(size_t size)
{
	if (filename.isEmpty()) return false;

	auto list = filename.split("/");
	auto letter = list.first();
	letter = letter.append("/");

	QStorageInfo *storage = new QStorageInfo(letter);

	if (storage->isReadOnly()) return false;

	if (storage->bytesAvailable() < size) return false;

	if (!storage->isReady()) return false;

	return true;
}
