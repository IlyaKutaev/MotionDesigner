#pragma once

#include <QObject>

class Renamer : public QObject
{
	Q_OBJECT

public:
	Renamer(QObject *parent);
	~Renamer();
};
