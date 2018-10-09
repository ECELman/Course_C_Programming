#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(void)
{
	int player;//要求使用者輸入想要跟誰對戰。
	int range;//要求玩家猜一個數字。
	int min=1;//設定最小值。
	int	max=99;//設定最大值。
	int count=0;//此參數是為了計算人和人對戰的次數，利用次數去除以2的餘數來判斷換哪一個玩家猜數字。
	int flag;//此參數是用在人和電腦的對戰，當人猜完數字時，則flag就會變成1，這時就換電腦猜。
	int computer;//此參數是去指定亂數所產生出來的值，再去作為判斷最大值和最小值的範圍的參數。
	srand(time(NULL));//設定隨機亂數的種子，避免所產生出來的亂數有所重複。
	int number = (rand()%99)+1;//此參數是去指定在1到99的範圍中所產生出來的亂數，再去做為比較玩家所輸入的直是大還是小。
	char answer;//此參數是用來設定使用者是否要繼續玩遊戲，若不要則離開遊戲。
	printf("Welcome to this game\n");
	printf("Playing with computer please press 1\n");
	printf("Playing with other player please press 2\n");
	scanf("%d",&player);
	//判斷玩家所輸入的值是否是1或2，若不是則要求玩家重新猜數字直到輸入正確為止。
	while(player!=1 && player!=2)
	{
		printf("Out of ramge.Please enter again.\n");
		scanf("%d",&player);
	}
	//若使用者輸入正確則進入此迴圈，並且開始遊戲。
	while(player==1 || player==2)
	{
	 max=99;
	 min=1;
	 switch(player)
	 {
	 //玩家和玩家對戰。
	 case 2:
	  while(player==2)
	  {
		printf("The code is between %d and %d.\n",min,max);
		printf("Player%d input your guess.\n",count%2);
		scanf("%d",&range);
		//比較大小，並產生新的最大值和最小值
		if(range>=min && range<=max)
		{
		 if(range>number)
		 {
			max=range-1;
		 }
		 else
		 if(range<number)
		 {
			min=range+1;
		 }
		 //玩家猜中遊戲結束。
		 else
		 {
			 printf("Bomb!! Player%d dead!\n",count%2);
			 printf("Try again <Y/N> ?");
	         scanf("%s",&answer);
			 if((char)answer=='Y' || (char)answer=='y')
			 {
				 min=1;
				 max=99;
				 count=-1;
				 number = (rand()%99)+1;
				 system("cls");
				 printf("Welcome to this game\n");
	             printf("Playing with computer please press 1\n");
	             printf("Playing with other player please press 2\n");
	             scanf("%d",&player);
				 while(player!=1 && player!=2)
	             {
		            printf("Out of ramge.Please enter again.\n");
		            scanf("%d",&player);
	             }
			 }
			 else
			 {
				  system("pause");
				  return 0;
			 }
		 }
		 count++;
		}
		else
		 {
			printf("Range error.\n");
		 }
	  }
	  break;

	 //玩家和電腦對戰
	 case 1:
	  while(player==1)
	  {
		printf("The code is between %d and %d.\n",min,max);
		printf("Player0 input your guess.\n");
		scanf("%d",&range);
		//比較大小，並產生新的最大值和最小值
		if(range>=min && range<=max)
		{
		 if(range>number)
		 {
			max=range-1;
			flag=1;
		 }
		 else
		 if(range<number)
		 {
			min=range+1;
			flag=1;
		 }
		 //玩家猜中遊戲結束。
		 else
		 {
			 printf("Bomb!! Player0 dead!\n");
			 printf("Try again <Y/N> ?");
	         //scanf("%s",&answer);
			 if((answer=getchar())=='Y' || (answer=getchar())=='y')
			 {
	             flag=0;
				 min=1;
				 max=99;
				 number = (rand()%99)+1;
				 system("cls");
				 printf("Welcome to this game\n");
	             printf("Playing with computer please press 1\n");
	             printf("Playing with other player please press 2\n");
	             scanf("%d",&player);
				 while(player!=1 && player!=2)
	             {
		            printf("Out of ramge.Please enter again.\n");
		            scanf("%d",&player);
	             }
			 }
			 else
			 {
				  system("pause");
				  return 0;
			 }
		 }
		}
		else
		{
			printf("Range error.\n");
			flag=0;
		}
		if(flag)
		 {
			 printf("The code is between %d and %d.\n",min,max);
			 computer=(rand()%(max-min+1))+min;
			 printf("Computer guess %d.\n",computer);
			 //比較大小，並產生新的最大值和最小值
			 if(computer>number)
		     {
			    max=computer-1;
		     }
			 else
		     if(computer<number)
		     {
			    min=computer+1;
		     }
			 //電腦猜中遊戲結束。
			 else
		     {
			  printf("Bomb!! Computer is dead!\n");
			  printf("Try again <Y/N> ?");
	          //scanf("%s",&answer);
			  if((answer=getchar())=='Y' || (answer=getchar())=='y')
			  {
	             flag=0;
				 min=1;
				 max=99;
				 number = (rand()%99)+1;
				 system("cls");
				 printf("Welcome to this game\n");
	             printf("Playing with computer please press 1\n");
	             printf("Playing with other player please press 2\n");
	             scanf("%d",&player);
				 while(player!=1 && player!=2)
	             {
		            printf("Out of ramge.Please enter again.\n");
		            scanf("%d",&player);
	             }
			  }
			  else
			  {
				  system("pause");
				  return 0;
			  }
		     }
         }
	  }
	   break;
	  }
	 }

system("pause");
return 0;
}