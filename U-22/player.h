#pragma once
#include "DxLib.h"
void PlayerMove();

//�ړ��W��
float move = 1.0f;

// �ړ��W��
float speed = 1.0f;

//�������Əc�����̃J�E���g���B
int xcount = 0, ycount = 0;
//�Y���p�ϐ�
int ix = 0, iy = 0, result = 0;
//�L�[�擾�p�z��
char key[256];

//x���W
int px = 300, py = 416, y_prev = 0, y_temp = 0;

//�W�����v���Ă邩�̃t���O�B
bool jflag = false;

//����
int dir = 0;