#include"Map.h"
#include"Global.h"
#include"TileObject.h"
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
    void Init() {
       
        CreateData();
    }
    void Render()
    {
        for (int i = 0; i < Global::Game::MapGridNum; i++)
        {
            for (int k = 0; k < Global::Game::MapGridNum; k++)
            {
                if (mapObjects[i][k] != NULL)
                {
                    mapObjects[i][k]->Render();
                }
            }
        }
    }
    void End()
    {
        delete mapObjects;
    }
}