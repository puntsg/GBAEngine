#pragma once
#include "bn_unordered_map.h"
#include "bn_vector.h"
#include "../Components/Component.h"
#include "../Components/Transform.h"

class Object {
public:
    Object() = default;
    virtual ~Object() = default;
    bool IsActive() const { return active; }
    bool IsPendingDestroy(){ return pendingDestroy; }
    void SetActive(bool value) { active = value; }
    virtual void OnEnable() = 0;
    virtual void OnDisable() = 0;
    virtual void Update(){

        //for(Component* c : components)
        //    if(c->IsEnabled())
        //       c->Update();
    }
    Transform transform;
private:
    bool active = true;
    bool pendingDestroy = false;
    bn::vector<Component*, 8> components; // punters: si no, els components derivats es "tallen" (slicing)
};