#include "DxLib.h"
#include "Picture.h"

//�摜�����[�h����

int LoadPicture(){
	if (LoadDivGraph("images/sample.bmp", 10, 10, 1, 64, 64, g_img.sample) == -1) return -1;					//�摜�`�b�v
	if((LoadDivGraph("images/Player.png", 9, 3, 3, 64, 64, g_img.gh)) == -1) return -1;							//�v���C���[�ϐ�
	if ((LoadDivGraph("images/Door.png", 3, 3, 3, 64, 64, g_img.door)) == -1) return -1;							//�h�A�摜�ϐ�
	if ((LoadDivGraph("images/book.png", 1, 1, 1, 64, 64, g_img.book)) == -1)return -1;	 //�{�摜�ϐ�
	if ((g_img.sample[10] = LoadGraph("images/book.png")) == -1) return -1;
	return 0;
}