#pragma once
#include "Animation.h"
class Sun 
{
public:
	Sun(int x,int  y);
	~Sun();
	void update(); 
	void setposition(int x,int y);
	bool tick();
	int X, Y;
	
private:
	 Animation* animations;
	 int counter;

};

