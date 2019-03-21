#pragma once

#include <QObject>

class Table : public QObject
{
	Q_OBJECT

public:
	Table(QObject *parent);
	~Table();
};
