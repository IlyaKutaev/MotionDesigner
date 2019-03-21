// This is an independent project of an individual developer. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "stdafx.h"
#include "MainForm.h"
#include "TempWidget.h"
#include <VertexType.h>
#include <vector>
#include <Range.h>
#include <Export.h>
#include <FreeMemory.h>

using namespace std;

MainForm::MainForm(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	QString app_title = QString::fromStdString(FreeMemory::Instance().LockMemory());

	setWindowTitle(app_title);

	Export *export0 = new Export(this);
	export0->Test();
}
