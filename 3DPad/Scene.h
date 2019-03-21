#pragma once

#include <QObject>
class Camera;
class SceneManager;
class Mesh;

class Scene : public QObject
{
	Q_OBJECT
public:
	QVector<Camera *> cameras;
	QVector<Mesh *> meshes;
	QVector<QWidget *> windows;
public:
	Scene(QObject *parent);
	~Scene();
public:
};
