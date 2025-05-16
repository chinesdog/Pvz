#include <graphics.h>		// 引用图形库头文件
#include <conio.h>
#include<iostream>
#include<string.h>
#include<string>
#include<vector>
#include "Plant.h"
#include "ZoomsManager.h"
#include "Image.h"
#include "Scene.h"
#include "MainMenu.h"
#include "winOrLose.h"
#include "NormalZoombie.h"
#include "PeaShooter.h"
#include "SunFlowers.h"
#include "Bullets.h"
#include "Sun.h"
#include <ctime>
#include <cstdlib>


extern void updateWithInput();
extern void updateWithNoInput();
extern void updateZoomScene();
extern void draw();
extern void drawMainMenu();
extern void drawRankLists();
extern void writeRankingList(int score);
extern void loadRankingList();
extern int rankingList[11];
extern void writesth(std::string title, std::string text);
extern std::string catNumber(int a, int b);

void Game();
int enter();
void selectPlant(int x, int y);
void init();
bool loadRes();
void drawLoadScene();
void getBackRes();

const int width = 800;
const int height = 600;
const int init_sunNum=300;
int map[20][20];
int sunshine_num;
int scores;//杀死僵尸数
Plant* PlantFollowMouse;
ZoomsManager* zoomsManager;
MOUSEMSG M_main;
Image* rank_memu;
Image* load_bg;
Image* load_block;
Image* load_srollBar;
Scene* scene;
MainMenu* mainmenu;
std::vector<NormalZoombie*>allnormalZooms;

std::vector<PeaShooter*>normalShooters;
std::vector<SunFlowers*>sunflowers;
std::vector<NormalZoombie*>normalZoombies[5];
std::vector<Bullets*>bullets;
std::vector<Sun*>suns;
winOrLose* gameover;
int load_pt = 0;

int main() {
		
	//资源加载
	//更新历史分数排行榜


	initgraph(width, height);
	init();
	
	while (!loadRes()) {
		drawLoadScene();
	}

	while (1) {

		drawMainMenu();
		int state = enter();
		if (state == 0) {
			Game();
		}
		else if (state == 1) {
			drawRankLists();
			
		}
	
	}
	_getch();				// 按任意键继续
	closegraph();			// 关闭绘图窗口
	return 0;
}
void drawLoadScene() {
	BeginBatchDraw();
	cleardevice();
	
	load_bg->put(0, 0, SRCCOPY);
	load_srollBar->put_transparent(200, 500, 321, 53, 0, 0);

	load_block->put_transparent(200+(320/ZoomsManager::maxIndex)*load_pt, 480, 73, 71, 0, 0);

	EndBatchDraw();
}
bool loadRes() {
	allnormalZooms.push_back(new NormalZoombie());
	load_pt += 1;
	if (load_pt >= ZoomsManager::maxIndex) {
		return true;
	}
	return false;
}



void init() {

	
	gameover = new winOrLose();
	srand(time(0));
	loadRankingList();
	scene = new Scene();
	mainmenu = new MainMenu();
	rank_memu = new Image("images\\Rank.jpg");
	load_bg = new Image("images\\loadingbg.png");
	load_srollBar = new Image("images\\LoadBar.png");
	load_block = new Image("images\\SodRollCap.png");

	setbkmode(TRANSPARENT);
	settextcolor(RED);
	setlinecolor(YELLOW);
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 5; j++) {
			map[i][j] = 0;
		}
	}
	sunshine_num = init_sunNum;
	scores = 0;
	zoomsManager = new ZoomsManager();
	/*for (int i = 0; i <ZoomsManager::maxIndex; i++) {
		allnormalZooms.push_back(new NormalZoombie());

	}*/
}


void Game() {
	//2 加载所有的游戏资源

	while (1) {
		Sleep(50);
		
		draw();
		updateWithNoInput();
		updateWithInput();
		updateZoomScene();

		if (gameover->state == winOrLose::QUIT) {

			writeRankingList(scores);
			getBackRes();

			break;
		}
		
	}
}

void getBackRes() {
	sunshine_num = init_sunNum;
	scores = 0;
	memset(map, 0, sizeof(map));
	zoomsManager->index = 0;//僵尸更新为0
	gameover->state = winOrLose::NORMAL;
	if (PlantFollowMouse != nullptr) {
		delete PlantFollowMouse;
		PlantFollowMouse = nullptr;
	}
	//回收豌豆
	for (std::vector<PeaShooter*>::iterator it = normalShooters.begin(); it != normalShooters.end(); ) {
		int row = (*it)->row_num;
		int col = (*it)->col_num;
		map[col][row] = 0;
		delete(*it);
		it = normalShooters.erase(it);
	}
	//回收向日葵
	for (std::vector<SunFlowers*>::iterator it = sunflowers.begin(); it != sunflowers.end(); ) {
		int row = (*it)->row_num;
		int col = (*it)->col_num;
		map[col][row] = 0;
		delete(*it);
		it = sunflowers.erase(it);
	}
	//回收子弹
	for (std::vector<Bullets*>::iterator it = bullets.begin(); it != bullets.end();) {
		delete (*it);
		it = bullets.erase(it);
	}
	//回收僵尸
	for (int i = 0; i < 5; i++) {
		for (std::vector<NormalZoombie*>::iterator it = normalZoombies[i].begin(); it != normalZoombies[i].end(); ) {
			it = normalZoombies[i].erase(it);
		}
	}
}


int enter() {
	while (MouseHit()) {
		M_main = GetMouseMsg();
		if (M_main.uMsg == WM_LBUTTONDOWN) {
			int x = M_main.x, y = M_main.y;
			if (x >= 400 && x <= 400 + 311 && y >= 50 && y <= 50 + 145) {
				return 0;
			}
			else if (x >= 20 && x <= 20 + 239 && y >= 20 && y <= 20 + 150) {
				return 1;
			}
		}
	}
	return -1;
}

