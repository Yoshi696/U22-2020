#include "DxLib.h"
#include "player.h"

//�v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);

	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}



	//�摜�ǂݍ���
	LoadDivGraph("images/P2.png", 9, 3, 3, 60, 60, gh);



	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && GetHitKeyStateAll(key) == 0) {

		if (key[KEY_INPUT_LEFT] == 1 || key[KEY_INPUT_RIGHT] == 1) {

			if (key[KEY_INPUT_UP] == 1 || key[KEY_INPUT_DOWN] == 1) {
				//�ړ��W�����O�D�V�P�ɐݒ�
				move = 0.71f;
			}
			else {
				//�΂߂���Ȃ���΂P�D�O�ɐݒ�
				move = 1.0f;
			}
		}
		else if (key[KEY_INPUT_UP] == 1 || key[KEY_INPUT_DOWN] == 1) {
			move = 1.0f;
		}


		if (key[KEY_INPUT_LEFT] == 1) {
			x -= (int)4 * move;
		}
		if (key[KEY_INPUT_RIGHT] == 1) {
			x += (int)4 * move;

		}
		//��ʈړ�����

		if (x + 49 > 640)
			x = 640 - 49;
		if (x < 0)
			x = 0;

		DrawFormatString(0, 0, 0xffffff, "xc%d", xcount);
		DrawFormatString(0, 20, 0xffffff, "yc%d", ycount);
		DrawFormatString(0, 40, 0xffffff, "re%d", result);
		DrawFormatString(0, 60, 0xffffff, "dir%d", dir);
		DrawFormatString(0, 80, 0xffffff, "x%d", x);
		DrawFormatString(0, 100, 0xffffff, "y%d", y);

		//�W�����v����

		if (jflag == true) {
			y_temp = y;
			y += (y - y_prev) + 1;
			y_prev = y_temp;
			if (y == 420) {
				jflag = false;
				if (dir == 0) {
					result = 0;
				}
				if (dir == 1) {
					result = 3;
				}
			}
		}

		if (key[KEY_INPUT_SPACE] == 1 && jflag == false) {
			jflag = true;
			y_prev = y;
			y = y - 15;

		}

		if (key[KEY_INPUT_LEFT] == 1) {
			if (xcount > 0)
				xcount = 0;
			ycount = 0;
			--xcount;
			dir = 1;
		}
		if (key[KEY_INPUT_RIGHT] == 1) {
			if (xcount < 0)
				xcount = 0;
			ycount = 0;
			++xcount;
			dir = 0;
		}

		if (key[KEY_INPUT_SPACE] == 1 && dir == 0) {
			if (ycount < 0)
				ycount = 0;
			++ycount;

		}

		if (key[KEY_INPUT_SPACE] == 1 && dir == 1) {
			if (ycount > 0)
				ycount = 0;
			--ycount;

		}


		//�J�E���g������Y�������߂�B
		ix = abs(xcount) % 30 / 10;
		iy = abs(ycount) % 30 / 10;


		///x�J�E���g���v���X�Ȃ�E�����Ȃ̂�1�s�ڂ̐擪�Y���ԍ��𑫂��B
		if (xcount > 0) {
			result = ix;
		}
		else if (xcount < 0) {
			//x�J�E���g���}�C�i�X�Ȃ獶�����Ȃ̂ŁA2�s�ڂ̐擪�Y���ԍ��𑫂��B
			ix += 3;
			result = ix;
		}

		///y�J�E���g���v���X�Ȃ��E�����Ȃ̂�3�s�ڂ̐擪�Y���ԍ��𑫂��B
		if (ycount == 1) {
			iy += 6;
			result = iy;

		}
		else if (ycount == -1) {
			//y�J�E���g���}�C�i�X�Ȃ�㍶�����Ȃ̂ŁA4�s�ڂ̐擪�Y���ԍ��𑫂��B
			iy += 7;
			result = iy;

		}

		DrawGraph(x, y, gh[result], TRUE);


		//������ĂȂ���΃J�E���g���[���ɂ���B
		if (key[KEY_INPUT_LEFT] != 1 && key[KEY_INPUT_RIGHT] != 1) {
			xcount = 0;
			ycount = 0;
		}

		if (key[KEY_INPUT_ESCAPE] == 1) {

			break;
		}

	}

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}