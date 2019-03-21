#pragma once

#include <QObject>

class NamedConstant : public QObject
{
	Q_OBJECT

public:
	NamedConstant(QObject *parent);
	~NamedConstant();
};
