// Hilbert.cpp : Entrace of the Console Application
//

#include "stdafx.h"
#include "QuickHilbertCode.h"
#include <fstream>

//QuickHilbertCode by Li-Shaojun(李绍俊，lishaojun@supermap.com)
double QHCHilbert(int nLevel)
{
	/********************************************/
	//统计执行时间
	/********************************************/
	LARGE_INTEGER Frequency;//计数器频率   
	LARGE_INTEGER start_PerformanceCount;//起始计数器   
	LARGE_INTEGER end_PerformanceCount;//结束计数器   
	double run_time; //运行时间   
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
	//统计执行时间
	/********************************************/
	QueryPerformanceCounter(&end_PerformanceCount);   
	run_time = ( end_PerformanceCount.QuadPart - start_PerformanceCount.QuadPart ) / (double)Frequency.QuadPart;  
	/********************************************/

	return run_time;
}


//经典Faloutsos & Roseman算法
double FRHilbert(int nLevel)
{
	/********************************************/
	//统计执行时间
	/********************************************/
	LARGE_INTEGER Frequency;//计数器频率   
	LARGE_INTEGER start_PerformanceCount;//起始计数器   
	LARGE_INTEGER end_PerformanceCount;//结束计数器   
	double run_time; //运行时间   
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
	//统计执行时间
	/********************************************/
	QueryPerformanceCounter(&end_PerformanceCount);   
	run_time = ( end_PerformanceCount.QuadPart - start_PerformanceCount.QuadPart ) / (double)Frequency.QuadPart;  
	/********************************************/

	return run_time;
}


int _tmain(int argc, _TCHAR* argv[])
{
	//重复执行n次，取平均值
	int nTimes = 20;

	double dQHCTime = 0.0;
	double dFRTime = 0.0;
	for(int i=1;i<15;i++)
	{
		//计算10次取平均值
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
	//用于统计执行时间的代码
	/********************************************/
	LARGE_INTEGER Frequency;//计数器频率   
	LARGE_INTEGER start_PerformanceCount;//起始计数器   
	LARGE_INTEGER end_PerformanceCount;//结束计数器   
	double run_time; //运行时间   
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
	//用于统计执行时间的代码
	/********************************************/
	QueryPerformanceCounter(&end_PerformanceCount);   
	run_time = ( end_PerformanceCount.QuadPart - start_PerformanceCount.QuadPart ) / (double)Frequency.QuadPart;  
	printf("%lf", run_time);
	/********************************************/

	system ( "pause" );

	return 0;
}






















