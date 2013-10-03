#include "stdafx.h"
#include "QuickHilbertCode.h"

//状态转移向量矩阵：key向量矩阵
BYTE arKey[4][2][2] = {0,1,3,2,0,3,1,2,2,3,1,0,2,1,3,0};

//状态转移向量矩阵：type向量矩阵
BYTE arType[4][2][2] = {1,0,3,0,0,2,1,1,2,1,2,3,3,3,0,2};

CQuickHilbertCode::CQuickHilbertCode(void)
{
}


CQuickHilbertCode::~CQuickHilbertCode(void)
{
}

//A Quick Algorithm for Hilbert Ordering Code Based on State Transition Matrix
//By Li Shao-jun @ SuperMap
//Input:
//GridX, GridY, 要计算的格元在栅格中的位置，前者为列号，后者为行号
//k，填充空间的层数，每层的格元数为2^k
//Output:
//所计算的格元在k层的Hilbert Code
DWORD CQuickHilbertCode::GetQuickHilbertKey(WORD GridX,WORD GridY,WORD k)
{
	ASSERT(k>0);

	//使用位域结构体可以快速获取指定位(bit)的值
	unGridPos X,Y;
	X.s = GridX,Y.s = GridY;

	WORD nType=0;
	WORD bitX = 0,bitY = 0;

	//resKey变量用来存放最终计算结果
	DWORD resKey = 0;

	//对于填充空间中的任意格元，计算次数都是k次
	//所以本算法复杂度的稳定性非常高
	for(short i=k;i>0;i--)
	{
		//取位
		MacroForGetXBit(i,bitX);
		MacroForGetYBit(i,bitY);

		//查矩阵取值并与上一层结果合并(上一层结果左移两位与本次查矩阵结果求或运算)
		resKey = (resKey<<2)|arKey[nType][bitX][bitY];
		//查矩阵取type值，用于循环的下一次计算
		nType = arType[nType][bitX][bitY];
	}

	//计算完毕，返回结果
	return resKey;
}


//A traditional Algorithm for Hilbert Ordering Code by Christos Faloutsos & Shari Roseman
DWORD CQuickHilbertCode::GetFRHilbertKey(WORD nX,WORD nY,WORD nLevel)
{
	ASSERT(nLevel>0);

	int lenMorton = nLevel*2;
	int nChaX = nLevel;
	int nChaY = nLevel;

	char cMorTon[33];
	char cX[17];
	char cY[17];
	char cBufferX[17];
	char cBufferY[17];

	_itoa_s(nX,cX,2);
	_itoa_s(nY,cY,2);

	sprintf_s(cBufferX, "%016s",cX);
	sprintf_s(cBufferY, "%016s",cY);

	sprintf_s(cMorTon, "%032s",0);

	for(int i=nLevel;i>0;i--)
	{
		cMorTon[32-i*2] = cBufferX[16-i];
		cMorTon[32-i*2+1] = cBufferY[16-i];

		if(cMorTon[32-i*2] == '1' && cMorTon[32-i*2+1] == '0')
		{
			cMorTon[32-i*2] = '1';
			cMorTon[32-i*2+1] = '1';
		}
		else if(cMorTon[32-i*2] == '1' && cMorTon[32-i*2+1] == '1')
		{
			cMorTon[32-i*2] = '1';
			cMorTon[32-i*2+1] = '0';
		}
	}

	for(int k=nLevel;k>1;k--)
	{
		if(cMorTon[32-k*2] == '0' && cMorTon[32-k*2+1] == '0' )
		{
			for(int i=k-1;i>0;i--)
			{
				if(cMorTon[32-i*2] == '1' && cMorTon[32-i*2+1] == '1')
				{
					cMorTon[32-i*2] = '0';
					cMorTon[32-i*2+1] = '1';
				}
				else if(cMorTon[32-i*2] == '0' && cMorTon[32-i*2+1] == '1')
				{
					cMorTon[32-i*2] = '1';
					cMorTon[32-i*2+1] = '1';
				}

			}
		}
		else if(cMorTon[32-k*2] == '1' && cMorTon[32-k*2+1] == '1' )
		{
			for(int i=k-1;i>0;i--)
			{
				if(cMorTon[32-i*2] == '1' && cMorTon[32-i*2+1] == '0')
				{
					cMorTon[32-i*2] = '0';
					cMorTon[32-i*2+1] = '0';
				}
				else if(cMorTon[32-i*2] == '0' && cMorTon[32-i*2+1] == '0')
				{
					cMorTon[32-i*2] = '1';
					cMorTon[32-i*2+1] = '0';
				}
			}
		}
	}
	
	int nResult = strtol(cMorTon, NULL, 2);
	
	return nResult;
}

//An Algorithm for Hilbert Ordering Code Based on Spatial Hierarchical Decomposition
//By LU Feng, Zhou Cheng-hu
DWORD CQuickHilbertCode::GetSHDHilbertKey(WORD nX,WORD nY,WORD nLevel)
{
	ASSERT(nLevel>0);
	return 0;
}
