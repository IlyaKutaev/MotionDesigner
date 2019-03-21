#pragma once

#include <QObject>

class TextureHDR : public QObject
{
	Q_OBJECT

public:
	TextureHDR(QObject *parent);
	~TextureHDR();
};
