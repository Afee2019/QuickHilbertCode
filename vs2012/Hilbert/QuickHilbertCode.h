#pragma once


#define MacroForGetXBit(x,y) switch(x){\
case 1: y=X.a.a##1;break; \
case 2:\
	y=X.a.a##2;\
	break;\
case 3:\
	y=X.a.a##3;\
	break;\
case 4:\
	y=X.a.a##4;\
	break;\
case 5:\
	y=X.a.a##5;\
	break;\
case 6:\
	y=X.a.a##6;\
	break;\
case 7:\
	y=X.a.a##7;\
	break;\
case 8:\
	y=X.a.a##8;\
	break;\
case 9:\
	y=X.a.a##9;\
	break;\
case 10:\
	y=X.a.a##10;\
	break;\
case 11:\
	y=X.a.a##11;\
	break;\
case 12:\
	y=X.a.a##12;\
	break;\
case 13:\
	y=X.a.a##13;\
	break;\
case 14:\
	y=X.a.a##14;\
	break;\
case 15:\
	y=X.a.a##15;\
	break;\
case 16:\
	y=X.a.a##16;\
	break;\
}

#define MacroForGetYBit(x,y) switch(x){\
case 1: y=Y.a.a##1;break; \
case 2:\
	y=Y.a.a##2;\
	break;\
case 3:\
	y=Y.a.a##3;\
	break;\
case 4:\
	y=Y.a.a##4;\
	break;\
case 5:\
	y=Y.a.a##5;\
	break;\
case 6:\
	y=Y.a.a##6;\
	break;\
case 7:\
	y=Y.a.a##7;\
	break;\
case 8:\
	y=Y.a.a##8;\
	break;\
case 9:\
	y=Y.a.a##9;\
	break;\
case 10:\
	y=Y.a.a##10;\
	break;\
case 11:\
	y=Y.a.a##11;\
	break;\
case 12:\
	y=Y.a.a##12;\
	break;\
case 13:\
	y=Y.a.a##13;\
	break;\
case 14:\
	y=Y.a.a##14;\
	break;\
case 15:\
	y=Y.a.a##15;\
	break;\
case 16:\
	y=Y.a.a##16;\
	break;\
}


class CQuickHilbertCode
{

	union unGridPos
	{
		WORD s;
		struct
		{
			unsigned a1:1;
			unsigned a2:1;
			unsigned a3:1;
			unsigned a4:1;
			unsigned a5:1;
			unsigned a6:1;
			unsigned a7:1;
			unsigned a8:1;
			unsigned a9:1;
			unsigned a10:1;
			unsigned a11:1;
			unsigned a12:1;
			unsigned a13:1;
			unsigned a14:1;
			unsigned a15:1;
			unsigned a16:1;
		} a;
	};

public:
	CQuickHilbertCode(void);
	~CQuickHilbertCode(void);

	
	DWORD GetQuickHilbertKey(WORD nX,WORD nY,WORD nLevel);
	DWORD GetFRHilbertKey(WORD nX,WORD nY,WORD nLevel);
	DWORD GetSHDHilbertKey(WORD nX,WORD nY,WORD nLevel);
};

