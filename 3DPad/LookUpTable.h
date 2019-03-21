#pragma once

#include <QObject>

class LookUpTable : public QObject
{
	Q_OBJECT

public:
	LookUpTable(QObject *parent);
	~LookUpTable();
};
