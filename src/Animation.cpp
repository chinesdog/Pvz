#include "Animation.h"
Animation::Animation(std::string filename, int w, int h, int rows, int cols,int cnt) {
	this->filename = filename;
	this->width = w;
	this->height = h;
	this->cols = cols;
	this->rows = rows;
	this->cnt = cnt;
	this->counter = 0;
	this->images = new Image(filename);
}
Animation::~Animation() {
	delete images;
}
void Animation ::play() {
	int x = counter % cols;
	int y = counter / cols;
	this->images->put_transparent(postion_x, positon_y, width, height, x * width, y * height);
	counter = (counter + 1) % cnt;

}
bool Animation::play_ones() {
	if (counter < cnt) {
		int x = counter % cols;
		int y = counter / cols;
		this->images->put_transparent(postion_x, positon_y, width, height, x * width, y * height);
	}
	else {
		return true;
	}
	counter = counter + 1;
	return false;
}
void Animation:: setposition(int x, int y) {
	positon_y = y;
	postion_x = x;
}
