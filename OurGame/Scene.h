#pragma once
//���г����Ļ��࣬����ͳһ�ӿڵ���
class Scene
{
public:
    virtual void Init() {};
    virtual void End() {};
    virtual void Render() {};
    virtual void Update() {};
};