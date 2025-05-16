#include "ZoomBies.h"
ZoomBies::ZoomBies(int speed, int health, int attack) {
	State = 0;
	this->speed_x = speed;
	this->health = health;
	this->attack = attack;
	walk_counter = 0;
	isRecoverd = false;
}
ZoomBies:: ~ZoomBies() {
	for (int i = 0; i < Actions.size(); i++)delete Actions[i];
}
void ZoomBies:: setPositon(int x,int y) {
	X = x;
	Y = y;
	
	for (int i = 0; i < Actions.size(); i++)Actions[i]->setposition(x, y);
}
void ZoomBies::Play(){
	
	Actions[State]->play();
}

void  ZoomBies::update() {
	
	if (State == DIE) {
		bool ok=Actions[State]->play_ones();
		if (ok) {
			isRecoverd = true;
		}
	}
	else if (State == WALK) {

		walk_counter = (walk_counter + 1) % 10;
		if (walk_counter == 0) {
			setPositon(X - speed_x, Y);
		}

		Actions[State]->play();
	}
	else if (State == EAT) {
		Actions[State]->play();
	}
	
	
}