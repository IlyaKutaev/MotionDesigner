#pragma once

#include <QObject>

class Text : public QObject
{
	Q_OBJECT

public:
	Text(QObject *parent);
	~Text();
};
