#pragma once

#include <QObject>

class SelectionGrow : public QObject
{
	Q_OBJECT

public:
	SelectionGrow(QObject *parent);
	~SelectionGrow();
};
