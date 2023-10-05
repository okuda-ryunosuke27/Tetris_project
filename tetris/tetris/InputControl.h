#pragma once

/****************************
マクロ定義
****************************/

/****************************
型定義
****************************/

/****************************
プロトタイプ宣言
****************************/
void InputControl_Initialize(void);
void InputControl_Update(void);

int GetButton(int button);
int GetButtonDown(int button);
int GetButtonUp(int button);

int GetExitButton(void);