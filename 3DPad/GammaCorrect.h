#pragma once

#include <QObject>

class GammaCorrect : public QObject
{
	Q_OBJECT

public:
	GammaCorrect(QObject *parent);
	~GammaCorrect();
};
