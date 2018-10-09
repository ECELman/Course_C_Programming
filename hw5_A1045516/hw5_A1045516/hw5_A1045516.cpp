#include<stdlib.h>
#include<stdio.h>
int main(void)
{
	int seed,time1,time2,time3;//宣告種子和迴圈
	float temp;//宣告每列的加總
	float matrix[4][4]={0};//宣告一4*4的矩陣
	float matrix1[4][4]={0};//宣告一4*4的單位矩陣
	//要求使用者輸入一個數值作為亂數種子
	printf("Please enter a number to set a seed.\n");
	scanf("%d",&seed);
	srand(seed);
	for(time1=0;time1<4;time1++)
	{
		for(time2=0;time2<4;time2++)
		{
			matrix[time1][time2]=rand()%199+(-99);
		}
	}
	//4*4的矩陣
	printf("\nThe 4*4 matrix is:\n");
	for(time1=0;time1<4;time1++)
	{
		for(time2=0;time2<4;time2++)
		{
			printf("%3d ",(int)matrix[time1][time2]);
		}
		printf("\n");
	}
	//4*4的轉置矩陣
	printf("\nThe transpose matrix is:\n");
	for(time1=0;time1<4;time1++)
	{
		for(time2=0;time2<4;time2++)
		{
			printf("%3d ",(int)matrix[time2][time1]);
		}
		printf("\n");
	}
	//4*4的反矩陣
	printf("\nThe inverse matrix is:\n");
	//設一個單位矩陣，命名為matrix1
	for(time1=0;time1<4;time1++)
	{
		for(time2=0;time2<4;time2++)
		{
			if(time1==time2)
			{
				matrix1[time1][time2]=1;
			}
			else
			{
				matrix1[time1][time2]=0;
			}
		}
	}
	//反矩陣運算
	for(time1=0;time1<4;time1++)
    {
        temp=0;
		//整列相加
        for(time2=0;time2<4;time2++)
		{
			temp+=matrix[time1][time2]; 
		}
		//若有一列等於0，則顯示此矩陣無法求出反矩陣
        if(temp==0)
        {
            printf("此矩陣無法求出反矩陣！\n");
			system("pause");
            return 0;
        }
		//偵測matrix矩陣主對角線元素是否為1，不為1則整列同除那個不為1的數
        if(matrix[time1][time1]!=1)
        {
            temp=matrix[time1][time1];
            for(time2=0;time2<4;time2++)
            {
                matrix[time1][time2]=matrix[time1][time2]/temp;
                matrix1[time1][time2]=matrix1[time1][time2]/temp;
            }
        }
        //同行若不是零，則整列同乘一倍數去減不為零的那列
        for(time2=0;time2<4;time2++)
        {
            if(matrix[time2][time1]!=0 && time2!=time1)
            {
				temp=matrix[time2][time1];
                for(time3=0;time3<4;time3++)
                {
					matrix[time2][time3]=matrix[time2][time3]-(matrix[time1][time3]*temp);
                    matrix1[time2][time3]=matrix1[time2][time3]-(matrix1[time1][time3]*temp);
                }
            }
        }
    }
	//印出反矩陣
    for(time1=0;time1<4;time1++)
    {
		for(time2=0;time2<4;time2++)
        {
			printf("%9.6f ",matrix1[time1][time2]);
        }
        printf("\n");
    }

system("pause");
return 0;
}