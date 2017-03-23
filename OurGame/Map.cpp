#include"Map.h"
#include"Global.h"
#include"TileObject.h"
namespace Map {
    //MapSize*MapSize´óÐ¡µÄ¾ØÕó
    BaseObject *mapObjects[Global::Game::MapGridNum][Global::Game::MapGridNum];
    void CreateData()
    {
        srand(GetTickCount());
        /*
        int s = rand() % 8;
        mapObjects[0][0] = new TileObject();
        mapObjects[0][0]->Init((ObjectType)s, 0, 0);
        */
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
    void LoadData()
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