#pragma once

#include <QObject>

class CheckDisk : public QObject
{
	Q_OBJECT
public:
	QString filename;
private:
public:
	CheckDisk(QString arg_filename, QObject *parent);
	CheckDisk(QObject *parent);
	~CheckDisk();
	bool CheckDiskForOutput(size_t size);
};
