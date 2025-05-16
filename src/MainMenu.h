#pragma once
#include "Image.h"
class MainMenu
{
public:
	MainMenu();
	~MainMenu();
	void draw();
private:
	Image* bg;
	Image* board_game;
	Image* board_label;
	Image* bg2;
	Image* bg3;
};

