#pragma once

#include <QObject>

class Text2D : public QObject
{
	Q_OBJECT

public:
	Text2D(QObject *parent);
	~Text2D();
};
