// Hilbert.cpp : Entrace of the Console Application
//

#include "stdafx.h"
#include "QuickHilbertCode.h"
#include <fstream>



int _tmain(int argc, _TCHAR* argv[])
{
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

	WORD nLevel = 4 ;
	int nWidth = 1<<nLevel;
	int nHeight = 1<<nLevel;
	DWORD nKey = 0, nKey2 = 0;

	double dif = 0.0;

	CQuickHilbertCode qTree;

 	for(WORD i=0;i<nHeight;i++)
 	{
		for(WORD j=0;j<nWidth;j++)
		{
			nKey = qTree.GetQuickHilbertKey(j,i,nLevel);
			//nKey2 = qTree.GetFRHilbertKey(j,i, nLevel);

			//dif += abs(int(nKey2)-int(nKey));

//			printf("%d\t",nKey);
		}
// 		printf("\n");
	}

	printf("%lf", dif);
	
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























