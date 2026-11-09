#pragma once
class Object {
public:
    Object() = default;
    virtual ~Object() = default;
    bool IsActive() const { return active; }
    bool IsPendingDestroy(){ return pendingDestroy; }
    void SetActive(bool value) { active = value; }
    virtual void OnEnable() = 0;
    virtual void OnDisable() = 0;
    virtual void Update() = 0;
private:
    bool active = true;
    bool pendingDestroy = false;
};