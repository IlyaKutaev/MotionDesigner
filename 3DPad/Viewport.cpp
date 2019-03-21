// This is an independent project of an individual developer. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "stdafx.h"
#include "Viewport.h"

Viewport::Viewport(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	this->setAttribute(Qt::WA_PaintOnScreen, true);
}

Viewport::~Viewport()
{
}

QPaintEngine * Viewport::paintEngine() const
{
	return nullptr;
}

void Viewport::mousePressEvent(QMouseEvent *event)
{
	mouse_pressed = true;
}

void Viewport::mouseMoveEvent(QMouseEvent *event)
{
	if (locked) return;

	static int oldx = event->x();
	static int oldy = event->y();

	if (mouse_pressed)
	{
		emit RotateCamera(oldx - event->x(),oldy - event->y());
		emit Updated();
	}

	oldx = event->x();
	oldy = event->y();
}

void Viewport::mouseReleaseEvent(QMouseEvent *event)
{
	mouse_pressed = false;
}

void Viewport::paintEvent(QPaintEvent *event)
{
	emit Updated();
}
