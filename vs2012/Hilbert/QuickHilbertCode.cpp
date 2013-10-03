#include "stdafx.h"
#include "QuickHilbertCode.h"

//״̬ת����������key��������
BYTE arKey[4][2][2] = {0,1,3,2,0,3,1,2,2,3,1,0,2,1,3,0};

//״̬ת����������type��������
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
//GridX, GridY, Ҫ����ĸ�Ԫ��դ���е�λ�ã�ǰ��Ϊ�кţ�����Ϊ�к�
//k�����ռ�Ĳ�����ÿ��ĸ�Ԫ��Ϊ2^k
//Output:
//������ĸ�Ԫ��k���Hilbert Code
DWORD CQuickHilbertCode::GetQuickHilbertKey(WORD GridX,WORD GridY,WORD k)
{
	ASSERT(k>0);

	//ʹ��λ��ṹ����Կ��ٻ�ȡָ��λ(bit)��ֵ
	unGridPos X,Y;
	X.s = GridX,Y.s = GridY;

	WORD nType=0;
	WORD bitX = 0,bitY = 0;

	//resKey��������������ռ�����
	DWORD resKey = 0;

	//�������ռ��е������Ԫ�������������k��
	//���Ա��㷨���Ӷȵ��ȶ��Էǳ���
	for(short i=k;i>0;i--)
	{
		//ȡλ
		MacroForGetXBit(i,bitX);
		MacroForGetYBit(i,bitY);

		//�����ȡֵ������һ�����ϲ�(��һ����������λ�뱾�β�������������)
		resKey = (resKey<<2)|arKey[nType][bitX][bitY];
		//�����ȡtypeֵ������ѭ������һ�μ���
		nType = arType[nType][bitX][bitY];
	}

	//������ϣ����ؽ��
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
