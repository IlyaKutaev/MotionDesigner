#pragma once

#include <QObject>

class UndoManager : public QObject
{
	Q_OBJECT

public:
	UndoManager(QObject *parent);
	~UndoManager();
};
