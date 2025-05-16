#pragma once
#include<string>
#include<iostream>
#include<vector>
#include"Image.h"
class Animation
{
public:
	Animation(std::string filename,int w,int h,int rows,int cols,int cnt);
	~Animation();
	std::string filename;
	int width;
	int height;
	int rows;
	int cols;
	int cnt;
	
	int postion_x;
	int positon_y;
	Image *images;
	void setposition(int x, int y);
	void play();
	bool play_ones();
	
	
private:
	int counter;
	
};

