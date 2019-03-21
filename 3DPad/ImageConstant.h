#pragma once

#include <QObject>

class ImageConstant : public QObject
{
	Q_OBJECT

public:
	ImageConstant(QObject *parent);
	~ImageConstant();
};
