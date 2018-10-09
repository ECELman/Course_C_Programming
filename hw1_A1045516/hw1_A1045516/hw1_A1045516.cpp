//hw1_A1045516
#include<stdio.h>
#include<stdlib.h>
//程式進入點
int main(void)
{
	int a,b;//宣告輸入變數
	int c,d,e,f;//宣告for的迴圈變數
    printf("Please enter two numbers a b:");//要求輸入兩個數字
	scanf("%d %d",&a,&b);//輸入兩個數字
	//while迴圈,設定a和b變數範圍,假如不符合需重新輸入
	while(a<1 || a>35 || b<1 || b>5)
	{
		printf("Out of range.Please enter again.\n");
		printf("Please enter two numbers a b:");
	    scanf("%d %d",&a,&b);
	}
	//for迴圈,分兩部分:for內所包含的前三個for是菱形上半部,後三個for是菱形下半部
	for(c=1;c<=b;c+=1)
	{
		for(d=1;d<=a;d+=1)
		{
		  for(e=a-d;e>0;e-=1)
		  {
			  printf(" ");
		  }
		  for(f=1;f<=d;f+=1)
		  {
			  printf("* ");
		  }
		  printf("\n");
		}

		for(d=a-1;d>0;d-=1)
		{
		  for(e=a-d;e>0;e-=1)
		  {
			  printf(" ");
		  }
		  for(f=d;f>=1;f-=1)
		  {
			  printf("* ");
		  }
		  printf("\n");
		}
	}
//程式結束
system("pause");
return 0;
}
