#pragma once
#include "AABB.h"
#include "Transform.h"
#include "bn_vector.h"
#include "bn_fixed.h"
#include "bn_fixed_point.h"

// Unitats "per frame": la GBA va sempre a 60 fps fixos, així que no fem servir dt.
//  - velocity: píxels/frame          - acceleration: píxels/frame²
//  - angularVelocity: graus/frame    - angularAcceleration: graus/frame²
class Rigidbody
{
private:
	bn::vector<AABB*, 4> colliders;
	Transform* transform;
	bn::fixed_point velocity;
	bn::fixed angularVelocity;
	bn::fixed_point acceleration;
	bn::fixed angularAcceleration;
	bn::fixed linearDrag;
	bn::fixed angularDrag;

public:
	//iniciem les variables
	Rigidbody(Transform* _transform)
		: transform(_transform),
		velocity(bn::fixed_point()), angularVelocity(0),
		acceleration(bn::fixed_point()), angularAcceleration(0),
		linearDrag(0), angularDrag(0) {}

	~Rigidbody() {
		RemoveColliders();
	}

	inline void AddCollider(AABB* collider) { colliders.push_back(collider); }
	void RemoveColliders() {
			for (AABB* collider: colliders)
				delete collider;
			colliders.clear();
	}
	bool CheckCollision(const Rigidbody* other) {
		for (AABB* myCol : colliders) {
			for (AABB* otherCol : other->colliders) {
				if (myCol->CheckOverlappingAABB(otherCol))
					return true;
			}
		}
		return false;
	}
	// TODO: descomentar quan AABB tingui CheckOverlappingPoint
	//bool CheckOverlappingPoint(bn::point point) {
	//	for (AABB* myCol : colliders) {
	//		if (myCol->CheckOverlappingPoint(point)) {
	//			return true;
	//		}
	//	}
	//	return false;
	//}
	void Update() {
		//1 Update de Velocity
		velocity = velocity + acceleration;
		angularVelocity = angularVelocity + angularAcceleration;

		//2 Update the Drag
		velocity = velocity / (1 + linearDrag);
		angularVelocity = angularVelocity / (1 + angularDrag);

		//3 Update position
		transform->position = transform->position + velocity;
		transform->rotation = transform->rotation + angularVelocity;

		// Mantenim la rotació dins [0, 360) (Butano ho exigeix a set_rotation_angle)
		while (transform->rotation >= 360) transform->rotation -= 360;
		while (transform->rotation < 0)    transform->rotation += 360;

		//4 Reset acceleration
		acceleration = bn::fixed_point();
		angularAcceleration = 0;

		//5 Update the colliders positioning
		// TODO: descomentar quan AABB tingui SetTopLeft / SetSize
		//bn::fixed_point offset = ...;
		//for (AABB* col : colliders) {
		//	col->SetTopLeft(transform->position + offset);
		//	col->SetSize(...);
		//}
	}

	inline void AddForce(bn::fixed_point force) { acceleration = acceleration + force; }
	inline void AddTorque(bn::fixed amount) { angularAcceleration += amount; }
	inline bn::fixed_point GetVelocity() const { return velocity; }
	inline void SetVelocity(bn::fixed_point velocity) { this->velocity = velocity; }
	inline void SetLinearDrag(bn::fixed linearDrag) { this->linearDrag = linearDrag; }
	inline void SetAngularDrag(bn::fixed angularDrag) { this->angularDrag = angularDrag; }
};
