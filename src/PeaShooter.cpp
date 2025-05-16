#include "PeaShooter.h"
PeaShooter::PeaShooter( int x,int y):Plant("animations\\plants\\peashooter.png",483/6,320/4,4,6,24) {
	setposition(x, y);
	islauched = 0;
	shoot_counter = 0;
	//100µÎÑª
	health = 100;
	isRecoverd = false;
}
int PeaShooter:: getprice() {
	return 100;
}
void PeaShooter::update() {
	shoot_counter = (shoot_counter + 1) % 20;
}
void PeaShooter::attacked() {
	health -= 1;
	if (health <= 0) {
		isRecoverd = true;
	}
}

