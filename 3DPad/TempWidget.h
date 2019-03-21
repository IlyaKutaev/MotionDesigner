#pragma once

#include <QWidget>
#include "ui_TempWidget.h"

class TempWidget : public QWidget
{
	Q_OBJECT

public:
	TempWidget(QWidget *parent = Q_NULLPTR);
	~TempWidget();

private:
	Ui::TempWidget ui;
	void paintEvent(QPaintEvent *event);
};
