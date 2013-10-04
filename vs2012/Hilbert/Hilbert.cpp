// Hilbert.cpp : Entrace of the Console Application
//

#include "stdafx.h"
#include "QuickHilbertCode.h"
#include <fstream>

//QuickHilbertCode by Li-Shaojun(���ܿ���lishaojun@supermap.com)
double QHCHilbert(int nLevel)
{
	/********************************************/
	//ͳ��ִ��ʱ��
	/********************************************/
	LARGE_INTEGER Frequency;//������Ƶ��   
	LARGE_INTEGER start_PerformanceCount;//��ʼ������   
	LARGE_INTEGER end_PerformanceCount;//����������   
	double run_time; //����ʱ��   
	QueryPerformanceFrequency(&Frequency);   
	QueryPerformanceCounter(&start_PerformanceCount);   
	/********************************************/

	int nWidth = 1<<nLevel;
	int nHeight = 1<<nLevel;
	DWORD nKey = 0;

	CQuickHilbertCode qTree;

	for(WORD i=0;i<nHeight;i++)
	{
		for(WORD j=0;j<nWidth;j++)
		{
			nKey = qTree.GetQuickHilbertKey(j,i,nLevel);
		}
	}


	/********************************************/
	//ͳ��ִ��ʱ��
	/********************************************/
	QueryPerformanceCounter(&end_PerformanceCount);   
	run_time = ( end_PerformanceCount.QuadPart - start_PerformanceCount.QuadPart ) / (double)Frequency.QuadPart;  
	/********************************************/

	return run_time;
}


//����Faloutsos & Roseman�㷨
double FRHilbert(int nLevel)
{
	/********************************************/
	//ͳ��ִ��ʱ��
	/********************************************/
	LARGE_INTEGER Frequency;//������Ƶ��   
	LARGE_INTEGER start_PerformanceCount;//��ʼ������   
	LARGE_INTEGER end_PerformanceCount;//����������   
	double run_time; //����ʱ��   
	QueryPerformanceFrequency(&Frequency);   
	QueryPerformanceCounter(&start_PerformanceCount);   
	/********************************************/

	int nWidth = 1<<nLevel;
	int nHeight = 1<<nLevel;
	DWORD nKey = 0;

	CQuickHilbertCode qTree;

	for(WORD i=0;i<nHeight;i++)
	{
		for(WORD j=0;j<nWidth;j++)
		{
			nKey = qTree.GetFRHilbertKey(j,i,nLevel);
		}
	}


	/********************************************/
	//ͳ��ִ��ʱ��
	/********************************************/
	QueryPerformanceCounter(&end_PerformanceCount);   
	run_time = ( end_PerformanceCount.QuadPart - start_PerformanceCount.QuadPart ) / (double)Frequency.QuadPart;  
	/********************************************/

	return run_time;
}


int _tmain(int argc, _TCHAR* argv[])
{
	//�ظ�ִ��n�Σ�ȡƽ��ֵ
	int nTimes = 20;

	double dQHCTime = 0.0;
	double dFRTime = 0.0;
	for(int i=1;i<15;i++)
	{
		//����10��ȡƽ��ֵ
		for(int j=0;j<nTimes;j++)
		{
			dQHCTime += QHCHilbert(i);
			dFRTime += FRHilbert(i);
		}
		printf("Lev=%ld\tQHCTime=%9f\tFRTime=%9f\tAR=%3f\n", i, dQHCTime/nTimes, dFRTime/nTimes, dFRTime/dQHCTime);
	}
	system ( "pause" );
	return 0;


	/********************************************/
	//����ͳ��ִ��ʱ��Ĵ���
	/********************************************/
	LARGE_INTEGER Frequency;//������Ƶ��   
	LARGE_INTEGER start_PerformanceCount;//��ʼ������   
	LARGE_INTEGER end_PerformanceCount;//����������   
	double run_time; //����ʱ��   
	QueryPerformanceFrequency(&Frequency);   
	QueryPerformanceCounter(&start_PerformanceCount);   
	/********************************************/

	WORD nLevel = 13;
	int nWidth = 1<<nLevel;
	int nHeight = 1<<nLevel;
	DWORD nKey = 0, nKey2 = 0;

	double dif = 0.0;

	CQuickHilbertCode qTree;

 	for(WORD i=0;i<nHeight;i++)
 	{
		for(WORD j=0;j<nWidth;j++)
		{
			//nKey = qTree.GetQuickHilbertKey(j,i,nLevel);
			nKey2 = qTree.GetFRHilbertKey(j,i, nLevel);

			//dif += abs(int(nKey2)-int(nKey));

//			printf("%d\t",nKey);
		}
// 		printf("\n");
	}

//	printf("%lf", dif);
	
	/********************************************/
	//����ͳ��ִ��ʱ��Ĵ���
	/********************************************/
	QueryPerformanceCounter(&end_PerformanceCount);   
	run_time = ( end_PerformanceCount.QuadPart - start_PerformanceCount.QuadPart ) / (double)Frequency.QuadPart;  
	printf("%lf", run_time);
	/********************************************/

	system ( "pause" );

	return 0;
}






















