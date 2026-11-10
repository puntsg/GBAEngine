#pragma once
class Component
{
public:
	Component() {}
	virtual ~Component() {}
    virtual void Update() {}
    bool IsEnabled() const { return enabled; }
    void SetEnabled(bool value) { enabled = value; }
private:
    bool enabled = true;

};