#pragma once

#include <QObject>

class FishEye : public QObject
{
	Q_OBJECT

public:
	FishEye(QObject *parent);
	~FishEye();
};
