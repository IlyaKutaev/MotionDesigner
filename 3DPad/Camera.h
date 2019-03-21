#pragma once

#include <QObject>
#include <QMatrix4x4>

class Camera : public QObject
{
	Q_OBJECT
private:
public:
	Camera(QObject *parent);
	~Camera();
public:

};
