#pragma once
#include"Scene.h"
//��ӭ����
class HomeScene : public virtual Scene
{
public:
    bool Init();

    void End();

    void Update();

    void Render();
    
private:
    LPDIRECT3DSURFACE9 background = NULL;

    LPD3DXFONT font;
private:
    void Draw_Background();
    bool Create_Background();
};

