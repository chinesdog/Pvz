#include <vector>
#include "Plant.h"
#include "ZoomBies.h"
#include "Bullets.h"
#include "PeaShooter.h"
#include "NormalZoombie.h"
#include "SunFlowers.h"
#include <fstream>
const int grass_width = 80;
const int grass_height = 95;
const int grass_cols = 9;
const int grass_rows = 5;
const int grass_of_x = 50;
const int grass_of_y = 100;



extern std::vector<PeaShooter*>normalShooters;
extern std::vector<NormalZoombie*>normalZoombies[5];
extern std::vector<Bullets*>bullets;
extern std::vector<SunFlowers*>sunflowers;
extern int map[20][20];
extern int scores;
void updatePlant();
void updateBullet();
void updateZooms();
void recoverSpace();

extern void writesth(std::string title, std::string text);
extern std::string catNumber(int a, int b);
/*
* updateBullet 维护子弹和僵尸的关系
* 
*/

void updateWithNoInput() {
	updatePlant();
	updateBullet();
	updateZooms();
	recoverSpace();
}
void updatePlant() {
	for (std::vector<PeaShooter*>::iterator it = normalShooters.begin(); it != normalShooters.end(); it++) {
		(*it)->update();
		if ((*it)->islauched == 0 && (*it)->shoot_counter == 0) {
			int row = (*it)->row_num;
			if (normalZoombies[row].size() > 0) {
				(*it)->islauched = 1;
				Bullets* bul = new Bullets(*it);
				bul->setPosition((*it)->postion_x+50, (*it)->positon_y);
				bul->shoot_x = (*it)->col_num;
				bul->shoot_y = (*it)->row_num;
				bullets.push_back(bul);
			}
		}
	}
	



}
void updateBullet() {
	for (std::vector<Bullets*>::iterator it = bullets.begin(); it != bullets.end();it++) {

		if ((*it)->state != Bullets::RUN)continue;//子弹无效
		int x = (*it)->shoot_x, y = (*it)->shoot_y;
		PeaShooter* shoot = (*it)->shooter;
		if ((*it)->X >= grass_of_x + grass_cols * grass_width) {
			(*it)->state = Bullets::DIE;
			
			if (map[x][y] != 0) {
				shoot->islauched = 0;
			}
			
		}
		else  {
			
			int row = (*it)->shoot_y;
			for (int i = 0; i < normalZoombies[row].size(); i++) {
				NormalZoombie *zoom = normalZoombies[row][i];
				if (abs( zoom->X - (*it)->X) <=10  ) {
					(*it)->state = Bullets::DIE;
					if (map[x][y] != 0) {
						shoot->islauched = 0;
					}
					zoom->attacked();
					break;
				}
			}
		}
	}
}
//僵尸触碰到植物
void updateZooms() {
	//僵尸状态转变
	for (int i = 0; i < 5; i++) {
		for (std::vector<NormalZoombie*>::iterator it = normalZoombies[i].begin(); it != normalZoombies[i].end();it++ ) {
			if ((*it)->State != ZoomBies::WALK)continue;
			//遍历豌豆
			for (std::vector<PeaShooter*>::iterator plant = normalShooters.begin(); plant != normalShooters.end(); plant++) {
				if ((*plant)->row_num != i)continue;
				

				if (abs((*plant)->postion_x - (*it)->X) <= 10) {
					(*it)->State = ZoomBies::EAT;
					break;
				}
			}
			//遍历向日葵
			for (std::vector<SunFlowers*>::iterator plant = sunflowers.begin(); plant != sunflowers.end(); plant++) {
				if ((*plant)->row_num != i)continue;


				if (abs((*plant)->postion_x - (*it)->X) <= 10) {
					(*it)->State = ZoomBies::EAT;
					break;
				}
			}
		}
	}
	//SunFlowers sunflowers plant
	//开始对植物造成伤害
	for (int i = 0; i < 5; i++) {
		for (std::vector<NormalZoombie*>::iterator it = normalZoombies[i].begin(); it != normalZoombies[i].end(); it++) {
			if ((*it)->State != ZoomBies::EAT)continue;
			bool find_plant = false;
			//遍历豌豆
			for (std::vector<PeaShooter*>::iterator shoot = normalShooters.begin(); shoot != normalShooters.end(); shoot++) {
				if ((*shoot)->row_num != i)continue;


				if (abs((*shoot)->postion_x - (*it)->X) <= 10) {
					(*shoot)->attacked();
					find_plant = true;
					break;
				}
			}
			//遍历向日葵
			for (std::vector<SunFlowers*>::iterator plant = sunflowers.begin(); plant != sunflowers.end(); plant++) {
				if ((*plant)->row_num != i)continue;


				if (abs((*plant)->postion_x - (*it)->X) <= 10) {
					(*plant)->attacked();
					find_plant = true;
					break;
				}
			}
			if (find_plant == false) {
				(*it)->State = ZoomBies::WALK;
			}
		}
	}
}

void recoverSpace() {
	for (std::vector<Bullets*>::iterator it = bullets.begin(); it != bullets.end();) {
		if ((*it)->state == Bullets::RECOVER) {
			delete (*it);
			it = bullets.erase(it);
		}
		else {
			it++;
		}
	}


	for (int i = 0; i < 5; i++) {
		
		for (std::vector<NormalZoombie*>::iterator it = normalZoombies[i].begin(); it != normalZoombies[i].end(); ) {
			if ((*it)->isRecoverd) {
				scores += 1;//分数加1

				//delete (*it);
				it = normalZoombies[i].erase(it);

			}
			else {
				it++;
			}
		}
	}

	//SunFlowers sunflowers plant

	//豌豆
	for (std::vector<PeaShooter*>::iterator it = normalShooters.begin(); it != normalShooters.end(); ) {
		if ((*it)->isRecoverd) {
			int row = (*it)->row_num;
			int col = (*it)->col_num;
			map[col][row] = 0;


			delete(*it);
			it = normalShooters.erase(it);
			
		}
		else {
			it++;
		}
	}
	//向日葵
	for (std::vector<SunFlowers*>::iterator it = sunflowers.begin(); it != sunflowers.end(); ) {
		if ((*it)->isRecoverd) {
			int row = (*it)->row_num;
			int col = (*it)->col_num;
			map[col][row] = 0;


			delete(*it);
			it = sunflowers.erase(it);

		}
		else {
			it++;
		}
	}

}
