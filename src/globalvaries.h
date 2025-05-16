#pragma once
#include <graphics.h>
#include<conio.h>
#include<string>
#include<iostream>
#include<fstream>

//形同虚设的头文件
#include<vector>
#include"Plant.h"
const int grass_width = 80;
const int grass_height = 95;
const int grass_cols = 9;
const int grass_rows = 5;
const int grass_of_x = 50;
const int grass_of_y = 100;

 std::vector<Plant*>Plants;
 void writesth(std::string title, std::string text) {
	std::ofstream outfile;
	outfile.open("logout.txt", std::ios_base::app);
	outfile << title << ": " << text << std::endl;
	outfile.close();
}
 std::string catNumber(int a, int b) {
	std::string res;
	res += std::to_string(a) + ":" + std::to_string(b);
	return res;
}

/*
* 豌豆 向日葵 樱桃 坚果 土豆 寒冰 大嘴花 双向豌豆
*/

 /*
 *		地图范围
 *		grass_of_x &&   grass_of_x + grass_cols * grass_width
		grass_of_y &&  grass_of_y + grass_height * grass_rows
		僵尸
		y+=50
		豌豆
		x+=50
		判断子弹掉出范围
		x>=grass_of_x+ grass_cols * grass_width
		判断子弹撞击僵尸
		zoom_x-x<=-10
		僵尸出场位置
		grass_of_x+grass_width*grass_cols, grass_of_y-grass_height+50
		每隔10秒刷新一次僵尸
		阳光位置 x,y,extend_length
		显示阳光
		20 70
 */