#include "MainMenu.h"
MainMenu::MainMenu() {
	bg = new Image("images\\Menu\\SelectorScreen_BG_Right.png");
	board_game = new Image("images\\Menu\\Adventure_1.png");
	board_label = new Image("images\\WoodSign.png");
	bg2 = new Image("images\\Menu\\SelectorScreen_BG_Left.jpg");
	bg3 = new Image("images\\Menu\\SelectorScreen_BG_Center.jpg");
}
MainMenu::~MainMenu() {

}
//800 * 600
void MainMenu::draw() {
	bg3->put_transparent(0, 250, 720, 350, 0, 0);

	bg2->put_transparent(0, 0, 476, 680, 0, 0);
	bg->put_transparent(70, 40, 730, 560, 0, 0);
	board_game->put_transparent(400, 50, 331, 145, 0, 0);
	board_label->put_transparent(20, 20, 239, 150, 0, 0);
}