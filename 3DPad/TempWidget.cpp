// This is an independent project of an individual developer. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "stdafx.h"
#include "TempWidget.h"

TempWidget::TempWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	QVBoxLayout *layout = new QVBoxLayout(this);
	layout->setMargin(2);
	setLayout(layout);
}

TempWidget::~TempWidget()
{
}

void TempWidget::paintEvent(QPaintEvent *event)
{
	QPainter p(this);
	p.drawText(rect().center(), "Loading...");
	p.end();
}

void drawText(QPainter & painter, qreal x, qreal y, Qt::Alignment flags,
	const QString & text, QRectF * boundingRect = 0)
{
	const qreal size = 32767.0;
	QPointF corner(x, y - size);
	if (flags & Qt::AlignHCenter) corner.rx() -= size / 2.0;
	else if (flags & Qt::AlignRight) corner.rx() -= size;
	if (flags & Qt::AlignVCenter) corner.ry() += size / 2.0;
	else if (flags & Qt::AlignTop) corner.ry() += size;
	else flags |= Qt::AlignBottom;
	QRectF rect{ corner.x(), corner.y(), size, size };
	painter.drawText(rect, flags, text, boundingRect);
}

