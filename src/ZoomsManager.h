#pragma once
class ZoomsManager
{
public:
	ZoomsManager();
	bool update();
	int index;
	static const int maxIndex = 30;
private:
	
	
	int counter;
};

