#pragma once

#include <QObject>

class Line : public QObject
{
	Q_OBJECT

public:
	Line(QObject *parent);
	~Line();
};
