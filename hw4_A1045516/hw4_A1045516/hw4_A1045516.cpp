#include<stdlib.h>
#include<stdio.h>
//設定C(n,k)的遞迴函式，利用C(n,k) = C(n-1,k-1) + C(n-1,k)之性質。
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
	//設定當輸入的值小於零時，需重新輸入。
	while(object<0)
	{
		printf("Your number is not an integer.Please enter again.\n");
	    printf("n = ");
	    scanf("%d",&object);
	}
	printf("k = ");
	scanf("%d",&get);
	//設定當輸入的值小於零時，需重新輸入。
	while(get<0)
	{
		printf("Your number is not an integer.Please enter again.\n");
	    printf("k = ");
	    scanf("%d",&get);
	}
	//設定當object所輸入的值小於get所輸入的值時，需重新輸入。
	while(object<get)
	{
		printf("Your number of object is not enough.Please enter again.\n");
	    printf("n = ");
	    scanf("%d",&object);
		//設定當輸入的值小於零時，需重新輸入。
	    while(object<0)
	    {
		    printf("Your number is not an integer.Please enter again.\n");
	        printf("n = ");
	        scanf("%d",&object);
	    }
	    printf("k = ");
	    scanf("%d",&get);
		//設定當輸入的值小於零時，需重新輸入。
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