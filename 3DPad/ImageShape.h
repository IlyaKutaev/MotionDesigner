#pragma once

#include <QObject>

class ImageShape : public QObject
{
	Q_OBJECT

public:
	ImageShape(QObject *parent);
	~ImageShape();
};
