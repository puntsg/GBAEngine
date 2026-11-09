#pragma once
#include "bn_fixed_point.h"
#include "bn_point.h"
#include "Component.h"
class AABB :public Component
{
protected:
	int layer;
	bool isTrigger;

public:
	bool CheckOverlappingAABB(const AABB* other);
};

class AABB_Rectangle : public AABB
{
public:
	AABB_Rectangle(bn::point _topLeft, bn::point _size);
};

class AABB_Box : public AABB
{
	public:
	AABB_Box(bn::point _topLeft, bn::point _size);
};

class AABB_Circle : public AABB
{
	public:
	AABB_Circle(bn::point _topLeft, bn::fixed _size);
};

