#include "DxLib.h"
#include "Struct.h"

/************************************************
**	U-22�Q�[���i�^�C�g���j
*************************************************/
//�ύX�_
//�g�C��
/***************************
*	�O���[�o���ϐ��̐錾
****************************/
int g_gameScene = 0;

/***************************
*	�֐��̐錾
****************************/

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

	}
}