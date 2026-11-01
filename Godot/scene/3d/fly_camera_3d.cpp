#include "scene/3d/fly_camera_3d.h"
#include "core/input/input_event.h"
#include "core/input/input_map.h"
#include "core/math/math_funcs.h"
#include "core/math/vector3.h"
#include "core/string/string_name.h"
#include "core/typedefs.h"
#include "scene/3d/camera_3d.h"
#include "scene/3d/physics/collision_shape_3d.h"
#include "scene/main/node.h"
#include "scene/main/viewport.h"
#include "scene/resources/3d/sphere_shape_3d.h"

FlyCamera3D::FlyCamera3D() {
	set_process_input(true);
	set_physics_process(true);
	_cam_pivot = memnew(Node3D);
	_camera = memnew(Camera3D);
	_coll = nullptr;
}

void FlyCamera3D::_notification(int p_what) {
	switch (p_what) {
		case NOTIFICATION_READY: {
			_cam_pivot->set_name("_cam_pivot");
			add_child(_cam_pivot);
			_cam_pivot->add_child(_camera);
			_camera->set_name("_camera");
			_camera->set_current(true);
			Vector3 rot = get_rotation_degrees();
			set_rotation_degrees(Vector3(0, 0, 0));
			set_rot(rot);
			break;
		}
		case NOTIFICATION_PHYSICS_PROCESS: {
			if (Engine::get_singleton()->is_editor_hint()) {
				break;
			}
			float spd = fly_speed;

			Basis aim = _camera->get_camera_transform().basis;
			Vector3 dir;

			if (_mouse_hidden || keep_key_controls) {
				if (_is_cam_action_pressed(_ACTION_FORWARD)) {
					dir -= aim[2];
				}
				if (_is_cam_action_pressed(_ACTION_BACKWARD)) {
					dir += aim[2];
				}
				if (_is_cam_action_pressed(_ACTION_LEFT)) {
					dir -= aim[0];
				}
				if (_is_cam_action_pressed(_ACTION_RIGHT)) {
					dir += aim[0];
				}
				if (_is_cam_action_pressed(_ACTION_FASTER)) {
					spd *= speed_factor;
				}
				if (_is_cam_action_pressed(_ACTION_SLOWER)) {
					spd /= speed_factor;
				}
			}
			dir = dir.normalized();
			Vector3 target = dir * spd;
			set_velocity(get_velocity().lerp(target, acceleration * get_physics_process_delta_time()));
			move_and_slide();
			if (Math::is_zero_approx(get_velocity().length())) {
				set_velocity(Vector3(0, 0, 0));
			}
			break;
		}
	}
}
void FlyCamera3D::unhandled_input(const Ref<InputEvent> &p_event) {
	_check_mouse_capture(p_event);
	if (!_mouse_hidden) {
		return;
	}

	if (InputEventMouseMotion *event = static_cast<InputEventMouseMotion *>(p_event.ptr())) {
		_yaw = Math::fmod(_yaw - (int)(event->get_relative().x * mouse_sensitivity.x / 10), (float)360.0);
		if (!invert_y) {
			_pitch = MAX(MIN(_pitch - event->get_relative().y * mouse_sensitivity.y / 10.0, _PITCH_LIMIT), -_PITCH_LIMIT);
		} else {
			_pitch = MAX(MIN(_pitch + event->get_relative().y * mouse_sensitivity.y / 10.0, _PITCH_LIMIT), -_PITCH_LIMIT);
		}

		_cam_pivot->set_rotation(Vector3(_cam_pivot->get_rotation().x, Math::deg_to_rad(_yaw), _cam_pivot->get_rotation().z));
		_camera->set_rotation(Vector3(Math::deg_to_rad(_pitch), _camera->get_rotation().y, _camera->get_rotation().z));
	}
}

bool FlyCamera3D::_is_cam_action_pressed(StringName action) {
	if (!use_default_controls && InputMap::get_singleton()->has_action(action)) {
		return Input::get_singleton()->is_action_pressed(action);
	}
	return Input::get_singleton()->is_key_pressed(_actions_to_keys[action]);
}

void FlyCamera3D::_set_collisions(bool enable) {
	if (enable) {
		_coll = memnew(CollisionShape3D);
		_coll->set_name("_coll");
		_coll->set_shape(memnew(SphereShape3D));
		add_child(_coll);
	} else {
		_coll->queue_free();
		_coll = nullptr;
	}
}

void FlyCamera3D::_check_mouse_capture(const Ref<InputEvent> &p_event) {
	enum ButtonState {
		UNCHANGED,
		PRESSED,
		RELEASED
	};
	ButtonState buttonState = UNCHANGED;
	if (!use_default_controls && InputMap::get_singleton()->has_action(_ACTION_ACTIVATE)) {
		if (p_event->is_action_pressed(_ACTION_ACTIVATE)) {
			buttonState = PRESSED;
		} else if (p_event->is_action_released(_ACTION_ACTIVATE)) {
			buttonState = RELEASED;
		}
	} else if (InputEventMouseButton *event = static_cast<InputEventMouseButton *>(p_event.ptr())) {
		if (event->get_button_index() == mouse_button) {
			if (event->is_pressed()) {
				buttonState = PRESSED;
			} else {
				buttonState = RELEASED;
			}
		}
	}
	if (buttonState == UNCHANGED) {
		return;
	}
	switch (activation_mode) {
		case ON_HOLD: {
			set_active(buttonState == PRESSED);
			break;
		}
		case ON_CLICK: {
			if (buttonState == PRESSED) {
				set_active(!_mouse_hidden);
			}
		}
	}
}

void FlyCamera3D::_revert_mouse_pos() {
	Viewport *vp = get_viewport();
	switch (revert_mouse_to) {
		case CLICK_POSITION: {
			vp->warp_mouse(_mouse_click_pos);
			break;
		}
		case VIEWPORT_CENTER: {
			vp->warp_mouse(vp->get_visible_rect().get_size() / 2);
			break;
		}
	}
}

Camera3D *FlyCamera3D::get_camera() {
	return _camera;
}

void FlyCamera3D::set_rot(Vector3 rot) {
	_yaw = rot.y;
	_pitch = rot.x;
	Vector3 pivotRotDeg = _cam_pivot->get_rotation_degrees();
	_cam_pivot->set_rotation_degrees(Vector3(pivotRotDeg.x, _yaw, pivotRotDeg.z));
	Vector3 camRotDeg = _camera->get_rotation_degrees();
	_camera->set_rotation_degrees(Vector3(_pitch, camRotDeg.y, camRotDeg.z));
}

Vector3 FlyCamera3D::get_rot() {
	return Vector3(_camera->get_rotation().x, _cam_pivot->get_rotation().y, 0);
}
