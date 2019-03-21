#pragma once

#include <QObject>

class Matrix : public QObject
{
	Q_OBJECT

public:
	Matrix(QObject *parent);
	~Matrix();
};
