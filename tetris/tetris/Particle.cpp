#include "Particle.h"
#include "DxLib.h"

#define MAX_SPARK 800

typedef struct 
{
	int Valid;	// ���̃f�[�^���g�p�����A�t���O
	int X, Y;	// �ΉԂ̈ʒu
	int Sx, Sy;	// �ΉԂ̈ړ���
	int G;		// �ΉԂ̏d��
	int Bright;	// �ΉԂ̖��邳
} SPARK;


SPARK Spark[MAX_SPARK];	// �Ήԃf�[�^

int flag;

void Particle_Initialize(void)
{
	// �ΉԂ̑��݂�����������
	for (int i = 0; i < MAX_SPARK; i++)
	{
		Spark[i].Valid = 0;
	}
	flag = 0;
}

void Particle_Draw(void)
{

	
	// �ΉԂ�`�悷��
	for (int j = 0; j < MAX_SPARK; j++)
	{
		
		// �Ήԃf�[�^���L���Ȏ��̂ݕ`��
		if (Spark[j].Valid == 1)
		{
			SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, Spark[j].Bright);
			//DrawCircle(Spark[j].X / 100, Spark[j].Y / 100, 5, GetColor(Spark[j].Bright, Spark[j].Bright, Spark[j].Bright), TRUE);
			DrawCircle(Spark[j].X / 100, Spark[j].Y / 100, 5, 0xFFFFFF, TRUE);
			SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 0);
		}
	}
	
}

//�p�[�e�B�N���̐���
void Create_Spark(int x, int y)
{
	int i;

	// �g���Ă��Ȃ��Ήԃf�[�^��T��
	for (i = 0; i < MAX_SPARK; i++)
	{
		if (Spark[i].Valid == 0)
		{
			break;
		}
	}

	// �����g���Ă��Ȃ��Ήԃf�[�^����������ΉԂ��o��
	if (i != MAX_SPARK)
	{
		// �ΉԂ̈ʒu��ݒ�
		Spark[i].X = x * 100;
		Spark[i].Y = y * 100;

		// �ړ��͂�ݒ�
		Spark[i].Sx = GetRand(100) - 50;
		Spark[i].Sy = -GetRand(500) + 1;

		// �ΉԂ̏d�����Z�b�g
		Spark[i].G = 0;


		Spark[i].Bright = 255;
		
		// �Ήԃf�[�^���g�p���ɃZ�b�g
		Spark[i].Valid = 1;

		flag = 1;
	}
}

//�p�[�e�B�N���̈ړ�
void Move_Spark(void)
{
	int i;

	// �ΉԂ̈ړ�����
	for (i = 0; i < MAX_SPARK; i++)
	{
		// �Ήԃf�[�^��������������X�L�b�v
		if (Spark[i].Valid == 0)
		{
			continue;
		}

		// �ʒu���ړ��͂ɉ����Ă��炷
		Spark[i].Y += Spark[i].Sy;
		Spark[i].X += Spark[i].Sx;

		// �ړ��͂�ύX
		Spark[i].Sy += Spark[i].G;

		 //�ΉԂ̖��邳��������
		Spark[i].Bright -= 2;

		// �ΉԂ̖��邳���O�ȉ��ɂȂ�����Ήԃf�[�^�𖳌��ɂ���
		if (Spark[i].Bright == 0)
		{
			Spark[i].Valid = 0;
			flag = 0;
		}
	}
}

int Get_Flag(void)
{
	return flag;
}