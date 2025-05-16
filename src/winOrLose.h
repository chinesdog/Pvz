#pragma once
#include "Image.h"
class winOrLose
{
public:
	winOrLose();
	~winOrLose();
	enum STATE
	{
		NORMAL,WIN,LOSE,QUIT
	};
	int state;
	bool update();
private:
	Image* win;
	Image* lose;
	int counter;
};

