#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(void)
{
	int a;//�n�D�ϥΪ̿�J�ƭȽd��C
	int b;//�~�j��ѼơC
	int c;//�Ψӫ��w����کҶ}�X�Ӫ��ȡC
	int d;//���j��ѼơC
	int flag;//�ΨӧP�_�u�ΰ��A�p�G���u�h����ơA�p�G�����h������ơC
	printf("Please enter a number from 2 to 1000000\n");
	scanf("%d",&a);
	//�]�w�d�򭭨�A�p�G�W�X�d��h�n�D���s��J�s���d��A���쥿�T����C
	while(a<2||a>1000000)
	{
		printf("Out of range.Please enter again.\n");
		printf("Please enter a number from 2 to 1000000\n");
	    scanf("%d",&a);
	}
	//��M��ƪ��j��C
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

/*�`�N���{���ҹJ�쪺��ê�O�A
�Ĥ@�ӷ�b�ϥ�sqrt(a)����Ʈ����Ya�o�ӰѼƥ����O�B�I�Ƥ~��A�_�h�b����ɷ|���Ϳ��~
�A�ӸѨM��k�N�O���N���Y��a��float���ഫ�A�A�N���sqrt(b)��int���ഫ
�ĤG�ӷ�ϥ�%�o�ӲŸ��ɡA�e�ᥲ�����O��Ƥ~��A�_�h�|�X�{���~
�ĤT�ӥ[�ֵ{������t�סA�Q�n�[�ֵ{������t�״N������ֱ��󦡪��P�_�A�]���@���P�_�@�h���檺�t�׬۹�N�|�ܺC�A
�ר�O�b�j�餤�]�P�_���O�̶ˮɶ���
�ĥ|�Ӧ��B�ڭ̧Q�ΤF�@�Ӥp�ޥ����N�Oflag�A�ڭ̳]�w�C�ӭȭ�i�Ӱj���flag=1�A�p�G���ƥi�Q�㰣�N�N���𤣬O���
�A�hflag�N�|�ܦ�0�A�p�G����O1���N�O��ƤF*/

system("pause");
return 0;
}
