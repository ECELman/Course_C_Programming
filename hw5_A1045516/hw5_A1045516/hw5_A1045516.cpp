#include<stdlib.h>
#include<stdio.h>
int main(void)
{
	int seed,time1,time2,time3;//�ŧi�ؤl�M�j��
	float temp;//�ŧi�C�C���[�`
	float matrix[4][4]={0};//�ŧi�@4*4���x�}
	float matrix1[4][4]={0};//�ŧi�@4*4�����x�}
	//�n�D�ϥΪ̿�J�@�Ӽƭȧ@���üƺؤl
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
	//4*4���x�}
	printf("\nThe 4*4 matrix is:\n");
	for(time1=0;time1<4;time1++)
	{
		for(time2=0;time2<4;time2++)
		{
			printf("%3d ",(int)matrix[time1][time2]);
		}
		printf("\n");
	}
	//4*4����m�x�}
	printf("\nThe transpose matrix is:\n");
	for(time1=0;time1<4;time1++)
	{
		for(time2=0;time2<4;time2++)
		{
			printf("%3d ",(int)matrix[time2][time1]);
		}
		printf("\n");
	}
	//4*4���ϯx�}
	printf("\nThe inverse matrix is:\n");
	//�]�@�ӳ��x�}�A�R�W��matrix1
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
	//�ϯx�}�B��
	for(time1=0;time1<4;time1++)
    {
        temp=0;
		//��C�ۥ[
        for(time2=0;time2<4;time2++)
		{
			temp+=matrix[time1][time2]; 
		}
		//�Y���@�C����0�A�h��ܦ��x�}�L�k�D�X�ϯx�}
        if(temp==0)
        {
            printf("���x�}�L�k�D�X�ϯx�}�I\n");
			system("pause");
            return 0;
        }
		//����matrix�x�}�D�﨤�u�����O�_��1�A����1�h��C�P�����Ӥ���1����
        if(matrix[time1][time1]!=1)
        {
            temp=matrix[time1][time1];
            for(time2=0;time2<4;time2++)
            {
                matrix[time1][time2]=matrix[time1][time2]/temp;
                matrix1[time1][time2]=matrix1[time1][time2]/temp;
            }
        }
        //�P��Y���O�s�A�h��C�P���@���ƥh����s�����C
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
	//�L�X�ϯx�}
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