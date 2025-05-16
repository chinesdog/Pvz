
#include "Image.h"


Image::Image(const std::string filepath) {
	this->ImageName = filepath;
	piximage = new IMAGE();
	loadimage(piximage, stringToTCHAR("res\\"+filepath));

	pix_bg = transparentimage();
}
Image::~Image() {
	delete piximage;
	
}


void Image:: put(int x, int y, DWORD dwRop)const
{
	putimage(x, y, piximage, dwRop);
}
void Image::put(int x, int y, int w, int h, int srcX, int srcY) {
	putimage(x, y, w, h, piximage, srcX, srcY);
	
}
void Image::put(int x, int y, int w, int h, int srcX, int srcY, DWORD dw)const
{
	putimage(x, y, w, h, piximage, srcX, srcY,dw);
}
void Image::put_transparent(int x, int y, int w, int h, int srcX, int srcY) {
	putimage(x, y, w, h, &pix_bg, srcX, srcY, SRCAND);
	putimage(x, y, w, h, piximage, srcX, srcY, SRCPAINT);
}


IMAGE Image:: transparentimage(){
	IMAGE img1;
	DWORD* d1;
	img1 = *piximage;
	d1 = GetImageBuffer(&img1);
	float h, s, l;
	for (int i = 0; i < img1.getheight() * img1.getwidth(); i++) {
		RGBtoHSL(BGR(d1[i]), &h, &s, &l);
		if (l < 0.03) {
			d1[i] = BGR(WHITE);
		}
		if (d1[i] != BGR(WHITE)) {
			d1[i] = 0;
		}
	}
	return img1;
}