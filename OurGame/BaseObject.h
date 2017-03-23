#pragma once
enum ObjectType
{
    //��
    Null = 0,
    //ѩ��
    Snow,
    //���
    Soil,
    //ש��
    Brick,
    //����ʯ
    Marble,
    //�ݵ�
    Grass,
    //��ˮ
    DeepWater,
    //ǳˮ
    ShallowWater,
    //��
    King,
    //��������
    KingDead,
    //����
    Enemy,
    //���
    Player
};
class  BaseObject
{
public:
    virtual ~BaseObject() {};
    virtual bool Init(ObjectType o, int x, int y) { return false; };
    virtual void Update() {};
    virtual void Render() {};
    ObjectType type;
};

