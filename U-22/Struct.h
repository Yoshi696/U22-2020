#pragma once
#include "Struct.h"

int Main();

void GameScene(int gameScene);


enum {
	PROLOGUE,

};

// �}�E�X�̓��͏��
struct mouse {
    int mouseX, mouseY;
    int oldMouse, nowMouse, MouseFlg;
};

void ControlInfo(mouse* mouseInfo);

void ControlInfo(mouse* mouseInfo) {
	GetMousePoint(&mouseInfo->mouseX, &mouseInfo->mouseY);

	mouseInfo->oldMouse = mouseInfo->nowMouse;
	mouseInfo->nowMouse = GetMouseInput();
	mouseInfo->MouseFlg = mouseInfo->nowMouse & ~mouseInfo->oldMouse;

}