//�摜�̕ϐ��Ƃ�

#pragma once

int LoadPicture();

struct image {
	int sample[10];//0~9 �摜�������Ă��鐔�l
	int gh[9];  //10~18
	int door[4]; //19~21
	int book[1]; //23
	
};

extern image g_img;
