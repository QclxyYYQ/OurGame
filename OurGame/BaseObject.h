#pragma once
enum ObjectType
{
    //砖块
    Brick = 1,
    //钢板
    Steel,
    //草地
    Grass,
    //深水
    DeepWater,
    //浅水
    ShallowWater,
    //雪地
    Snow,
    //泥土
    Soil,
    //王
    King,
    //敌人
    Enemy,
    //玩家
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

