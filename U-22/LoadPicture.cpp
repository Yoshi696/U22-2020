#include "DxLib.h"
#include "Picture.h"

int LoadPicture(){
	if ((g_img.sample = LoadGraph("images/sample.bmp")) == -1) return -1;		//�}�b�v�`�b�v�p�摜
	if(LoadDivGraph("images/P2.png", 9, 3, 3, 60, 60, g_img.gh,0) == -1) return -1;							//�v���C���[�ϐ�

	return 0;
}