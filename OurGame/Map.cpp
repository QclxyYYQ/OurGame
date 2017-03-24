#include"Map.h"
#include"Global.h"
#include"TileObject.h"
#include"BulletObject.h"
#include<list>
#include"PlayerObject.h"
#include"MapTool.h"
namespace Map {
    //MapSize*MapSize大小的矩阵
    BaseObject *mapObjects[Global::Game::MapGridNum][Global::Game::MapGridNum];
    //子弹链表
    list<BulletObject*> bullets;
    //玩家链表
    list<PlayerObject*> players;

    //产生一颗炮弹，belongTo发射者坦克ID，x,y为发射者坦克精灵坐标，dir方向，speed 速度
    void CreateBullet(int belongTo, int x, int y, DIRECTION Dir, float speed)
    {
        BulletObject *b = new BulletObject();
        b->Init(x, y, Dir);
        b->speed = speed;
        b->belongTo = belongTo;
        bullets.push_back(b);
    }
    //创建玩家，x,y为地图坐标
    void CreatePlayer(int id, int x, int y)
    {
        PlayerObject *p = new PlayerObject();
        p->Init(id);
        p->sprite.x = MapTool::GetActualLocationX(x);
        p->sprite.y = MapTool::GetActualLocationY(y);
        players.push_back(p);

    }
    //随机生成地图
    void CreateData()
    {
        srand(GetTickCount());
        for (int i = rand() % Global::Game::MapGridNum; i < Global::Game::MapGridNum; i++)
        {
            for (int k = rand() % Global::Game::MapGridNum; k < Global::Game::MapGridNum; k++)
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
    void RenderPlayers()
    {
        list<PlayerObject*>::iterator iter;
        if (players.size() > 0)
        {
            iter = players.begin();
            while (iter != players.end())
            {
                (*iter)->Render();
                if (players.size() > 0)
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
        RenderPlayers();
    }
    void UpdatePlayers()
    {
        list<PlayerObject*>::iterator iter;
        if (players.size() > 0)
        {
            iter = players.begin();
            while (iter != players.end())
            {
                (*iter)->Update();
                ++iter;
            }
        }
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
        UpdatePlayers();
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