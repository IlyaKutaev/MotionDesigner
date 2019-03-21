#pragma once

#include <QObject>

class TableSave : public QObject
{
	Q_OBJECT

public:
	TableSave(QObject *parent);
	~TableSave();
};
