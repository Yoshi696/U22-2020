//画像の変数とか

#pragma once

int LoadPicture();

struct image {
	int sample[10];
	int gh[9];
};

extern image g_img;