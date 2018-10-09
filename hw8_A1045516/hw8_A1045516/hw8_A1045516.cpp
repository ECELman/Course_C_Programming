#include<stdlib.h>
#include<stdio.h>
#include<math.h>
int main()
{
	int time;//宣告此項要求使用者輸入一個值，來去代表接下來會輸入多少筆方程式的資料
	int	i,j;//宣告迴圈參數
	int	num[5][2]={0};//宣告一個二維陣列來去存取使用者所輸入的方程式的值
	int	test;//宣告此項要求使用者輸入一個想帶入方程式的參數
	int total=0;//宣告此項加總各項帶入參數後的值
	int counter=0;//宣告此項來去作為運算過程中的判斷
	scanf("%d",&time);//要求使用者輸入一個值，來去代表接下來會輸入多少筆方程式的資料
	//如果所輸入的值小於1或者是大於5，則要求使用者重新輸入
	while(time<1 || time>5)
	{
		printf("輸入的值過大，請重新輸入\n");
		scanf("%d",&time);
	}
	//要求使用者輸入方程式的值
	for(i=0;i<time;i++)
	{
		scanf("%d %d",&num[i][0],&num[i][1]);
		//如果後項的指數等於前項的指數，則要求使用者重新輸入
		while(num[i][1]==num[i-1][1])
		{
			printf("指數項重複，請重新輸入\n");
		    scanf("%d %d",&num[i][0],&num[i][1]);
		}
		//如果後項的指數大於前項的指數，則要求使用者重新輸入			
		while(num[i][1]>num[i-1][1] && i!=0)
		{
			printf("此項指數大於前項指數，請重新輸入\n");
			scanf("%d %d",&num[i][0],&num[i][1]);
		    while(num[i][1]==num[i-1][1])
		    {
			     printf("指數項重複，請重新輸入\n");
		         scanf("%d %d",&num[i][0],&num[i][1]);
		    }
		}
	}
	scanf("%d",&test);//要求使用者輸入一個想帶入方程式的參數
	//當我最高次的指數大於等於0時，則一直重複執行
	while(num[0][1]>=0)
	{
        for(i=0;i<time;i++)
		{
			//此判斷條件是為了跳過第一次的方程式
			if(counter!=0)
		    {
		        num[i][0]*=num[i][1];
		        num[i][1]=num[i][1]-1;
		    }
			//此判斷條件是當我最高次指數變成-1時，則跳出迴圈，否則印出每個方程式的值
			if(num[i][1]<0)
			{
			    continue;
			}
			else
			{
		    printf("%3d %d    ",num[i][0],num[i][1]);
			}
	    }
		//做每個指數帶入參數後的值進行相加
	    for(i=0;i<time;i++)
	    {
		    total+=num[i][0]*pow((double)test,num[i][1]);
	    }
		//此判斷條件是當我的total等於0則跳出迴圈，否則印出其total的值
		if(total==0)
		{
			break;
		}
		else
		{
	        printf("%d\n",total);
		}
		total=0;//將total歸0，避免數字累加的事情發生
		counter++;//當整個while裡的程式碼都跑完，則counter加1
	}

system("pause");
return 0;
}