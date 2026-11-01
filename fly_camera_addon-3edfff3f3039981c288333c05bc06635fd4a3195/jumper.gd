extends RigidBody3D

@export var jump_force := 10

func _integrate_forces(state: PhysicsDirectBodyState3D) -> void:
	if Input.is_action_just_pressed("jump"):
		state.apply_central_impulse(Vector3(0, jump_force, 0))
