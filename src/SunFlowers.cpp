#include "SunFlowers.h"
// Ê®µÎÑª 50¾­¼Ã
//:Plant("animations\\plants\\sunflower.png", 483 / 6, 320 / 4, 4, 6, 24) 
SunFlowers:: SunFlowers():Plant("animations\\plants\\sunflower.png", 483 / 6, 320 / 4, 4, 6, 24) {
	//normal = new Animation("animations\\plants\\sunflower.png", 483 / 6, 320 / 4, 4, 6, 24);
	shine = new Animation("animations\\plants\\sunflower_1.png", 483 / 6, 320 / 4, 4, 6, 24);
	state = NORMAL;
	sun_counter = 0;
	health = 100;
	isRecoverd = false;
}
SunFlowers::SunFlowers(int x, int y) :Plant("animations\\plants\\sunflower.png", 483 / 6, 320 / 4, 4, 6, 24) {
	setposition(x, y);
}
int SunFlowers::getprice() {
	return 50;
 }
int SunFlowers::update() {
	sun_counter = (sun_counter + 1) % 600;
	if (sun_counter >=400) {
		state = SHINE;
	}
	else {
		state = NORMAL;
	}
	if (state == NORMAL) {
		play();
	}
	else if (state == SHINE) {
		shine->play();
	}
	return sun_counter;
}
void SunFlowers::attacked() {
	health -= 1;
	if (health <= 0) {
		isRecoverd = true;
	}
}
void SunFlowers::setPosition(int x,int y) {
	//normal->setposition(x, y);
	setposition(x,y);
	shine->setposition(x, y);
}