#pragma once

#include <QObject>

class VolumeSelect : public QObject
{
	Q_OBJECT

public:
	VolumeSelect(QObject *parent);
	~VolumeSelect();
};
