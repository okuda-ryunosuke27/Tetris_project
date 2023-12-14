#include "GameMainScene.h"
#include "DxLib.h"
#include "Block.h"
#include "SceneManager.h"
#include "InputControl.h"
#include "Particle.h"

/****************************
�}�N����`
****************************/

/****************************
�^��`
****************************/

/****************************
�O���[�o���ϐ��錾
****************************/
int BackGround_image;		//�w�i�摜�C���[�W
int BackGround_sound;		//BGM
int GameOver_sound;			//�Q�[���I�[�o�[SE
int Score;					//�X�R�A
int Level;
bool GM_Bomflag;
int LevelScore[4] = { 500,1500,3000,5000 };

/****************************
�v���g�^�C�v�錾
****************************/
void Score_Draw(void);

/****************************
�Q�[�����C����ʁF����������
���@���F�Ȃ�
�߂�l�F�G���[���
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

	//�G���[�`�F�b�N
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
�Q�[�����C����ʁF�X�V����
���@���F�Ȃ�
�߂�l�F�Ȃ�
****************************/
void GameMainScene_Update(void)
{
	int delete_line;
	//BGM�̍Đ�
	PlaySoundMem(BackGround_sound, DX_PLAYTYPE_LOOP, FALSE);

	

	//�u���b�N�@�\�̍X�V
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

	//���x�����l���Ă�B
	
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
	
	


	//�����ł��Ȃ��Ȃ�����
	if (Get_GenerateFlg() != TRUE)
	{
		PlaySoundMem(GameOver_sound, DX_PLAYTYPE_BACK, FALSE);
		Change_Scene(E_RANKING);
		StopSoundMem(BackGround_sound);
	}
}

/****************************
�Q�[�����C����ʁF�`�揈��
���@���F�Ȃ�
�߂�l�F�Ȃ�
****************************/
void GameMainScene_Draw(void)
{
	//�w�i�̕`��
	DrawGraph(0, 0, BackGround_image, TRUE);

	//�u���b�N�`��
	Block_Draw();
	SetFontSize(100);

	//�X�R�A�̕`��
	Score_Draw();
	
	//���x���̕`��
	DrawFormatString(900, 250, 0xFFFFFF, "%d", Level);

	SetFontSize(20);
}

/****************************
�Q�[�����C����ʁF�X�R�A�擾����
���@���F�Ȃ�
�߂�l�F����
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