﻿#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<time.h>
#define size 21 /*設定一巨集名稱為size，其大小可以任意設定數值，
                  但其數值必須是奇數才行否則會造成地圖的顯示是錯誤的，也就是會少下方那一行和左方那一行*/

int map[size+2][size+2]={0};//宣告一個整數變數且其名稱為map，用來存放各個位置的值
void create(int x,int y) //此create的function是為了随機生成迷宫
{
    int c[4][2]={0,1,1,0,0,-1,-1,0}; //這裡的二維數組代表方向，上下左右
    int i,j,t;//宣告i,j,t變數來去用在for迴圈裡面
    //此for迴圈目的是為了將方向的順序打亂，隨機的由來
    for(i=0;i<4;i++)
    {
        j=rand()%4;//隨機生成0~3的數值
        t=c[i][0];
		c[i][0]=c[j][0];
		c[j][0]=t;
        t=c[i][1];
		c[i][1]=c[j][1];
		c[j][1]=t;
    }
    map[x][y]=1;//把當前坐標設為1
	//每一次遞迴都會走完四個方向。保證了全圖的遍歷
    for(i=0;i<4;i++)
	{
		//如果當前方向前面的第二個還是牆的話
        if(map[x+2*c[i][0]][y+2*c[i][1]]==0)
        {
             map[x+c[i][0]][y+c[i][1]]=1;//把當前方向前面第一個設為1
             create(x+2*c[i][0],y+2*c[i][1]);/*遞迴到前面第二個,這部分要注意到的一點是：如果遞迴到前面第二個的話第二個一定會被設為1
			                                  ,也就是說每一次條件成立的話就會將兩個坐標設為1,這也是為什麼一定要是奇數的原因*/
        }
	}
}

int main()
{
	srand(time(NULL));//輸入此行目的是為了讓其數值可以隨機產生
	int i,j,total=0,x=1,y=2,a=size-1,b=size,p1=0,p2=0;//宣告迴圈和金幣總數以及人物位置的座標軸變數
	char move,answer;//宣告接收字元值的變數
	printf("歡迎來到吃金幣遊戲，請放到全螢幕\n並按任意鍵開始。\n");
    printf("player1操作說明:上w 下s 左a 右d\nplayer2操作說明:上8 下5 左4 右6\n");
	move=getch();//來去隨意接受鍵盤所輸進來的按鍵
	system("cls");//宣告此行目的是為了清除一開始的畫面，這樣子才能使得其地圖能隨後產生出來
	for(i=0;i<=size+1;i++)
	{
        for(j=0;j<=size+1;j++)
		{
            if(i==0||i==size+1||j==0||j==size+1) //此行是為了去初始化迷宫
			{
                map[i][j]=1;
			}
            else 
			{
				map[i][j]=0;
			}
		}
	}
	create(2*(rand()%(size/2)+1),2*(rand()%(size/2)+1));
	map[1][2]=3; //給定一個入口
    map[size-1][size]=4; //給定一個出口
	for(i=1;i<=size;i++)
	{
		for(j=1;j<=size;j++)
		{
			if(map[i][j]==1)
			{
				map[i][j]=rand()%2+1;
			}
		}
	}
	//將地圖給印出來
	for(i=1;i<=size;i++)
	{
		for(j=1;j<=size;j++)
		{
			if(map[i][j]==0)//如果其陣列元素等於0則印出牆壁
				printf("■");
			if(map[i][j]==1)//如果其陣列元素等於1則印出空格
				printf("  ");
			if(map[i][j]==2)//如果其陣列元素等於2則印出小點
			{
				printf(" .");
				total++;//計算其金幣數總共有幾個
			}
            if(map[i][j]==3)//如果其陣列元素等於3則印出P1
				printf("P1");
			if(map[i][j]==4)//如果其陣列元素等於4則印出P2
				printf("P2");
		}
		printf("\n");
	}
	printf("P1 coin : %d\nP2 coin : %d\n",p1,p2);//此行來去顯示P1和P2分別吃了多少的金幣
	//當其total的值不等於0則繼續執行while裡的程式，因為代表其還有其餘的金幣存在
	while(total!=0)
	{
		move=getch();//從鍵盤上接收W,A,S,D和4,5,6,8的方向鍵
		//下列if分別去偵測是否接收到對應的字元
	    if(move=='w')
		{
			if(map[x-1][y]!=0 && x-1!=0 && map[x-1][y]!=map[a][b])/*此行是為了以防撞牆或超出地圖範圍
				                                                    或其P1和P2相遇會蓋掉對方*/
			{
				if(map[x-1][y]==2)//如果其陣列元素等於2代表其玩家吃到了金幣
				{
				    total--;//其總數減1
				    p1++;//P1吃到的金幣數加1
				}
				map[x][y]=1;//其原來位置的元素值變成1也就是變成空格
				x--;//x的值減1
				map[x][y]=3;//變化過的位置座標其元素數值變成3也就是變成P1
			}
		}
		if(move=='s')
		{
			if(map[x+1][y]!=0 && map[x+1][y]!=map[a][b])/*此行是為了以防撞牆或其P1和P2相遇會蓋掉對方*/
			{
				if(map[x+1][y]==2)//如果其陣列元素等於2代表其玩家吃到了金幣
				{
				    total--;//其總數減1
				    p1++;//P1吃到的金幣數加1
				}
				map[x][y]=1;//其原來位置的元素值變成1也就是變成空格
				x++;//x的值加1
				map[x][y]=3;//變化過的位置座標其元素數值變成3也就是變成P1
			}
		}
		if(move=='a')
		{
			if(map[x][y-1]!=0 && map[x][y-1]!=map[a][b])/*此行是為了以防撞牆或其P1和P2相遇會蓋掉對方*/
			{
				if(map[x][y-1]==2)//如果其陣列元素等於2代表其玩家吃到了金幣
				{
				    total--;//其總數減1
				    p1++;//P1吃到的金幣數加1
				}
				map[x][y]=1;//其原來位置的元素值變成1也就是變成空格
				y--;//y的值減1
				map[x][y]=3;//變化過的位置座標其元素數值變成3也就是變成P1
			}
		}
		if(move=='d')
		{
			if(map[x][y+1]!=0 && y+1!=size+1 && map[x][y+1]!=map[a][b])/*此行是為了以防撞牆或超出地圖範圍
				                                                         或其P1和P2相遇會蓋掉對方*/
			{
				if(map[x][y+1]==2)//如果其陣列元素等於2代表其玩家吃到了金幣
				{
				    total--;//其總數減1
				    p1++;//P1吃到的金幣數加1
				}
				map[x][y]=1;//其原來位置的元素值變成1也就是變成空格
				y++;//y的值加1
				map[x][y]=3;//變化過的位置座標其元素數值變成3也就是變成P1
			}
		}
		if(move=='8')
		{
			if(map[a-1][b]!=0 && a-1!=0 && map[a-1][b]!=map[x][y])/*此行是為了以防撞牆或超出地圖範圍
				                                                    或其P1和P2相遇會蓋掉對方*/
			{
				if(map[a-1][b]==2)//如果其陣列元素等於2代表其玩家吃到了金幣
				{
				    total--;//其總數減1
				    p2++;//P2吃到的金幣數加1
				}
				map[a][b]=1;//其原來位置的元素值變成1也就是變成空格
				a--;//a的值減1
				map[a][b]=4;//變化過的位置座標其元素數值變成4也就是變成P2
			}
		}
		if(move=='5')
		{
			if(map[a+1][b]!=0 && map[a+1][b]!=map[x][y])/*此行是為了以防撞牆或其P1和P2相遇會蓋掉對方*/
			{
				if(map[a+1][b]==2)//如果其陣列元素等於2代表其玩家吃到了金幣
				{
				    total--;//其總數減1
				    p2++;//P2吃到的金幣數加1
				}
				map[a][b]=1;//其原來位置的元素值變成1也就是變成空格
				a++;//a的值加1
				map[a][b]=4;//變化過的位置座標其元素數值變成4也就是變成P2
			}
		}
		if(move=='4')
		{
			if(map[a][b-1]!=0 && map[a][b-1]!=map[x][y])/*此行是為了以防撞牆或其P1和P2相遇會蓋掉對方*/
			{
				if(map[a][b-1]==2)//如果其陣列元素等於2代表其玩家吃到了金幣
				{
				    total--;//其總數減1
				    p2++;//P2吃到的金幣數加1
				}
				map[a][b]=1;//其原來位置的元素值變成1也就是變成空格
				b--;//b的值減1
				map[a][b]=4;//變化過的位置座標其元素數值變成4也就是變成P2
			}
		}
		if(move=='6')
		{
			if(map[a][b+1]!=0 && b+1!=size+1 && map[a][b+1]!=map[x][y])/*此行是為了以防撞牆或超出地圖範圍
				                                                         或其P1和P2相遇會蓋掉對方*/
			{
				if(map[a][b+1]==2)//如果其陣列元素等於2代表其玩家吃到了金幣
				{
				    total--;//其總數減1
				    p2++;//P2吃到的金幣數加1
				}
				map[a][b]=1;//其原來位置的元素值變成1也就是變成空格
				b++;//b的值加1
				map[a][b]=4;//變化過的位置座標其元素數值變成4也就是變成P2
			}
		}
		system("cls");//宣告此行目的是為了清除一開始的畫面，這樣子才能使得其地圖能重新產生出來
		//將地圖給印出來
		for(i=1;i<=size;i++)
	    {
		    for(j=1;j<=size;j++)
		    {
			    if(map[i][j]==0)//如果其陣列元素等於0則印出牆壁
				    printf("■");
			    if(map[i][j]==1)//如果其陣列元素等於1則印出空格
				    printf("  ");
			    if(map[i][j]==2)//如果其陣列元素等於2則印出小點
			    {
				    printf(" .");
			    }
                if(map[i][j]==3)//如果其陣列元素等於3則印出P1
				    printf("P1");
				if(map[i][j]==4)//如果其陣列元素等於4則印出P2
				    printf("P2");
		    }
		    printf("\n");
	    }
		printf("P1 coin : %d\nP2 coin : %d\n",p1,p2);//此行來去顯示P1和P2分別個吃了多少的金幣
	}
	//如果p1的值大於p2的值代表其p1吃到的金幣比p2還要多，則印出p1贏得了勝利
	if(p1>p2)
	{
		system("cls");//宣告此行目的是為了清除一開始的畫面，這樣子才能使得其隨後的結果印出來
		printf("player1贏了。\n要繼續嗎?\n要請按y 不要請按其他任意鍵\n");
		answer=getch();//來去抓取其鍵盤的按鍵
		//如果讀到的值是大寫Y或者是小寫y代表其玩家要繼續玩		
		if(answer=='y' || answer=='Y')
		{
			system("cls");//清空螢幕上所有的畫面
			return main();//回到main的主程式
		}
		//假如其讀到的值不是大寫Y或者是小寫y則代表玩家不想玩了，則其程式中止
		else
		{
			system("pause");
            return 0;
		}
	}
	//如果p1的值小於p2的值代表其p1吃到的金幣比p2還要少，則印出p2贏得了勝利
	else if(p1<p2)
	{
		system("cls");//宣告此行目的是為了清除一開始的畫面，這樣子才能使得其隨後的結果印出來
		printf("player2贏了。\n要繼續嗎?\n要請按y 不要請按其他任意鍵\n");
		answer=getch();//來去抓取其鍵盤的按鍵
		//如果讀到的值是大寫Y或者是小寫y代表其玩家要繼續玩		
		if(answer=='y' || answer=='Y')
		{
			system("cls");//清空螢幕上所有的畫面
			return main();//回到main的主程式
		}
		//假如其讀到的值不是大寫Y或者是小寫y則代表玩家不想玩了，則其程式中止
		else
		{
			system("pause");
            return 0;
		}
	}
	//如果p1的值等於p2的值代表其p1吃到的金幣和p2是一樣多的，則印出p1和p2平手
	else if(p1==p2)
	{
		system("cls");//宣告此行目的是為了清除一開始的畫面，這樣子才能使得其隨後的結果印出來
		printf("player1和player2平手。\n要繼續嗎?\n要請按y 不要請按其他任意鍵\n");
		answer=getch();//來去抓取其鍵盤的按鍵
		//如果讀到的值是大寫Y或者是小寫y代表其玩家要繼續玩		
		if(answer=='y' || answer=='Y')
		{
			system("cls");//清空螢幕上所有的畫面
			return main();//回到main的主程式
		}
		//假如其讀到的值不是大寫Y或者是小寫y則代表玩家不想玩了，則其程式中止
		else
		{
			system("pause");
            return 0;
		}
	}
}