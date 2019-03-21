#pragma once

#include <QObject>

class RedshiftPassEquation : public QObject
{
	Q_OBJECT

public:
	RedshiftPassEquation(QObject *parent);
	~RedshiftPassEquation();
};
