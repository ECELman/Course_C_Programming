#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(void)
{
	int player;//�n�D�ϥΪ̿�J�Q�n��ֹ�ԡC
	int range;//�n�D���a�q�@�ӼƦr�C
	int min=1;//�]�w�̤p�ȡC
	int	max=99;//�]�w�̤j�ȡC
	int count=0;//���ѼƬO���F�p��H�M�H��Ԫ����ơA�Q�Φ��ƥh���H2���l�ƨӧP�_�����@�Ӫ��a�q�Ʀr�C
	int flag;//���ѼƬO�Φb�H�M�q������ԡA��H�q���Ʀr�ɡA�hflag�N�|�ܦ�1�A�o�ɴN���q���q�C
	int computer;//���ѼƬO�h���w�üƩҲ��ͥX�Ӫ��ȡA�A�h�@���P�_�̤j�ȩM�̤p�Ȫ��d�򪺰ѼơC
	srand(time(NULL));//�]�w�H���üƪ��ؤl�A�קK�Ҳ��ͥX�Ӫ��üƦ��ҭ��ơC
	int number = (rand()%99)+1;//���ѼƬO�h���w�b1��99���d�򤤩Ҳ��ͥX�Ӫ��üơA�A�h����������a�ҿ�J�����O�j�٬O�p�C
	char answer;//���ѼƬO�Ψӳ]�w�ϥΪ̬O�_�n�~�򪱹C���A�Y���n�h���}�C���C
	printf("Welcome to this game\n");
	printf("Playing with computer please press 1\n");
	printf("Playing with other player please press 2\n");
	scanf("%d",&player);
	//�P�_���a�ҿ�J���ȬO�_�O1��2�A�Y���O�h�n�D���a���s�q�Ʀr�����J���T����C
	while(player!=1 && player!=2)
	{
		printf("Out of ramge.Please enter again.\n");
		scanf("%d",&player);
	}
	//�Y�ϥΪ̿�J���T�h�i�J���j��A�åB�}�l�C���C
	while(player==1 || player==2)
	{
	 max=99;
	 min=1;
	 switch(player)
	 {
	 //���a�M���a��ԡC
	 case 2:
	  while(player==2)
	  {
		printf("The code is between %d and %d.\n",min,max);
		printf("Player%d input your guess.\n",count%2);
		scanf("%d",&range);
		//����j�p�A�ò��ͷs���̤j�ȩM�̤p��
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
		 //���a�q���C�������C
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

	 //���a�M�q�����
	 case 1:
	  while(player==1)
	  {
		printf("The code is between %d and %d.\n",min,max);
		printf("Player0 input your guess.\n");
		scanf("%d",&range);
		//����j�p�A�ò��ͷs���̤j�ȩM�̤p��
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
		 //���a�q���C�������C
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
			 //����j�p�A�ò��ͷs���̤j�ȩM�̤p��
			 if(computer>number)
		     {
			    max=computer-1;
		     }
			 else
		     if(computer<number)
		     {
			    min=computer+1;
		     }
			 //�q���q���C�������C
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