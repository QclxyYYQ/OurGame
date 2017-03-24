#include"Map.h"
#include"Global.h"
#include"TileObject.h"
#include"BulletObject.h"
#include<list>
namespace Map {
    //MapSize*MapSize大小的矩阵
    BaseObject *mapObjects[Global::Game::MapGridNum][Global::Game::MapGridNum];

    list<BulletObject*> bullets;

    //产生一颗炮弹，belongTo发射者坦克ID，x,y为发射者坦克精灵坐标，dir方向，speed 速度
    void CreateBullet(int belongTo, int x, int y, DIRECTION Dir, float speed)
    {
        BulletObject *b = new BulletObject();
        b->Init(x, y, Dir);
        b->speed = speed;
        b->belongTo = belongTo;
        bullets.push_back(b);
    }

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
        //CreateBullet(3, 3, DIRECTION::RIGHT);
    }
    void RenderMap()
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
    void RenderBullets()
    {
        list<BulletObject*>::iterator iter;
        if (bullets.size() > 0)
        {
            iter = bullets.begin();
            while (iter != bullets.end())
            {
                (*iter)->Render();
                if (bullets.size() > 0)
                    ++iter;
                else
                    break;
            }
        }
    }
    void Render()
    {
        RenderMap();
        RenderBullets();

    }
    void UpdateBullets() {
        list<BulletObject*>::iterator iter;
        if (bullets.size() > 0)
        {
            iter = bullets.begin();
            while (iter != bullets.end())
            {
                if ((*iter)->isDeleted)
                {
                    delete (*iter);
                    bullets.erase(iter++);
                }
                else {
                    (*iter)->Update();
                    ++iter;
                }
            }
        }
    }
    void Update() {
        UpdateBullets();
    }
    BaseObject* GetMapObject(int x, int y)
    {
        if (x >= 0 && x < Global::Game::MapGridNum) {
            if (y >= 0 && y < Global::Game::MapGridNum)
            {
                return mapObjects[x][y];
            }
        }
    }
    void End()
    {
        list<BulletObject*>::iterator iter;
        if (bullets.size() > 0)
        {
            iter = bullets.begin();
            while (iter != bullets.end())
            {
                delete (*iter);
                bullets.erase(iter++);
            }
        }
    }
    int GetBulletCount() {
        return bullets.size();
    }
}