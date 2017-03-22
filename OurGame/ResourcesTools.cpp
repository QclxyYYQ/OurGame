#include"ResourcesTools.h"
#include"DirectX.h"
#include <list>

namespace ResourcesTools {

    list<LPDIRECT3DTEXTURE9> textures;

    LPDIRECT3DTEXTURE9 Load(char * filename)
    {
        D3DXIMAGE_INFO Info;
        //得到图片文件信息到Info
        if (D3D_OK != (D3DXGetImageInfoFromFile(filename, &Info)))
        {
            MessageBox(NULL, "得到图象信息错误!", "LOAD PIC ERROR", MB_OK);
        }
        LPDIRECT3DTEXTURE9 texture = LoadTexture(Resource::Cursor::Normal);
        if (!texture) return NULL;

        textures.push_back(texture);
        //返回最后一个刚刚推进来的元素
        return *textures.rbegin();
    }

    ANIMATE* doCreateAnimate(LPDIRECT3DTEXTURE9 texture, int WidthCount, int UnitWidth, int HeightCount, int UnitHeight, int dir, float grapTime)
    {
        ANIMATE ani;
        ani.count = WidthCount*HeightCount;
        ani.grapTime = grapTime;
        ani.sprites = (SPRITE*)calloc(ani.count, sizeof(SPRITE));
        //横向扫描
        if (dir == 0)
        {
            for (int i = 0; i < HeightCount; i++)
            {
                for (int j = 0; j < WidthCount; j++)
                {
                    
                }
            }
        }
        else {

        }
        return NULL;
    }
    void ReleaseTextures()
    {
        list<LPDIRECT3DTEXTURE9>::iterator iter = textures.begin();

        for (int i = 0; i < textures.size(); i++)
        {
            (*iter)->Release();
            iter++;
        }
    }
}