#pragma once

#include <QObject>

class ImageProxy : public QObject
{
	Q_OBJECT

public:
	ImageProxy(QObject *parent);
	~ImageProxy();
};
