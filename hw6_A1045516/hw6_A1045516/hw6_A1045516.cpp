#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int main(void)
{
	char num[40]={0},get[40]={0};//�ŧinum�}�C�����J�ȡAget�}�C����r�ꤤ������
	int i,j=0,length,flag=0;//�ŧii���j��ѼơAj��get�}�C���ĴX���Alength���r����סAflag���P�_�r��̬O�_������
	printf("Please enter a code.\n");
	//�P�_�ϥΪ̿�J�ȡA�p�G��J���Ȥ��OEOF�h�~��{���i��A�_�h���}�{��
	while((scanf("%s",&num))!=EOF)
	{
		length=strlen(num);
		//�P�_�r����׬O�_���b�d�򤺡A�S���h���s��J�s���r��
	    while(strlen(num)<10 || strlen(num)>30)
	    {
		    printf("INCORRECT\n");
		    return main();
	    }
	    for(i=0;i<length;i++)
	    {
			/*�P�_�r�ꤤ��Ⱶ�s���Ʀr�����A�᭱���Ʀr���L�j��e�����ƨ⭿�A�p�G���h���s��J�s���r��A�B�p�G(num[i]-48)��
			��0�h�P�w�����T��*/
	        if((num[i]-48)*2<(num[i+1]-48) && (num[i]-48)!=0)
	        {
		        printf("INCORRECT\n");
		        return main();
	        }
	        else
			//�P�_�r��O�_���j��r��A�p�G���O�h���s��J�s���r��
	        if(i<length/2)
	        {
		        if(num[i]!=num[length-i-1])
	            {
		            printf("INCORRECT\n");
			        return main();
	            }
	        }
			//�p�G�H�W����󧡦��ߡA�h�h�d�ݦr����Y���L���ơA�p�G���h��iget���}�C��
	        if((num[i]-48)%2==0)
	        {
			    get[j]=num[i];
			    j++;
			    flag=1;
	        }
	    }
		//�P�_�r�ꤤ�O�_�����ơA�p�G�S���h�n�D���s��J�A�p�G���h�N�r�ꤤ��������ܥX��
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