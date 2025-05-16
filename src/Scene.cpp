#include "Scene.h"

Scene::Scene() {
	
	bg = new Image("images\\bg5.jpg");
	cardSlot = new Image("images\\bar.png");
	blank = new Image("images\\blank.png");
	scoop = new Image("images\\scoop.png");
	for (int i = 1; i <= 8; i++) {
		std::string name = "images\\cards\\card" + std::to_string(i);
		name += ".png";
		cards.push_back(new Image(name));
	}
}
Scene:: ~Scene() {
	delete bg;
	delete cardSlot;
	delete blank;
	delete scoop;
	for (int i = 1; i <= 8; i++) {
		delete cards[i];
	}
}
void Scene::draw() {
	bg->put(0, 0, 800, 600, 200, 0);
	cardSlot->put(0, 0, SRCCOPY);
	blank->put(620, 0, SRCCOPY);
	scoop->put_transparent(620, 0, 80, 80, 0, 0);
	for (int i = 0; i < 8; i++) {
		cards[i]->put(100 + 60 * i, 10, SRCCOPY);
	}
}
/*
* ¿¨Æ¬ 56*80
* Ö²ÎïÀ¸ÇøÓò (100,10)->(100+420+56,90)
*/