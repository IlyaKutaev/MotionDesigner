#pragma once

#include <QObject>

class Polygon : public QObject
{
	Q_OBJECT
public:
	int vertices_count = 6;
	float radius = 25;
	bool fill = true;
	bool border = true;
	QColor fill_color = QColor(255, 255, 255);
	QColor border_color = QColor(0, 0, 0);
	float border_width = 3;
public:
	Polygon(QObject *parent);
	~Polygon();
};
