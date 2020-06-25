#include "DxLib.h"
#include "player.h"
#include "Picture.h"
#include "Map.h"

void PlayerMove(){

	DrawFormatString(0, 60, 0xffffff, "xc%d", g_player.xcount);
	DrawFormatString(0, 80, 0xffffff, "yc%d", g_player.ycount);
	DrawFormatString(0, 100, 0xffffff, "re%d", g_player.result);
	DrawFormatString(0, 120, 0xffffff, "dir%d", g_player.dir);
	DrawFormatString(0, 140, 0xffffff, "x%d", g_player.px);
	DrawFormatString(0, 160, 0xffffff, "y%d", g_player.py);

	if (key[KEY_INPUT_LEFT] == 1 || key[KEY_INPUT_RIGHT] == 1) {

		if (key[KEY_INPUT_UP] == 1 || key[KEY_INPUT_DOWN] == 1) {
			//�ړ��W�����O�D�V�P�ɐݒ�
			g_player.move = 0.71f;
		}
		else {
			//�΂߂���Ȃ���΂P�D�O�ɐݒ�
			g_player.move = 1.0f;
		}
	}
	else if (key[KEY_INPUT_UP] == 1 || key[KEY_INPUT_DOWN] == 1) {
		g_player.move = 1.0f;
	}


	if (key[KEY_INPUT_LEFT] == 1) {
		g_player.px -= (int)4 * g_player.move;
	}
	if (key[KEY_INPUT_RIGHT] == 1) {
		g_player.px += (int)4 * g_player.move;

	}
	//��ʈړ�����

	if (g_player.px + 64 > 1152)
		g_player.px = 1152 - 64;
	if (g_player.px < 0)
		g_player.px = 0;

	//if (g_player.px + 32 > 582 && g_player.px + 32 < 701 && g_player.py > 515 && g_player.py < 632) {
	//	g_player.px = 760, g_player.py = 70;

	//}

	if (g_map.playStage[int(g_player.py / 64) + 1][int(g_player.px / 64) + 1] != 9) {
		g_player.py += 16;
	}

	//�W�����v����

	/*if (g_player.jflag == true) {
		g_player.y_temp = g_player.py;
		g_player.py += (g_player.py - g_player.y_prev) + 1;
		g_player.y_prev = g_player.y_temp;
		if (g_player.py == 572) {
			g_player.jflag = false;
			if (g_player.dir == 0) {
				g_player.result = 0;
			}
			if (g_player.dir == 1) {
				g_player.result = 3;
			}
		}
	}

	if (key[KEY_INPUT_SPACE] == 1 && g_player.jflag == false) {
		g_player.jflag = true;
		g_player.y_prev = g_player.py;
		g_player.py = g_player.py - 15;

	}
	*/
	if (key[KEY_INPUT_LEFT] == 1) {
		if (g_player.xcount > 0)
			g_player.xcount = 0;
		g_player.ycount = 0;
		--g_player.xcount;
		g_player.dir = 1;
	}
	if (key[KEY_INPUT_RIGHT] == 1) {
		if (g_player.xcount < 0)
			g_player.xcount = 0;
		g_player.ycount = 0;
		++g_player.xcount;
		g_player.dir = 0;
	}

	//if (key[KEY_INPUT_SPACE] == 1 && g_player.dir == 0) {
	//	if (g_player.ycount < 0)
	//		g_player.ycount = 0;
	//	++g_player.ycount;

	//}

	//if (key[KEY_INPUT_SPACE] == 1 && g_player.dir == 1) {
	//	if (g_player.ycount > 0)
	//		g_player.ycount = 0;
	//	--g_player.ycount;

	//}


	//�J�E���g������Y�������߂�B
	g_player.ix = abs(g_player.xcount) % 30 / 10;
	//g_player.iy = abs(g_player.ycount) % 30 / 10;


	///x�J�E���g���v���X�Ȃ�E�����Ȃ̂�1�s�ڂ̐擪�Y���ԍ��𑫂��B
	if (g_player.xcount > 0) {
		g_player.result = g_player.ix;
	}
	else if (g_player.xcount < 0) {
		//x�J�E���g���}�C�i�X�Ȃ獶�����Ȃ̂ŁA2�s�ڂ̐擪�Y���ԍ��𑫂��B
		g_player.ix += 3;
		g_player.result = g_player.ix;
	}

	/////y�J�E���g���v���X�Ȃ��E�����Ȃ̂�3�s�ڂ̐擪�Y���ԍ��𑫂��B
	//if (g_player.ycount == 1) {
	//	g_player.iy += 6;
	//	g_player.result = g_player.iy;

	//}
	//else if (g_player.ycount == -1) {
	//	//y�J�E���g���}�C�i�X�Ȃ�㍶�����Ȃ̂ŁA4�s�ڂ̐擪�Y���ԍ��𑫂��B
	//	g_player.iy += 7;
	//	g_player.result = g_player.iy;

	//}

	DrawGraph(g_player.px, g_player.py, g_img.gh[g_player.result], TRUE);

	//������ĂȂ���΃J�E���g���[���ɂ���B
	if (key[KEY_INPUT_LEFT] != 1 && key[KEY_INPUT_RIGHT] != 1) {
		g_player.xcount = 0;
		//g_player.ycount = 0;
	}

	}
