#pragma once

/****************************
�}�N����`
****************************/
#define D_ERRPR			(-1)
#define D_NORMALITY		(0)

/****************************
�^��`
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
�v���g�^�C�v�錾
****************************/
void SceneManager_Initialize(GAME_MODE mode);
void SceneManager_Updata(void);
void SceneManager_Draw(void);

void Change_Scene(GAME_MODE mode);
int ErrorCheck(void);