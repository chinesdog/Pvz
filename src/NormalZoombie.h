#pragma once
#include "ZoomBies.h"
class NormalZoombie :
    public ZoomBies
{
public:
    NormalZoombie();
    void attacked();
    int type;
    void init();
private:
    int counter;
};

