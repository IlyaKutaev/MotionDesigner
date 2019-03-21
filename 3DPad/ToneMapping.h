#pragma once

#include <QObject>

class ToneMapping : public QObject
{
	Q_OBJECT

public:
	ToneMapping(QObject *parent);
	~ToneMapping();
};
