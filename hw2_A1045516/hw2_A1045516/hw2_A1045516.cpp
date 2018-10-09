#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(void)
{
	int a;//要求使用者輸入數值範圍。
	int b;//外迴圈參數。
	int c;//用來指定平方根所開出來的值。
	int d;//內迴圈參數。
	int flag;//用來判斷真或假，如果為真則為質數，如果為假則不為質數。
	printf("Please enter a number from 2 to 1000000\n");
	scanf("%d",&a);
	//設定範圍限制，如果超出範圍則要求重新輸入新的範圍，直到正確為止。
	while(a<2||a>1000000)
	{
		printf("Out of range.Please enter again.\n");
		printf("Please enter a number from 2 to 1000000\n");
	    scanf("%d",&a);
	}
	//找尋質數的迴圈。
    for(b=2;b<=a;b++)
    {
      c=int(sqrt(float(b)));
      flag=1;
      for(d=2;d<=c;d++)
      {
         if(b%d==0)
		 {
         flag = 0;
		 }
      }
      if(flag)
      {
         printf("%d\n",b);
      }
    }

/*注意此程式所遇到的障礙是，
第一個當在使用sqrt(a)此函事時裏頭a這個參數必須是浮點數才行，否則在執行時會產生錯誤
，而解決辦法就是先將裡頭的a做float的轉換，再將整個sqrt(b)做int的轉換
第二個當使用%這個符號時，前後必須都是整數才行，否則會出現錯誤
第三個加快程式執行速度，想要加快程式執行速度就必須減少條件式的判斷，因為一旦判斷一多執行的速度相對就會變慢，
尤其是在迴圈中跑判斷式是最傷時間的
第四個此處我們利用了一個小技巧那就是flag，我們設定每個值剛進來迴圈時flag=1，如果此數可被整除就代表此樹不是質數
，則flag就會變成0，如果持續是1那就是質數了*/

system("pause");
return 0;
}
