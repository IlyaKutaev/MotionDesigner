#pragma once

#include <QObject>

class EdgeHardness : public QObject
{
	Q_OBJECT

public:
	EdgeHardness(QObject *parent);
	~EdgeHardness();
};
