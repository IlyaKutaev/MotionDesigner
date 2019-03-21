// This is an independent project of an individual developer. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "stdafx.h"
#include "Camera.h"
#include "Position.h"
#include "SceneManager.h"

Camera::Camera(QObject *parent)
	: QObject(parent)
{
}

Camera::~Camera()
{
}
