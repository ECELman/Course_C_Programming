#include<stdlib.h>
#include<stdio.h>
//�]�wC(n,k)�����j�禡�A�Q��C(n,k) = C(n-1,k-1) + C(n-1,k)���ʽ�C
int c(int n,int k)
{
	if(n==k||k==0)
	{
		return 1;
	}
	else
	{
		return c(n-1,k-1)+c(n-1,k);
	}
}
int main(void)
{
	int object;
	int get;
	printf("n = ");
	scanf("%d",&object);
	//�]�w���J���Ȥp��s�ɡA�ݭ��s��J�C
	while(object<0)
	{
		printf("Your number is not an integer.Please enter again.\n");
	    printf("n = ");
	    scanf("%d",&object);
	}
	printf("k = ");
	scanf("%d",&get);
	//�]�w���J���Ȥp��s�ɡA�ݭ��s��J�C
	while(get<0)
	{
		printf("Your number is not an integer.Please enter again.\n");
	    printf("k = ");
	    scanf("%d",&get);
	}
	//�]�w��object�ҿ�J���Ȥp��get�ҿ�J���ȮɡA�ݭ��s��J�C
	while(object<get)
	{
		printf("Your number of object is not enough.Please enter again.\n");
	    printf("n = ");
	    scanf("%d",&object);
		//�]�w���J���Ȥp��s�ɡA�ݭ��s��J�C
	    while(object<0)
	    {
		    printf("Your number is not an integer.Please enter again.\n");
	        printf("n = ");
	        scanf("%d",&object);
	    }
	    printf("k = ");
	    scanf("%d",&get);
		//�]�w���J���Ȥp��s�ɡA�ݭ��s��J�C
	    while(get<0)
	    {
		    printf("Your number is not an integer.Please enter again.\n");
	        printf("k = ");
	        scanf("%d",&get);
	    }
	}
	printf("C(%d,%d) = %d\n",object,get,c(object,get));

system("pause");
return 0;
}