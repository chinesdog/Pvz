#pragma once
#include <graphics.h>
#include<conio.h>
#include<string>
#include<iostream>
#include<fstream>

//��ͬ�����ͷ�ļ�
#include<vector>
#include"Plant.h"
const int grass_width = 80;
const int grass_height = 95;
const int grass_cols = 9;
const int grass_rows = 5;
const int grass_of_x = 50;
const int grass_of_y = 100;

 std::vector<Plant*>Plants;
 void writesth(std::string title, std::string text) {
	std::ofstream outfile;
	outfile.open("logout.txt", std::ios_base::app);
	outfile << title << ": " << text << std::endl;
	outfile.close();
}
 std::string catNumber(int a, int b) {
	std::string res;
	res += std::to_string(a) + ":" + std::to_string(b);
	return res;
}

/*
* �㶹 ���տ� ӣ�� ��� ���� ���� ���컨 ˫���㶹
*/

 /*
 *		��ͼ��Χ
 *		grass_of_x &&   grass_of_x + grass_cols * grass_width
		grass_of_y &&  grass_of_y + grass_height * grass_rows
		��ʬ
		y+=50
		�㶹
		x+=50
		�ж��ӵ�������Χ
		x>=grass_of_x+ grass_cols * grass_width
		�ж��ӵ�ײ����ʬ
		zoom_x-x<=-10
		��ʬ����λ��
		grass_of_x+grass_width*grass_cols, grass_of_y-grass_height+50
		ÿ��10��ˢ��һ�ν�ʬ
		����λ�� x,y,extend_length
		��ʾ����
		20 70
 */