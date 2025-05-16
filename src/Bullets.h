#pragma once
#include "Animation.h"
#include "PeaShooter.h"
class Bullets
{
public:
	Bullets(PeaShooter *shooter);
	~Bullets();
	enum STATE
	{
		RUN,DIE,RECOVER
	};
	void setPosition(int x, int y);
	void update();
	PeaShooter* shooter;
	int X, Y;
	int state;
	int shoot_x;
	int shoot_y;
private:
	Animation* image;
	Animation* effects;
	int speed;
	
	int fly_counter;
};

