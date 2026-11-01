#pragma once
#include "scene/3d/physics/rigid_body_3d.h"

class Jumper3D : public RigidBody3D
{
	GDCLASS(Jumper3D, RigidBody3D);

	const int jump_force = 10;

protected:
	void _notification(int);

public:
	Jumper3D();
	~Jumper3D();
};
