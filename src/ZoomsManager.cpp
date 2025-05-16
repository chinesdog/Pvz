#include "ZoomsManager.h"
ZoomsManager::ZoomsManager() {
	index = 0;
	
}
bool ZoomsManager::update() {
	counter = (counter + 1) % 100;
	if (counter == 1)return true;
	
	return false;
}