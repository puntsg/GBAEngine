#pragma once
#define PM PhysicsManager::Instance()

class PhysicsManager
{
private:

	PhysicsManager() = default;
	PhysicsManager(PhysicsManager&) = delete;
	PhysicsManager& operator=(const PhysicsManager&) = delete;
    bool collisionMatrix[8][8];
	
public:
	inline static PhysicsManager& Instance() {
		static PhysicsManager pm;
		return pm;
	}
	inline void SetCollisionMatrix(bool matrix[8][8]) {
		for (int i = 0; i < 8; i++) 
			for (int j = 0; j < 8; j++) 
				collisionMatrix[i][j] = matrix[i][j];

	}
	inline bool GetCollisionMatrixValue(int layerA, int layerB) {
		return collisionMatrix[layerA][layerB];
	}
	inline void SetCollisionMatrixValue(int layerA, int layerB, bool value) {
		collisionMatrix[layerA][layerB] = value;
		collisionMatrix[layerB][layerA] = value;
	}
	void UpdatePhysics();
};