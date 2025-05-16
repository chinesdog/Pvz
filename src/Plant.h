#pragma once
#include "Animation.h"
#include<iostream>
#include<string>
class Plant :public Animation
{
public:
	enum PlantType
	{
		SHOOT,ECONOMIC
	};
	Plant(std::string filename, int w, int h, int rows, int cols, int cnt);
};

