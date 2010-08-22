// queen.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
static int column_strike[8];
static int master_diagonal[15];
static int slave_diagonal[15];
static int iQueenNum=0;  //��¼�ܵ�����״̬��
static char Queen[8][8];

void qu(int i);  //����i������

int _tmain(int argc, _TCHAR* argv[])
{
	int nav,iColumn;

	//���̳�ʼ�����ո�Ϊ*�����ûʺ�ĵط�Ϊ@
	for(nav=0;nav<8;nav++)
	{
	  column_strike[nav]=0;  //�б�ǳ�ʼ������ʾ���г�ͻ
	  for(iColumn=0;iColumn<8;iColumn++)
			Queen[nav][iColumn]='*';
	}
	
	//�����ӶԽ��߱�ǳ�ʼ������ʾû�г�ͻ
	for(nav=0;nav<15;nav++)
		master_diagonal[nav]=slave_diagonal[nav]=0;

	qu(0);
	return 0;
}

void qu(int i)
{
	for(int iColumn=0;iColumn<8;iColumn++)
	{
	  if(column_strike[iColumn]==0&&master_diagonal[i-iColumn+7]==0&&slave_diagonal[i+iColumn]==0) //����޳�ͻ
	  {
			Queen[i][iColumn]='@'; //�Żʺ�
			column_strike[iColumn]=1;   //��ǣ���һ�θ����ϲ��ܷŻʺ�
			master_diagonal[i-iColumn+7]=1;  //��ǣ���һ�θ����Խ����ϲ��ܷŻʺ�
			slave_diagonal[i+iColumn]=1;   //��ǣ���һ�θôӶԽ����ϲ��ܷŻʺ�
			if(i<7) qu(i+1);  //����л�û�б����꣬������һ��
			else     //�������
			{
			 	//�������״̬
			 	int iColumn;
			 	printf("��%d��״̬Ϊ��\n",++iQueenNum);
			 	for(int nav=0;nav<8;nav++)
			 	{
			 		for(iColumn=0;iColumn<8;iColumn++)
						printf("%c  ",Queen[nav][iColumn]);
	  		 	printf("\n");
		  	}
	  		printf("\n\n");
	  	}
	  	//���ǰ�εĻʺ���õ��º���ķ���������ζ���������Ҫ������ݣ�����
	  	Queen[i][iColumn]='*';
	  	column_strike[iColumn]=0;
	  	master_diagonal[i-iColumn+7]=0;
	  	slave_diagonal[i+iColumn]=0;
		}
	}
} 