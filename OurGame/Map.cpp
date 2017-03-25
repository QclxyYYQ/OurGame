#include"Map.h"
#include"Global.h"
#include"TileObject.h"
#include"BulletObject.h"
#include<list>
#include"PlayerObject.h"
#include"MapTool.h"
#include"DebugTools.h"
namespace Map {
    //MapSize*MapSize��С�ľ���
    TileObject *mapObjects[Global::Game::MapGridNum][Global::Game::MapGridNum];
    //�ӵ�����
    list<BulletObject*> bullets;
    //�������
    list<PlayerObject*> players;

    //����һ���ڵ���belongTo������̹��ID��x,yΪ������̹�˾������꣬dir����speed �ٶ�
    void CreateBullet(int belongTo, int x, int y, DIRECTION Dir, float speed)
    {
        BulletObject *b = new BulletObject();
        b->Init(x, y, Dir);
        b->speed = speed;
        b->belongTo = belongTo;
        bullets.push_back(b);
    }
    //������ң�x,yΪ��ͼ����
    void CreatePlayer(int id, int x, int y)
    {
        PlayerObject *p = new PlayerObject();
        p->Init(id);
        p->sprite.x = MapTool::GetActualLocationX(x);
        p->sprite.y = MapTool::GetActualLocationY(y);
        players.push_back(p);

    }
    //������ɵ�ͼ
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
    //���ļ������ͼ
    void LoadData()
    {

    }
    //����ͼд���ļ�
    void SaveData()
    {

    }
    void Init() {
        //mapObjects = (TileObject *)calloc(Global::Game::MapGridNum*Global::Game::MapGridNum, sizeof(TileObject *));
        for (int i = 0; i < Global::Game::MapGridNum; i++)
        {
            for (int k = 0; k < Global::Game::MapGridNum; k++)
            {
                mapObjects[i][k] = NULL;
            }
        }
        CreateData();
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
                DebugTools::PrintGrid((*iter)->sprite.x, (*iter)->sprite.y, D3DCOLOR_XRGB(128, 128, 128));
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

    TileObject* GetMapObject(int x, int y)
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

    //ȡ��ǰ�����������������ͼ���飬������Ļ����x��y
    int GetNearTile(DIRECTION dir, int x, int y, TileObject** t)
    {
        t[0] = GetMapObject(MapTool::GetMapLocationX(x), MapTool::GetMapLocationY(y));
        t[1] = NULL;

        switch (dir)
        {
        case UP:
        case DOWN:
            if (x%Global::Game::UnitSize > 0)
            {
                t[1] = GetMapObject(MapTool::GetMapLocationX(x) + 1, MapTool::GetMapLocationY(y));
            }
            return 2;
        case RIGHT:
        case LEFT:
            if (y%Global::Game::UnitSize > 0)
            {
                t[1] = GetMapObject(MapTool::GetMapLocationX(x), MapTool::GetMapLocationY(y) + 1);
            }
            return 2;
        default:
            break;
        }
        return 1;
    }
}