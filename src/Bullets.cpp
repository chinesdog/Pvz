#include "Bullets.h"
Bullets::Bullets(PeaShooter* shooter) {
	this->shooter = shooter;
	image = new Animation("animations\\bullets\\pea.png", 28, 28, 1, 1, 1);
	effects = new Animation("animations\\effects\\Pea_splats.png", 96 / 4, 24, 1, 4, 4);
	speed = 10;
	state = RUN;
}
Bullets:: ~Bullets() {
	delete image;
	delete effects;
}
void Bullets::setPosition(int x, int y) {
	X = x;
	Y = y;
	image->setposition(x, y);
	effects->setposition(x, y);
}
void Bullets::update() {
	const int grass_width = 80;
	const int grass_height = 95;
	const int grass_cols = 9;
	const int grass_rows = 5;
	const int grass_of_x = 50;
	const int grass_of_y = 100;
	if (state == RUN) {
		if (X <= grass_of_x + grass_width * grass_cols) {
			setPosition(X + speed, Y);

		}
		image->play();
	}
	else if (state == DIE) {
		setPosition(X, Y);
		bool ok = effects->play_ones();
		if (ok) {
			state = RECOVER;
		}
	}
	
	

	
	
	
}

/*
* const int grass_width = 80;
const int grass_height = 95;
const int grass_cols = 9;
const int grass_rows = 5;
const int grass_of_x = 50;
const int grass_of_y = 100;
*/