// This is an independent project of an individual developer. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "stdafx.h"
#include "SceneManager.h"
#include "Position.h"
#include "Camera.h"
#include "Scene.h"
#include "Mesh.h"

SceneManager::SceneManager(QObject *parent)
	: QObject(parent)
{
}

SceneManager::~SceneManager()
{
}
