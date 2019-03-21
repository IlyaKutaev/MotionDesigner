#pragma once

#include <QObject>

class Delete : public QObject
{
	Q_OBJECT

public:
	Delete(QObject *parent);
	~Delete();
};
