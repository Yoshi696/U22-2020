#pragma once
#include "DxLib.h"

#define GIMMICK_NUM 2	//�M�~�b�N��

void gimmickMove();
void gimmickDisp();
void gimmickInit();

enum {
	LIFT = 0,		//�G���x�[�^�[(���[�v�]�[��)
	BREAK = 1		//�j��ł����

};

enum {//����
	K_UE = 0,		//��
	K_HA = 1		//�j
};

struct Gimmick {
	int x;				//x���W
	int y;				//y���W
	int w;				//��
	int h;				//����
	bool moveFlg;		//�M�~�b�N�̋N���t���O
};

extern Gimmick g_gimmick[GIMMICK_NUM];
