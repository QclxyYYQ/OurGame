#include"Map.h"
#include"Global.h"
#include"TileObject.h"
namespace Map {
    //MapSize*MapSize��С�ľ���
    BaseObject *mapObjects[Global::Game::MapGridNum][Global::Game::MapGridNum];

    //������ɵ�ͼ
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
    //���ļ������ͼ
    void LoadData()
    {

    }
    //����ͼд���ļ�
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
    BaseObject GetNearObject()
    {
        return BaseObject();
    }
    void End()
    {
        delete mapObjects;
    }
}