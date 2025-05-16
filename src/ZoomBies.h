#pragma once
#include "Animation.h"
#include <vector>
class ZoomBies
{
public:
	ZoomBies(int speed, int health,int attack);
	~ZoomBies();
	enum MyEnum
	{
		STAND, WALK, EAT, WALK2, EAT2, DIE, DIE2, ASH, HEAD, HEAD2
	};
	bool isRecoverd;
	void setPositon(int x,int y);
	void Play();
	
	int X;
	int Y;
	int State;
	void update();
protected:
	int speed_x;
	int health;
	int attack;
	int walk_counter;
	std::vector<Animation*>Actions;
	
	
};

