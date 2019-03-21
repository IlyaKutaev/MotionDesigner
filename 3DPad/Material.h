#pragma once

#include <QObject>

class Material : public QObject
{
	Q_OBJECT

public:
	Material(QObject *parent);
	~Material();
};
