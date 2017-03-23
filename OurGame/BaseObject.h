#pragma once
enum ObjectType
{
    //ש��
    Brick = 1,
    //�ְ�
    Steel,
    //�ݵ�
    Grass,
    //��ˮ
    DeepWater,
    //ǳˮ
    ShallowWater,
    //ѩ��
    Snow,
    //����
    Soil,
    //��
    King,
    //����
    Enemy,
    //���
    Player
};
class  BaseObject
{
public:
    virtual ~BaseObject() {};
    virtual bool Init() { return false; };
    virtual void Update() {};
    virtual void Render() {};
    ObjectType type;
};

