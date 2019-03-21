#pragma once

#include <QObject>

class NativeFormat : public QObject
{
	Q_OBJECT

public:
	NativeFormat(QObject *parent);
	~NativeFormat();
};
