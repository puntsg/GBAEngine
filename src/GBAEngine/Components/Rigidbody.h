#pragma once
#include "AABB.h"
#include "Transform.h"
#include "bn_vector.h"
class Rigidbody
{
private:
	bn::vector<AABB*, 4> colliders;
	Transform* transform;
	Vector2 velocity;
	float angularVelocity;
	Vector2 acceleration;
	float angularAcceleration;
	float linearDrag;
	float angularDrag;

public:
	//iniciem les variables
	Rigidbody(Transform* _transform)
		: transform(_transform),
		velocity(Vector2()), angularVelocity(0.0f),
		acceleration(Vector2()), angularAcceleration(0.0f),
		linearDrag(0.0f), angularDrag(0.0f) {}

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
	bool CheckOverlappingPoint(Vector2 point) {
		for (AABB* myCol : colliders) {
			if (myCol->CheckOverlappingPoint(point)) {
				return true;
			}
		}
		return false;
	}
	void Update(float dt) {
		//1 Update de Velocity
		velocity = velocity + acceleration * dt; //acceleració era metres per segon, i dt és temps en segons
		angularVelocity = angularVelocity + angularAcceleration * dt;
		
		//2 Update the Drag
		velocity = velocity * (1.0f / (1.0f + dt * linearDrag));
		angularVelocity = angularVelocity * (1.0f / (1.0f + dt * angularDrag));
		
		//3 Update position
		transform->position = transform->position + velocity * dt;
		transform->rotation = transform->rotation + angularVelocity * dt;
		
		//4 Reset acceleration
		acceleration = Vector2();
		angularAcceleration = 0.0f;
		
		//5 Update the colliders positioning
		Vector2 offset = ((Vector2(-transform->size.x, -transform->size.y)) / 2.0f) * transform->scale;
		for (AABB* col : colliders) {
			col->SetTopLeft(transform->position + offset);
			col->SetSize(transform->size * transform->scale);
		}
	}

	inline void AddForce(Vector2 force) { acceleration = acceleration + force; }
	inline void AddTorque(float amount) { angularAcceleration += amount; }
	inline Vector2 const GetVelocity() { return velocity; }
	inline void SetVelocity(Vector2 velocity) { this->velocity = velocity; }
	inline void SetLinearDrag(float linearDrag) { this->linearDrag = linearDrag; }
	inline void SetAngularDrag(float angularDrag) { this->angularDrag = angularDrag; }
};