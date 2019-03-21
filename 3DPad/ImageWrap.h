#pragma once

#include <QObject>

class ImageWrap : public QObject
{
	Q_OBJECT

public:
	ImageWrap(QObject *parent);
	~ImageWrap();
};
