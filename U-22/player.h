#pragma once
#include "DxLib.h"
#include "player.h"

void PlayerMove();

struct Player {
	//�ړ��W��
	float move = 1.0f;

	// �ړ��W��
	float speed = 1.0f;

	//�������Əc�����̃J�E���g���B
	int xcount = 0, ycount = 0;
	//�Y���p�ϐ�
	int ix = 0, iy = 0, result = 0;

	//x���W
	int px = 700, py = 572, y_prev = 0, y_temp = 0;

	//�W�����v���Ă邩�̃t���O�B
	bool jflag = false;

	//����
	int dir = 0;
};

extern Player g_player;

//�L�[�擾�p�z��
extern char key[256];