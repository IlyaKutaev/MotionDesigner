#pragma once

#include <QWidget>
#include "ui_Viewport.h"

class Viewport : public QWidget
{
	Q_OBJECT

public:
	Viewport(QWidget *parent = Q_NULLPTR);
	~Viewport();


	virtual QPaintEngine * paintEngine() const override;

	bool locked = true;
private:
	bool mouse_pressed = false;
private:
	Ui::Viewport ui;

	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
	void paintEvent(QPaintEvent *event);
public:
signals:
	void RotateCamera(float x, float y);
	void Updated();
};
