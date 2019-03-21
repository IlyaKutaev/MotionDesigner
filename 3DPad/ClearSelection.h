#pragma once

#include <QObject>

class ClearSelection : public QObject
{
	Q_OBJECT

public:
	ClearSelection(QObject *parent);
	~ClearSelection();
};
