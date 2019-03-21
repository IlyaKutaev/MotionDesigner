#pragma once

#include <QObject>

class ImageSave : public QObject
{
	Q_OBJECT

public:
	ImageSave(QObject *parent);
	~ImageSave();
};
