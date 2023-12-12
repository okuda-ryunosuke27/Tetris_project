#include "Particle.h"
#include "DxLib.h"

#define MAX_SPARK 800

typedef struct 
{
	int Valid;	// このデータが使用中か、フラグ
	int X, Y;	// 火花の位置
	int Sx, Sy;	// 火花の移動力
	int G;		// 火花の重さ
	int Bright;	// 火花の明るさ
} SPARK;


SPARK Spark[MAX_SPARK];	// 火花データ

int flag;

void Particle_Initialize(void)
{
	// 火花の存在を初期化する
	for (int i = 0; i < MAX_SPARK; i++)
	{
		Spark[i].Valid = 0;
	}
	flag = 0;
}

void Particle_Draw(void)
{

	
	// 火花を描画する
	for (int j = 0; j < MAX_SPARK; j++)
	{
		
		// 火花データが有効な時のみ描画
		if (Spark[j].Valid == 1)
		{
			SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, Spark[j].Bright);
			//DrawCircle(Spark[j].X / 100, Spark[j].Y / 100, 5, GetColor(Spark[j].Bright, Spark[j].Bright, Spark[j].Bright), TRUE);
			DrawCircle(Spark[j].X / 100, Spark[j].Y / 100, 5, 0xFFFFFF, TRUE);
			SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 0);
		}
	}
	
}

//パーティクルの生成
void Create_Spark(int x, int y)
{
	int i;

	// 使われていない火花データを探す
	for (i = 0; i < MAX_SPARK; i++)
	{
		if (Spark[i].Valid == 0)
		{
			break;
		}
	}

	// もし使われていない火花データがあったら火花を出す
	if (i != MAX_SPARK)
	{
		// 火花の位置を設定
		Spark[i].X = x * 100;
		Spark[i].Y = y * 100;

		// 移動力を設定
		Spark[i].Sx = GetRand(100) - 50;
		Spark[i].Sy = -GetRand(500) + 1;

		// 火花の重さをセット
		Spark[i].G = 0;


		Spark[i].Bright = 255;
		
		// 火花データを使用中にセット
		Spark[i].Valid = 1;

		flag = 1;
	}
}

//パーティクルの移動
void Move_Spark(void)
{
	int i;

	// 火花の移動処理
	for (i = 0; i < MAX_SPARK; i++)
	{
		// 火花データが無効だったらスキップ
		if (Spark[i].Valid == 0)
		{
			continue;
		}

		// 位置を移動力に応じてずらす
		Spark[i].Y += Spark[i].Sy;
		Spark[i].X += Spark[i].Sx;

		// 移動力を変更
		Spark[i].Sy += Spark[i].G;

		 //火花の明るさを下げる
		Spark[i].Bright -= 2;

		// 火花の明るさが０以下になったら火花データを無効にする
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