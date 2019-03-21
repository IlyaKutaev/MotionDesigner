#pragma once

#include <QObject>

class ImageResize : public QObject
{
	Q_OBJECT

public:
	ImageResize(QObject *parent);
	~ImageResize();
};
