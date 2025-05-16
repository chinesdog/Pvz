#pragma once
#include "Animation.h"
#include "Plant.h"
class SunFlowers :public Plant
{
public:
    enum STATE
    {
        NORMAL,SHINE
    };
    int row_num;
    int col_num;
    bool isRecoverd;
    SunFlowers();
    SunFlowers(int x,int y);
    void attacked();
    int update();
    void setPosition(int x,int y);
    static int getprice();
private:
                     
    int sun_counter;
    int state;
    //Animation* normal;
    Animation* shine;
    int health;
};

