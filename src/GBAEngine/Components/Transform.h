#pragma once
#include "bn_fixed.h"
#include "bn_fixed_point.h"
#include "Component.h"

class Transform : public Component
{
public:
    Transform()
        : position(bn::fixed_point(0, 0)), rotation(0), size(bn::fixed_point(1, 1)), scale(bn::fixed_point(1, 1)) {}

    Transform(bn::fixed_point _position, bn::fixed _rotation, bn::fixed_point _size, bn::fixed_point _scale)
        : position(_position), rotation(_rotation), size(_size), scale(_scale) {}

    ~Transform() = default;
    bn::fixed_point position;
    bn::fixed rotation;
    bn::fixed_point size;
    bn::fixed_point scale;
};
