#pragma once
class  BaseObject
{
public:
    virtual ~BaseObject() {};
    virtual bool Init() { return false; };
    virtual void Update() {};
    virtual void Render() {};
};

