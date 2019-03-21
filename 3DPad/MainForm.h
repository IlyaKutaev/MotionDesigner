#ifndef IncludeGuard_3DPad_MainForm
#define IncludeGuard_3DPad_MainForm

#include <QtWidgets/QMainWindow>
#include "ui_DPad.h"
#include "_3DPad_Common.h"

class TempWidget;

class MainForm : public QMainWindow
{
	Q_OBJECT
public:
	padsmall Count;
private:
public:
	MainForm(QWidget *parent = Q_NULLPTR);

private:
	Ui::DPadClass ui;
};

#endif