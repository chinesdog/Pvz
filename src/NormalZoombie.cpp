#include "NormalZoombie.h"
//2ÐÐ×ß 10ÑªÁ¿ 1¹¥»÷
NormalZoombie::NormalZoombie():ZoomBies(6,10,1) {
	//STAND,WALK,EAT,WALK2,EAT2,DIE,DIE2,ASH,HEAD,HEAD2
	
	Actions.push_back(new Animation("animations\\zombies\\normal\\stand.png", 166, 1584 / 11, 11, 1, 11));
	Actions.push_back(new Animation("animations\\zombies\\normal\\walk.png", 1000 / 10, 695 / 5, 5, 10, 46));
	Actions.push_back(new Animation("animations\\zombies\\normal\\eat.png", 1000 / 10, 556 / 4, 4, 10, 39));

	Actions.push_back(new Animation("animations\\zombies\\normal\\walk_1.png", 1000 / 10, 695 / 5, 5, 10, 46));
	Actions.push_back(new Animation("animations\\zombies\\normal\\eat_1.png", 1000 / 10, 556 / 4, 4, 10, 39));

	Actions.push_back(new Animation("animations\\zombies\\normal\\die.png", 166 ,1440/10, 10, 1, 10));
	Actions.push_back(new Animation("animations\\zombies\\normal\\die_1.png", 166, 1440 / 10, 10, 1, 10));
	Actions.push_back(new Animation("animations\\zombies\\normal\\ash.png", 100, 2880/20, 20, 1, 20));

	Actions.push_back(new Animation("animations\\zombies\\normal\\head.png", 150, 2232/12, 12, 1, 12));
	Actions.push_back(new Animation("animations\\zombies\\normal\\head_1.png", 150, 2232 / 12, 12, 1, 12));
}
void NormalZoombie:: attacked() {
	health -= 1;
	if (health <= 0) {
		State = DIE;
	}
}
void NormalZoombie:: init() {
	speed_x = 6;
	health = 10;
	attack = 1;
	isRecoverd = false;

}