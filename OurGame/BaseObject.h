#pragma once
enum ObjectType
{
    //空
    Null = 0,
    //雪地
    Snow,
    //泥地
    Soil,
    //砖块
    Brick,
    //大理石
    Marble,
    //草地
    Grass,
    //深水
    DeepWater,
    //浅水
    ShallowWater,
    //王
    King,
    //已死的王
    KingDead,
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

