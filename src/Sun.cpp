#include "Sun.h"
Sun::Sun(int x,int y) {
	animations = new Animation("animations\\bullets\\sun.png", 483/6, 159/2, 2, 6, 12);
	X = x;
	Y = y;
	animations->setposition(X, Y);
}
Sun::~Sun() {
	delete animations;
}
void Sun::update() {
	animations->play();
}
bool Sun::tick() {
	counter++;
	if (counter % 200 == 0) {
		return true;
	}
	return false;
}
void Sun::setposition(int x,int y) {
	animations->setposition(x, y);
}