#include "HomeScene.h"
#include "Global.h"
#include "DirectX.h"
using namespace Global;
using namespace Global::Window;

bool HomeScene::Create_Background()
{
    background = LoadSurface(Resource::Home::Backgroud);
    return background != NULL;
}

void HomeScene::Draw_Background()
{
    RECT source_rect = {
        0,
        0,
        ScreenWidth,
        ScreenHeight
    };
    d3dDev->StretchRect(background, &source_rect, backBuffer, &source_rect, D3DTEXF_NONE);
}

bool HomeScene::Init()
{
    OutputDebugString("��ӭ������ʼ��ʼ��\n");
    if (!HomeScene::Create_Background())
    {
        ShowMessage("����ͼ����ʧ��");
        return false;
    }
    //DXSound���������룬������ʱֻ֧��wav
    //if (bgm = LoadSound(Resource::Home::BGM), bgm == NULL) {
        //ShowMessage("BGM����ʧ��");
        //return false;
    //}
    //LoopSound(bgm);


    return true;
}
void HomeScene::End()
{
    //�ͷű���ͼ
    background->Release();
    //delete bgm;
}
void HomeScene::Update()
{
    if (Mouse_Button(MLButton))
    {
        OutputDebugString("�������");
    }
}
void HomeScene::Render()
{
    HomeScene::Draw_Background();

}