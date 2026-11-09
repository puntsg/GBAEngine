#pragma once
class Component
{
public:
	Component() {}
	virtual ~Component() {}
    virtual void Update(float dt) = 0;
    bool IsEnabled() const { return enabled; }
    void SetEnabled(bool value) { enabled = value; }
private:
    bool enabled = true;

};