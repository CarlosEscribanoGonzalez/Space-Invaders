#pragma once
#include "Solid.h"
class Camera : public Solid
{
public:
	Camera(Vector3D positionArgument = Vector3D()) :
		Solid(positionArgument) {}

	void Render();
};

