#pragma once

#include <QObject>

class ViewGrid : public QObject
{
	Q_OBJECT

public:
	ViewGrid(QObject *parent);
	~ViewGrid();
};
