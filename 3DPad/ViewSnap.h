#pragma once

#include <QObject>

class ViewSnap : public QObject
{
	Q_OBJECT

public:
	ViewSnap(QObject *parent);
	~ViewSnap();
};
