//hw1_A1045516
#include<stdio.h>
#include<stdlib.h>
//�{���i�J�I
int main(void)
{
	int a,b;//�ŧi��J�ܼ�
	int c,d,e,f;//�ŧifor���j���ܼ�
    printf("Please enter two numbers a b:");//�n�D��J��ӼƦr
	scanf("%d %d",&a,&b);//��J��ӼƦr
	//while�j��,�]�wa�Mb�ܼƽd��,���p���ŦX�ݭ��s��J
	while(a<1 || a>35 || b<1 || b>5)
	{
		printf("Out of range.Please enter again.\n");
		printf("Please enter two numbers a b:");
	    scanf("%d %d",&a,&b);
	}
	//for�j��,���ⳡ��:for���ҥ]�t���e�T��for�O�٧ΤW�b��,��T��for�O�٧ΤU�b��
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
//�{������
system("pause");
return 0;
}
