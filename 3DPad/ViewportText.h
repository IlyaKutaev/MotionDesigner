#pragma once

#include <QObject>

class ViewportText : public QObject
{
	Q_OBJECT

public:
	ViewportText(QObject *parent);
	~ViewportText();
};
