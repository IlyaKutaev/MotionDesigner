#pragma once

#include <QObject>

class SharedNodeProperties : public QObject
{
	Q_OBJECT
public:
	enum NodeState
	{
		normal,
		disabled,
		count
	};
	NodeState node_state = normal;
	QString name = "Untitled";
	QUuid guid;
public:
	SharedNodeProperties(QObject *parent);
	~SharedNodeProperties();
};
