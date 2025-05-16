#pragma once
#include "Image.h"
#include<vector>
#include<string>
#include<iostream>
class Scene
{
public:

	

	Scene();
	~Scene();
	void draw();
private:

	Image* bg;
	Image* cardSlot;
	Image* blank;
	Image* scoop;
	std::vector<Image*>cards;
};

