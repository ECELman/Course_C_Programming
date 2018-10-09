#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int main(void)
{
	char num[40]={0},get[40]={0};//宣告num陣列抓取輸入值，get陣列抓取字串中的偶數
	int i,j=0,length,flag=0;//宣告i為迴圈參數，j為get陣列的第幾項，length為字串長度，flag為判斷字串裡是否有偶數
	printf("Please enter a code.\n");
	//判斷使用者輸入值，如果輸入的值不是EOF則繼續程式進行，否則離開程式
	while((scanf("%s",&num))!=EOF)
	{
		length=strlen(num);
		//判斷字串長度是否有在範圍內，沒有則重新輸入新的字串
	    while(strlen(num)<10 || strlen(num)>30)
	    {
		    printf("INCORRECT\n");
		    return main();
	    }
	    for(i=0;i<length;i++)
	    {
			/*判斷字串中兩兩接連的數字之間，後面的數字有無大於前面的數兩倍，如果有則重新輸入新的字串，且如果(num[i]-48)等
			於0則判定為正確的*/
	        if((num[i]-48)*2<(num[i+1]-48) && (num[i]-48)!=0)
	        {
		        printf("INCORRECT\n");
		        return main();
	        }
	        else
			//判斷字串是否為迴文字串，如果不是則重新輸入新的字串
	        if(i<length/2)
	        {
		        if(num[i]!=num[length-i-1])
	            {
		            printf("INCORRECT\n");
			        return main();
	            }
	        }
			//如果以上兩條件均成立，則去查看字串裡頭有無偶數，如果有則放進get的陣列內
	        if((num[i]-48)%2==0)
	        {
			    get[j]=num[i];
			    j++;
			    flag=1;
	        }
	    }
		//判斷字串中是否有偶數，如果沒有則要求重新輸入，如果有則將字串中的偶數顯示出來
	    if(flag==0)
	    {
		    printf("NO ANSWER\n");
	        return main();
	    }
	    else
	    {
	        for(i=0;get[i]!='\0';i++)
	        {
			    printf("%d",(get[i]-48));
	        }
	        printf("\n");
		    return main();
	    }
	}

system("pause");
return 0;
}