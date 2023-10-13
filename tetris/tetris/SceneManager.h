#pragma once

/****************************
マクロ定義
****************************/
#define D_ERRPR			(-1)
#define D_NORMALITY		(0)

/****************************
型定義
****************************/
enum GAME_MODE
{
	E_TITLE,
	E_GAMEMAIN,
	E_RANKING,
	E_END,
	E_MODE_MAX
};

/****************************
プロトタイプ宣言
****************************/
void SceneManager_Initialize(GAME_MODE mode);
void SceneManager_Updata(void);
void SceneManager_Draw(void);

void Change_Scene(GAME_MODE mode);
int ErrorCheck(void);