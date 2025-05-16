#include "winOrLose.h"
winOrLose:: winOrLose() {
	win = new Image("images\\win.jpg");
	lose= new Image("images\\lose.jpg");
	state = NORMAL;
}
winOrLose:: ~winOrLose() {
	delete win;
	delete lose;
}
bool winOrLose:: update() {
	if (state == WIN) {
		win->put(0, 0, SRCCOPY);
	}
	else if (state == LOSE) {
		lose->put(0, 0, SRCCOPY);
	}
	counter = (counter + 1) % 100;
	if (counter == 99) {
		return true;
	}
	return false;
}