#include "ZoomsManager.h"
#include "NormalZoombie.h"
#include "Sun.h"
#include "winOrLose.h"
extern ZoomsManager* zoomsManager;
extern std::vector<NormalZoombie*>normalZoombies[5];
extern std::vector<NormalZoombie*>allnormalZooms;
extern std::vector<Sun*>suns;
extern int getRand(int min, int max);
extern winOrLose* gameover;
const int grass_width = 80;
const int grass_height = 95;
const int grass_cols = 9;
const int grass_rows = 5;
const int grass_of_x = 50;
const int grass_of_y = 100;
void updateZoomScene() {
	bool ok = zoomsManager->update();
	if (ok) {
		
		int p= getRand(0, 4);
		int index = zoomsManager->index;
		
		if (index < zoomsManager->maxIndex) {

			NormalZoombie* normal = allnormalZooms[index];
			normal->setPositon(grass_of_x + grass_width * grass_cols, grass_of_y - grass_height + 50 + p * grass_height);
			normal->State = ZoomBies::WALK;
			normalZoombies[p].push_back(normal);
			normal->init();
			zoomsManager->index++;
		}
		
		/*for (int i = 0; i < 5; i++) {
			NormalZoombie* normal = new NormalZoombie();
			normal->setPositon(grass_of_x + grass_width * grass_cols, grass_of_y - grass_height + 50+i*grass_height );
			normal->State = ZoomBies::WALK;
			normalZoombies[i].push_back(normal);
		}*/
		if (zoomsManager->index == ZoomsManager::maxIndex) {
			int exsit = 0;
			for (int i = 0; i < 5; i++) {
				if (normalZoombies[i].size() > 0) {
					exsit = 1;
				}
			}
			if (exsit == 0) {
				gameover->state = winOrLose::WIN;
			}
		}
		
		for (int i = 0; i < 5; i++) {
			for (std::vector<NormalZoombie*>::iterator it = normalZoombies[i].begin(); it != normalZoombies[i].end(); it++) {
				if ((*it)->X <= 0) {
					gameover->state = winOrLose::LOSE;
				}

			}
		}

	}
	
}