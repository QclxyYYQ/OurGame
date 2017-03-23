#include"Map.h"
#include"Global.h"
#include"TileObject.h"
#include"BulletObject.h"
namespace Map {
    //MapSize*MapSize大小的矩阵
    BaseObject *mapObjects[Global::Game::MapGridNum][Global::Game::MapGridNum];

    //随机生成地图
    void CreateData()
    {
        srand(GetTickCount());
        for (int i = 0; i < Global::Game::MapGridNum; i++)
        {
            for (int k = 0; k < Global::Game::MapGridNum; k++)
            {
                int s = rand() % 8;
                if (s > 0)
                {
                    mapObjects[i][k] = new TileObject();
                    mapObjects[i][k]->Init((ObjectType)s, i, k);
                }
            }
        }

    }
    //从文件载入地图
    void LoadData()
    {

    }
    //将地图写到文件
    void SaveData()
    {

    }
    BulletObject *b;
    void Init() {

        //CreateData();
        b = new BulletObject();
        b->Init(2, 2, DIRECTION::RIGHT);
    }
    void Render()
    {
        if (b != NULL)
            b->Render();
        /*for (int i = 0; i < Global::Game::MapGridNum; i++)
        {
            for (int k = 0; k < Global::Game::MapGridNum; k++)
            {
                if (mapObjects[i][k] != NULL)
                {
                    mapObjects[i][k]->Render();
                }
            }
        }*/
    }
    void Update() {
        if (b != NULL)
            b->Update();
    }
    BaseObject GetNearObject()
    {
        return BaseObject();
    }
    void End()
    {
        //delete mapObjects;
    }
}