#pragma once

#include "core/os/keyboard.h"
#include "scene/3d/camera_3d.h"
#include "scene/3d/physics/character_body_3d.h"
#include "scene/3d/physics/collision_shape_3d.h"
#include <map>

class FlyCamera3D : public CharacterBody3D {
	GDCLASS(FlyCamera3D, CharacterBody3D);

public:
	enum ActivationMode { ON_CLICK,
		ON_HOLD };
	enum RevertMouseOption { CLICK_POSITION,
		VIEWPORT_CENTER };

	ActivationMode activation_mode = ActivationMode::ON_CLICK;
	RevertMouseOption revert_mouse_to = RevertMouseOption::CLICK_POSITION;
	MouseButton mouse_button = MouseButton::RIGHT;
	Vector2 mouse_sensitivity = Vector2(2.2, 2.2);
	bool invert_y = false;
	bool keep_key_controls = true;
	float fly_speed = 20.0;
	int acceleration = 10;
	int speed_factor = 3;
	bool use_collision = false;
	bool use_default_controls = false;

	Camera3D *get_camera();

	void set_rot(Vector3);

	Vector3 get_rot();

	void set_active(bool);

	FlyCamera3D();
	~FlyCamera3D();

protected:
	void unhandled_input(const Ref<InputEvent> &) override;
	void _notification(int);

private:
	const StringName _ACTION_FORWARD = "cam_forward";
	const StringName _ACTION_BACKWARD = "cam_backward";
	const StringName _ACTION_LEFT = "cam_left";
	const StringName _ACTION_RIGHT = "cam_right";
	const StringName _ACTION_FASTER = "cam_faster";
	const StringName _ACTION_SLOWER = "cam_slower";
	const StringName _ACTION_ACTIVATE = "cam_activate";

	std::map<StringName, Variant> _actions_to_keys = { { _ACTION_FORWARD, Key::W }, { _ACTION_BACKWARD, Key::S }, { _ACTION_LEFT, Key::A }, { _ACTION_RIGHT, Key::D }, { _ACTION_FASTER, Key::SHIFT }, { _ACTION_SLOWER, Key::CTRL }, { _ACTION_ACTIVATE, mouse_button } };

	const int _PITCH_LIMIT = 90;

	Vector2 _mouse_click_pos;

	bool _mouse_hidden = false;

	CollisionShape3D *_coll;

	Camera3D *_camera;

	Node3D *_cam_pivot;

	float _yaw = 0;
	float _pitch = 0;

	bool _is_cam_action_pressed(StringName);

	void _set_collisions(bool);

	void _check_mouse_capture(const Ref<InputEvent> &);

	void _revert_mouse_pos();
};
