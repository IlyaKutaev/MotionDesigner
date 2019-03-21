#pragma once

#include <QObject>

class Archive : public QObject
{
	Q_OBJECT

public:
	Archive(QObject *parent);
	~Archive();
};
