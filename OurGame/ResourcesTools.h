#pragma once
#include"DirectX.h"
namespace ResourcesTools {
    struct ANIMATE {
        //帧数
        int count;
        //间隔时间
        float grapTime;
        //每一帧的精灵
        SPRITE *sprites;
    };
}