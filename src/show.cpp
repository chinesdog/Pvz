
#include <graphics.h>		// 引用图形库头文件
#include <conio.h>
#include<iostream>
#include<string.h>
#include<string>
#include<vector>

#include "Scene.h"
#include "PeaShooter.h"
#include "SunFlowers.h"
#include "Image.h"
#include "NormalZoombie.h"
#include "Bullets.h"
#include "MainMenu.h"
#include "Sun.h"
#include "winOrLose.h"
extern std::vector<PeaShooter*>normalShooters;
extern std::vector<SunFlowers*>sunflowers;
extern std::vector<NormalZoombie*>normalZoombies[5];
extern std::vector<Bullets*>bullets;
extern std::vector<Sun*>suns;
extern Plant* PlantFollowMouse;
extern Image * rank_memu;
extern int rankingList[11];
extern Scene* scene;
extern MainMenu* mainmenu;
extern winOrLose* gameover;

const int grass_width = 80;
const int grass_height = 95;
const int grass_cols = 9;
const int grass_rows = 5;
const int grass_of_x = 50;
const int grass_of_y = 100;
bool leave();
extern int sunshine_num;
MOUSEMSG M_rank;

void draw() {

	if (gameover->state == winOrLose::WIN || gameover->state==winOrLose::LOSE) {
		BeginBatchDraw();
		cleardevice();
		bool quit=gameover->update();
		if (quit) {
			gameover->state = winOrLose::QUIT;
		}
		EndBatchDraw();
		return;
	}
	else if (gameover->state == winOrLose::QUIT) {
		return;
	}

	BeginBatchDraw();
	cleardevice();
	scene->draw();
	//更新豌豆射手
	for (std::vector<PeaShooter*>::iterator  it = normalShooters.begin(); it != normalShooters.end(); it++) {
		(*it)->play();
	}
	//更新向日葵
	for (std::vector<SunFlowers*>::iterator it = sunflowers.begin(); it != sunflowers.end(); it++) {
		int cnt=(*it)->update();
		if (cnt == 450) {
			suns.push_back(new Sun((*it)->postion_x, (*it)->positon_y));
		}
	}
	if (PlantFollowMouse!=NULL) {
		PlantFollowMouse->play();
	}

	//更新普通僵尸
	for (int i = 0; i < 5; i++) {
		for (std::vector<NormalZoombie*>::iterator it = normalZoombies[i].begin(); it != normalZoombies[i].end(); it++) {
			(*it)->update();
		}
	}
	
	//更新豌豆子弹
	for (std::vector<Bullets*>::iterator it = bullets.begin(); it != bullets.end(); it++) {
		(*it)->update();
	}
	//更新阳光
	for (std::vector<Sun*>::iterator it = suns.begin(); it != suns.end(); it++) {
		(*it)->update();
	}
	
	TCHAR s[5];
	_stprintf_s(s, _T("%d"), sunshine_num);		// 高版本 VC 推荐使用 _stprintf_s 函数
	outtextxy(20, 75, s);
	EndBatchDraw();
}


void drawMainMenu() {
	BeginBatchDraw();
	cleardevice();
	mainmenu->draw();
	//20, 20, 239, 150, 0, 0
	//140 120
	outtextxy(140, 120, _T("排行榜"));
	EndBatchDraw();
}
void drawRankLists() {
	
	while (1) {

		

		BeginBatchDraw();

		cleardevice();
		rank_memu->put(0, 0, SRCCOPY);
		rectangle(0, 0, 100, 50);
		outtextxy(10, 20, _T("返回主界面"));

		//写用户的数据上去
		for (int i = 0; i < 11; i++) {
			TCHAR s[5];
			_stprintf_s(s, _T("%d"), rankingList[i]);
			outtextxy(300, (i+2)*40, s);
			_stprintf_s(s, _T("%d"), i+1);
			outtextxy(200, (i + 2) * 40, s);
		}

		EndBatchDraw();
		if (leave()) {
			return;
		}

	}

	
}
bool leave() {
	while (MouseHit()) {
		M_rank = GetMouseMsg();
		if (M_rank.uMsg == WM_LBUTTONDOWN) {
			int x = M_rank.x, y = M_rank.y;
			if (x >= 0 && x <= 100 && y >= 0 && y <= 50) {
				return true;
			}
		}
	}
	return false;
}