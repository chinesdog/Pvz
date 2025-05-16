#pragma once
#include <graphics.h>	
#include<string.h>
#include<iostream>
extern const TCHAR* stringToTCHAR(const std::string& str);
class Image
{
public:
	Image(const std::string filepath);
	~Image();
	IMAGE* piximage;
	IMAGE pix_bg;
	std::string ImageName;
	void put(int x, int y, DWORD dwRop)const;//Ö»¶Á
	
	void put(int x, int y,int w ,int h, int srcX, int srcY);
	void put(int x, int y, int w, int h, int srcX, int srcY,DWORD dw)const;
	void put_transparent(int x, int y, int w, int h, int srcX, int srcY);
protected:
	IMAGE transparentimage();
};

