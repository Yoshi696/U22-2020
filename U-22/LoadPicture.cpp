#include "DxLib.h"
#include "Picture.h"

//�摜�����[�h����

int LoadPicture(){
	if (LoadDivGraph("images/sample.bmp", 10, 10, 1, 24, 24, g_img.sample) == -1) return -1;
	if((LoadDivGraph("images/Player.png", 9, 3, 3, 64, 64, g_img.gh)) == -1) return -1;							//�v���C���[�ϐ�

	return 0;
}