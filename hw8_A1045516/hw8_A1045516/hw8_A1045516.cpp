#include<stdlib.h>
#include<stdio.h>
#include<math.h>
int main()
{
	int time;//�ŧi�����n�D�ϥΪ̿�J�@�ӭȡA�ӥh�N���U�ӷ|��J�h�ֵ���{�������
	int	i,j;//�ŧi�j��Ѽ�
	int	num[5][2]={0};//�ŧi�@�ӤG���}�C�ӥh�s���ϥΪ̩ҿ�J����{������
	int	test;//�ŧi�����n�D�ϥΪ̿�J�@�ӷQ�a�J��{�����Ѽ�
	int total=0;//�ŧi�����[�`�U���a�J�Ѽƫ᪺��
	int counter=0;//�ŧi�����ӥh�@���B��L�{�����P�_
	scanf("%d",&time);//�n�D�ϥΪ̿�J�@�ӭȡA�ӥh�N���U�ӷ|��J�h�ֵ���{�������
	//�p�G�ҿ�J���Ȥp��1�Ϊ̬O�j��5�A�h�n�D�ϥΪ̭��s��J
	while(time<1 || time>5)
	{
		printf("��J���ȹL�j�A�Э��s��J\n");
		scanf("%d",&time);
	}
	//�n�D�ϥΪ̿�J��{������
	for(i=0;i<time;i++)
	{
		scanf("%d %d",&num[i][0],&num[i][1]);
		//�p�G�ᶵ�����Ƶ���e�������ơA�h�n�D�ϥΪ̭��s��J
		while(num[i][1]==num[i-1][1])
		{
			printf("���ƶ����ơA�Э��s��J\n");
		    scanf("%d %d",&num[i][0],&num[i][1]);
		}
		//�p�G�ᶵ�����Ƥj��e�������ơA�h�n�D�ϥΪ̭��s��J			
		while(num[i][1]>num[i-1][1] && i!=0)
		{
			printf("�������Ƥj��e�����ơA�Э��s��J\n");
			scanf("%d %d",&num[i][0],&num[i][1]);
		    while(num[i][1]==num[i-1][1])
		    {
			     printf("���ƶ����ơA�Э��s��J\n");
		         scanf("%d %d",&num[i][0],&num[i][1]);
		    }
		}
	}
	scanf("%d",&test);//�n�D�ϥΪ̿�J�@�ӷQ�a�J��{�����Ѽ�
	//��ڳ̰��������Ƥj�󵥩�0�ɡA�h�@�����ư���
	while(num[0][1]>=0)
	{
        for(i=0;i<time;i++)
		{
			//���P�_����O���F���L�Ĥ@������{��
			if(counter!=0)
		    {
		        num[i][0]*=num[i][1];
		        num[i][1]=num[i][1]-1;
		    }
			//���P�_����O��ڳ̰��������ܦ�-1�ɡA�h���X�j��A�_�h�L�X�C�Ӥ�{������
			if(num[i][1]<0)
			{
			    continue;
			}
			else
			{
		    printf("%3d %d    ",num[i][0],num[i][1]);
			}
	    }
		//���C�ӫ��Ʊa�J�Ѽƫ᪺�ȶi��ۥ[
	    for(i=0;i<time;i++)
	    {
		    total+=num[i][0]*pow((double)test,num[i][1]);
	    }
		//���P�_����O��ڪ�total����0�h���X�j��A�_�h�L�X��total����
		if(total==0)
		{
			break;
		}
		else
		{
	        printf("%d\n",total);
		}
		total=0;//�Ntotal�k0�A�קK�Ʀr�֥[���Ʊ��o��
		counter++;//����while�̪��{���X���]���A�hcounter�[1
	}

system("pause");
return 0;
}