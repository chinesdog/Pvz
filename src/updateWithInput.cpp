#include <graphics.h>	
#include<string>
#include<iostream>
#include<fstream>
#include<vector>
#include "Plant.h"
#include "PeaShooter.h"
#include "SunFlowers.h"
#include "Sun.h"

const int grass_width	=  80;
const int grass_height	 = 95;
const int grass_cols	= 9;
const int grass_rows	= 5;
const int grass_of_x	= 50;
const int grass_of_y	= 100;


void putPlate(int x,int y);

void selectPlant(int x, int y);
void giveupPlant();
void writesth(std::string title, std::string text);
void catchSun(int x,int y);
std::string catNumber(int a, int b);


extern int map[20][20];
extern int sunshine_num;
extern Plant* PlantFollowMouse;
extern std::vector<PeaShooter*>normalShooters;
extern std::vector<SunFlowers*>sunflowers;
extern std::vector<Sun*>suns;
extern int sunshine_num;
MOUSEMSG M;
int current_PlantNum;

void updateWithInput() {
	
	while (MouseHit()) {
		M = GetMouseMsg();
		if (M.uMsg != WM_LBUTTONDOWN) {				// 检测有效鼠标点击（左键点击）
			continue;
		}		
		catchSun(M.x, M.y);
		if ( M.x >= 100 && M.x <= 100 + 420 + 56 && M.y >= 10 && M.y <= 90) {
			if (PlantFollowMouse==NULL) {
				selectPlant(M.x, M.y);
			}
			else {
				giveupPlant();
			}
			break;
					
		}
		if (PlantFollowMouse != NULL && M.x >= grass_of_x && M.x <= grass_of_x + grass_cols * grass_width &&
			M.y >= grass_of_y && M.y <= grass_of_y + grass_height * grass_rows) {

			putPlate(M.x, M.y);
			break;
		}
		
	}
	
}
void catchSun(int x,int y) {
	for (std::vector<Sun*>::iterator it = suns.begin(); it != suns.end(); ) {
		int sun_x = (*it)->X, sun_y = (*it)->Y;
		if (x >= sun_x && x <= sun_x + 80 && y >= sun_y && y <= sun_y + 80) {
			sunshine_num += 50;
			delete(*it);
			it = suns.erase(it);
		}
		else {
			it++;
		}
	}
}
void selectPlant(int x, int y) {
	int num = (x - 100) / 60;
	/*writesth("选中植物",std::to_string(num ));*/
	// 豌豆 向日葵 樱桃 坚果 土豆 寒冰 大嘴花 双向豌豆
	if (num == 0 && sunshine_num >= PeaShooter::getprice()) {
		PlantFollowMouse = new PeaShooter(M.x-30, M.y-30);
		current_PlantNum = 0;
	}
	else if (num == 1 && sunshine_num >= SunFlowers::getprice()) {
		PlantFollowMouse = new SunFlowers(M.x - 30, M.y - 30);

		current_PlantNum = 1;
	}
	
}
void putPlate(int x, int y) {

	int yy = (y - grass_of_y) / grass_height;
	int xx = (x - grass_of_x) / grass_width;

	if (map[xx][yy] == 0) {
		map[xx][yy] = 1;
	}
	else {
		
		return;
	}
	giveupPlant();
	switch (current_PlantNum)
	{
	case 0:
		
	{
		sunshine_num -= PeaShooter::getprice();
		PeaShooter* it = new PeaShooter(grass_of_x + xx * grass_width, grass_of_y + yy * grass_height);
		
		it->row_num = yy;
		it->col_num = xx;
		normalShooters.push_back(it);

		break;
	}
		
	case 1:
		//Plants.push_back(new SunFlowers(grass_of_x + xx * grass_width, grass_of_y + yy * grass_height));
	{
		sunshine_num -= SunFlowers::getprice();
		SunFlowers* it = new SunFlowers();
		it->setPosition(grass_of_x + xx * grass_width, grass_of_y + yy * grass_height);
		it->row_num = yy;
		it->col_num = xx;
		sunflowers.push_back(it);
		break;
	}
		
	default:
		break;
	}
	

}


void giveupPlant() {
	if (PlantFollowMouse == NULL)return;
	delete PlantFollowMouse;
	PlantFollowMouse = NULL;
}


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