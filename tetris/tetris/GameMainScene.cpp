#include "GameMainScene.h"
#include "DxLib.h"
#include "Block.h"
#include "SceneManager.h"
#include "InputControl.h"
#include "Particle.h"

/****************************
マクロ定義
****************************/

/****************************
型定義
****************************/

/****************************
グローバル変数宣言
****************************/
int BackGround_image;		//背景画像イメージ
int BackGround_sound;		//BGM
int GameOver_sound;			//ゲームオーバーSE
int Score;					//スコア
int Level;
bool GM_Bomflag;
int LevelScore[4] = { 500,1500,3000,5000 };

/****************************
プロトタイプ宣言
****************************/
void Score_Draw(void);

/****************************
ゲームメイン画面：初期化処理
引　数：なし
戻り値：エラー情報
****************************/
int GameMainScene_Initialize(void)
{
	int ret = 0;

	ret = Block_Initialize();
	BackGround_image = LoadGraph("images/stage.png");
	BackGround_sound = LoadSoundMem("sounds/BGM017.ogg");
	GameOver_sound = LoadSoundMem("sounds/GameOver.mp3");

	Score = 0;
	Level = 1;
	GM_Bomflag = true;

	//エラーチェック
	if (BackGround_image == -1)
	{
		ret = -1;
	}
	if (BackGround_sound == -1)
	{
		ret = -1;
	}
	if (GameOver_sound == -1)
	{
		ret = -1;
	}

	return ret;
}

/****************************
ゲームメイン画面：更新処理
引　数：なし
戻り値：なし
****************************/
void GameMainScene_Update(void)
{
	int delete_line;
	//BGMの再生
	PlaySoundMem(BackGround_sound, DX_PLAYTYPE_LOOP, FALSE);

	

	//ブロック機能の更新
	Block_Update();

	if (GetButtonDown(XINPUT_BUTTON_START) == TRUE)
	{
		Change_Scene(E_RANKING);
	}

	delete_line = Get_Line();

	if (delete_line == 4)
	{
		Score += delete_line * 50 * 2;
	}
	else
	{
		Score += delete_line * 50;
	}

	//レベルを考えてる。
	
	if (Score <= LevelScore[0])
	{
		Level = 1;
	}
	else if (Score <= LevelScore[1])
	{
		Level = 2;
		if (GM_Bomflag == true)
		{
			Set_Bom(1);
			GM_Bomflag = false;
		}
	}
	else if (Score <= LevelScore[2])
	{
		Level = 3;
		if (GM_Bomflag == false)
		{
			Set_Bom(1);
			GM_Bomflag = true;
		}
	}
	else if (Score <= LevelScore[3])
	{
		Level = 4;
		if (GM_Bomflag == true)
		{
			Set_Bom(1);
			GM_Bomflag = false;
		}
	}
	else
	{
		Level = 5;
		if (GM_Bomflag == false)
		{
			Set_Bom(1);
			GM_Bomflag = true;
		}
	}
	
	


	//生成できなくなったら
	if (Get_GenerateFlg() != TRUE)
	{
		PlaySoundMem(GameOver_sound, DX_PLAYTYPE_BACK, FALSE);
		Change_Scene(E_RANKING);
		StopSoundMem(BackGround_sound);
	}
}

/****************************
ゲームメイン画面：描画処理
引　数：なし
戻り値：なし
****************************/
void GameMainScene_Draw(void)
{
	//背景の描画
	DrawGraph(0, 0, BackGround_image, TRUE);

	//ブロック描画
	Block_Draw();
	SetFontSize(100);

	//スコアの描画
	Score_Draw();
	
	//レベルの描画
	DrawFormatString(900, 250, 0xFFFFFF, "%d", Level);

	SetFontSize(20);
}

/****************************
ゲームメイン画面：スコア取得処理
引　数：なし
戻り値：あり
****************************/
int Get_Score(void)
{
	return Score;
}

int Get_Level(void)
{
	return -Level;
}

void Score_Draw(void)
{
	if (Score >= 1000)
	{
		DrawFormatString(750, 100, 0xFFFFFF, "%d", Score);
	}
	else if(Score >= 100)
	{
		DrawFormatString(800, 100, 0xFFFFFF, "%d", Score);
	}
	else if(Score >= 50)
	{
		DrawFormatString(850, 100, 0xFFFFFF, "%d", Score);
	}
	else
	{
		DrawFormatString(900, 100, 0xFFFFFF, "%d", Score);
	}
}