#pragma once
#include "Plant.h"
class PeaShooter :public Plant
{
public:
	PeaShooter(int x,int y);
	void update();
	void attacked();
	int row_num;
	int col_num;
	int islauched;
	int shoot_counter;
	bool isRecoverd;
	static int getprice();
private:
	int health;
	
};

