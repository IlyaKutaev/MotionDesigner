// This is an independent project of an individual developer. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "stdafx.h"
#include "Scene.h"
#include "SceneManager.h"
#include "Camera.h"
#include "Position.h"
#include "Mesh.h"

Scene::Scene(QObject *parent)
	: QObject(parent)
{
}

Scene::~Scene()
{
}

