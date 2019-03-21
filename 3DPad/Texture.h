#pragma once

#include <QObject>

class Texture : public QObject
{
	Q_OBJECT

public:
	Texture(QObject *parent);
	~Texture();
};
