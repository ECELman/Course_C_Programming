#include<stdlib.h>
#include<stdio.h>
//�@�[�k�B��
void add(int A, int B, int C, int D, int *X, int *Y)
{
	*X=A+C;
	*Y=B+D;
	printf("(A + Bi) + (C + Di): %d + %di\n",*X,*Y);
}
//�@��k�B��
void subtract(int A, int B, int C, int D, int *X, int *Y)
{
	*X=A-C;
	*Y=B-D;
	printf("(A + Bi) - (C + Di): %d + %di\n",*X,*Y);
}
//�@���k�B��
void multiply(int A, int B, int C, int D, int *X, int *Y)
{
	*X=A*C+B*D*-1;
	*Y=A*D+B*C;
	printf("(A + Bi) * (C + Di): %d + %di\n",*X,*Y);
}
//�@���k�B��
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
	int A,B,C,D;//�ŧi�|���ܼƤ��O�s����J���|�Ӽƭ�
	int	X=0,Y=0;//�ŧi��Ӹ�ƫ��O����ƪ��ܼơA�]�����Щҫ��쪺���e�����P���Ƹ�ƫ��O�ۦP�A�Φb�[�B��B��������
	float E=0,F=0;//�ŧi��Ӹ�ƫ��O���B�I�ƪ��ܼơA�]�����Щҫ��쪺���e�����P���Ƹ�ƫ��O�ۦP�A�Φb��������
	printf("Please enter four number to express two complex number : A + Bi and C + Di.\n");
	printf("If you want to quit, please enter four 0\n");
	scanf("%d %d %d %d",&A,&B,&C,&D);//�n�D�ϥΪ̿�J�|�Ӽƭ�
	//�p�G�|�Ӽƭȳ��O0�h����{���A�_�h�e�{�X��B�⵲�G�í��s�}�l�D�{��
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