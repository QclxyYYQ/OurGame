#include"Map.h"
#include"Global.h"
#include"TileObject.h"
namespace Map {
    int MapSize;
    //MapSize*MapSize´óÐ¡µÄ¾ØÕó
    BaseObject** mapObjects = NULL;
    TileObject *tileObjects = NULL;
    TileObject *tile = NULL;
    char** mapData;
    void doCreateObject(ObjectType type)
    {
        switch (type)
        {
        case Brick:
            break;
        case Steel:
            break;
        case Grass:
            break;
        case DeepWater:
            break;
        case ShallowWater:
            break;
        case Snow:
            break;
        case Soil:
            break;
        case King:
            break;
        case Enemy:
            break;
        case Player:
            break;
        default:
            break;
        }
    }
    void CreateData()
    {
        srand(GetTickCount());

        mapData = new char*[MapSize];
        for (int i = 0; i < MapSize; i++)
        {
            mapData[i] = (char*)new char[MapSize];
            rand() % 8;
        }

    }
    void LoadData()
    {

    }
    void Init() {
        MapSize = Global::Game::MapSize / Global::Game::UnitSize;

        CreateData();

        tile = new TileObject();
        tile->Init(ObjectType::Grass, 3, 4);

        mapObjects = new BaseObject*[MapSize];
        for (int i = 0; i < MapSize; i++)
            mapObjects[i] = (BaseObject*)new BaseObject[MapSize];
    }
    void Render()
    {
        if (tile != NULL)
        {
            tile->Render();
            for (int i = 0; i < MapSize; i++)
            {
                for (int k = 0; k < MapSize; k++)
                {
                    /*if (mapObjects[i][k] != NULL)
                    {

                    }*/
                }
            }
        }
    }
    void End()
    {
        delete mapObjects;
    }
}