#include "jumper_3d.h"
#include "core/input/input.h"

Jumper3D::Jumper3D()
{
	set_process_input(true);
	set_physics_process(true);
}
Jumper3D::~Jumper3D() {}

void Jumper3D::_notification(int p_what)
{
	if (Engine::get_singleton()->is_editor_hint()) {
		return;
	}
	switch (p_what) {
	case NOTIFICATION_READY:
		set_can_sleep(false);
		break;

	case NOTIFICATION_PHYSICS_PROCESS:
		if (Input::get_singleton()->is_action_just_pressed("jump")) {
			apply_central_impulse(Vector3(0, jump_force, 0));
		}
		break;
	}
}
