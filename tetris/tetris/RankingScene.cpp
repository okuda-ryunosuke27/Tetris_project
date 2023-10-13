#include "RanklingScene.h"
#include "DxLib.h"
#include "InputControl.h"
#include "SceneManager.h"

/****************************
マクロ定義
****************************/
#define RANKING_FILE		("dat/rankingdata.csv")
#define RANKING_MAX			(10)
#define RANKING_NAME_LEN	(11)

/****************************
型定義
****************************/
typedef struct
{
	int rank;						//ランク
	char name[RANKING_NAME_LEN];	//名前
	int score;						//スコア
}T_RANKING;

typedef struct
{
	int x;
	int y;
}T_CURSOR;

/****************************
グローバル変数宣言
****************************/
T_RANKING Ranking_Data[RANKING_MAX];	//ランキングデータ
T_RANKING New_Score;					//新しいスコアデータ
int DispMode;							//表示モード

T_CURSOR Cursor;						//カーソル用変数
int name_num;


/****************************
プロトタイプ宣言
****************************/


int RankingScene_Initialize(void);
void RankingScene_Updata(void);
void RankingScene_Draw(void);

void Set_RankingMode(int mode);
void Set_RankingScore(int score);