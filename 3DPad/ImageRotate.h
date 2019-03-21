#pragma once

#include <QObject>

class ImageRotate : public QObject
{
	Q_OBJECT

public:
	ImageRotate(QObject *parent);
	~ImageRotate();
};
