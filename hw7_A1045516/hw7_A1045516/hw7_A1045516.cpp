#include<stdlib.h>
#include<stdio.h>
//作加法運算
void add(int A, int B, int C, int D, int *X, int *Y)
{
	*X=A+C;
	*Y=B+D;
	printf("(A + Bi) + (C + Di): %d + %di\n",*X,*Y);
}
//作減法運算
void subtract(int A, int B, int C, int D, int *X, int *Y)
{
	*X=A-C;
	*Y=B-D;
	printf("(A + Bi) - (C + Di): %d + %di\n",*X,*Y);
}
//作乘法運算
void multiply(int A, int B, int C, int D, int *X, int *Y)
{
	*X=A*C+B*D*-1;
	*Y=A*D+B*C;
	printf("(A + Bi) * (C + Di): %d + %di\n",*X,*Y);
}
//作除法運算
void divide(int A, int B, int C, int D, float *X, float *Y)
{
	float Z;
	*Y=C*C-D*D*-1;
	*X=A*C-B*D*-1;
	Z=B*C-A*D;
	printf("(A + Bi) / (C + Di): %.2f + %.2fi\n\n",*X / *Y,Z / *Y);
}
int main()
{
	int A,B,C,D;//宣告四個變數分別存取輸入的四個數值
	int	X=0,Y=0;//宣告兩個資料型別為整數的變數，因為指標所指到的內容必須與其資料資料型別相同，用在加、減、乘的部分
	float E=0,F=0;//宣告兩個資料型別為浮點數的變數，因為指標所指到的內容必須與其資料資料型別相同，用在除的部分
	printf("Please enter four number to express two complex number : A + Bi and C + Di.\n");
	printf("If you want to quit, please enter four 0\n");
	scanf("%d %d %d %d",&A,&B,&C,&D);//要求使用者輸入四個數值
	//如果四個數值都是0則停止程式，否則呈現出其運算結果並重新開始主程式
	if(A==0 && B==0 && C==0 && D==0)
	{
		system("pause");
		return 0;
	}
	else
	{
		add(A,B,C,D,&X,&Y);
        subtract(A,B,C,D,&X,&Y);
        multiply(A,B,C,D,&X,&Y);
        divide(A,B,C,D,&E,&F);
		return main();
	}
}