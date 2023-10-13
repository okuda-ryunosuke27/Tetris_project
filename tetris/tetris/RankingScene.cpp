#include "RanklingScene.h"
#include "DxLib.h"
#include "InputControl.h"
#include "SceneManager.h"

/****************************
�}�N����`
****************************/
#define RANKING_FILE		("dat/rankingdata.csv")
#define RANKING_MAX			(10)
#define RANKING_NAME_LEN	(11)

/****************************
�^��`
****************************/
typedef struct
{
	int rank;						//�����N
	char name[RANKING_NAME_LEN];	//���O
	int score;						//�X�R�A
}T_RANKING;

typedef struct
{
	int x;
	int y;
}T_CURSOR;

/****************************
�O���[�o���ϐ��錾
****************************/
T_RANKING Ranking_Data[RANKING_MAX];	//�����L���O�f�[�^
T_RANKING New_Score;					//�V�����X�R�A�f�[�^
int DispMode;							//�\�����[�h

T_CURSOR Cursor;						//�J�[�\���p�ϐ�
int name_num;


/****************************
�v���g�^�C�v�錾
****************************/


int RankingScene_Initialize(void);
void RankingScene_Updata(void);
void RankingScene_Draw(void);

void Set_RankingMode(int mode);
void Set_RankingScore(int score);