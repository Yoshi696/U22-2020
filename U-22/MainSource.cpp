#include "DxLib.h"
#include "Struct.h"
#include "yoshitaka.h"
#include "tubasa.h"
#include "yu-ki.h"
#include "issei.h"
#include "hiroaki.h"
#include "daiki.h"
#include "GameScene.h"
#include "GameTitle.h"
#include "StageSelect.h"
#include "GamePlay.h"
#include "GameClear.h"
#include "GameOver.h"

/************************************************
**	U-22�Q�[���i�^�C�g���j
*************************************************/
//�ύX�_
//�g�C��
/***************************
*	�O���[�o���ϐ��̐錾
****************************/
int g_gameScene = 0;
mouse g_mouseInfo;								// �}�E�X�̏�ԊǗ�

/***************************
*	�֐��̐錾
****************************/
int Main(void);					// �Q�[���̃��C������
void GameScene(int gameScene);	// ��ʂ̃V�[���Ǘ�

/***************************
* WinMain�֐�
****************************/

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_
	HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd) {

	// �t���X�N���[���ɂ��Ȃ����ǂ��� TRUE:���Ȃ� FALSE:����
	ChangeWindowMode(TRUE);

	// �E�B���h�E��ʂ̑傫��
	SetGraphMode(1280, 768, 32);

	// DX���C�u�����̏�����
	if (DxLib_Init() == -1) return  -1;

	//�Q�[�����C��
	Main();

	// DX���C�u�����I��
	DxLib_End();

	// �I��
	return 0;
}

int Main() {
	// �`���𗠉�ʂɃZ�b�g
	SetDrawScreen(DX_SCREEN_BACK);

	// ���C�����[�v
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {
		// ��ʂ̃N���A
		ClearDrawScreen();

		//�f�o�b�O�H�}�E�X�擾
		ControlInfo(&g_mouseInfo);

		//�f�o�b�O�O����W
		DrawFormatString(0, 20, 0xFFFFFF, "mouseX = %d \n mouseY = %d", g_mouseInfo.mouseX, g_mouseInfo.mouseY);

		// �Q�[���V�[���̒������ēK���ȃQ�[����ʂ�`��
		GameScene(g_gameScene);

		// ��ʂ̍X�V
		ScreenFlip();
	}

	// �I��
	return 0;
}

// �Q�[���V�[���̊Ǘ�
void GameScene(int gameScene) {

	switch (gameScene) {
		case GAME_TITLE:	GameTitle();	break;	 // �Q�[���^�C�g��
		case GAME_SELECT:	StageSelect();	break;	 // �Q�[���Z���N�g
		case GAME_PLAY:	    GamePlay();		break;	 // �Q�[���v���C	
		case GAME_OVER:		GameOver();		break;	 // �Q�[���I�[�o�[
		case GAME_CLEAR:	GameClear();	break;	 // �Q�[���N���A
	}
}
