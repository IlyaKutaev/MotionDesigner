#pragma once

#include <QObject>

class TextureManager : public QObject
{
	Q_OBJECT

public:
	TextureManager(QObject *parent);
	~TextureManager();
};
