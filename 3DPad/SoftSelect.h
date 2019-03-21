#pragma once

#include <QObject>

class SoftSelect : public QObject
{
	Q_OBJECT

public:
	SoftSelect(QObject *parent);
	~SoftSelect();
};
