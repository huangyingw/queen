// queen.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
static int a[8];
static int b[15];
static int c[15];
static int iQueenNum=0;  //��¼�ܵ�����״̬��
static char Queen[8][8];

void qu(int i);  //����i������


int _tmain(int argc, _TCHAR* argv[])
{
	int iLine,iColumn;

	//���̳�ʼ�����ո�Ϊ*�����ûʺ�ĵط�Ϊ@
	for(iLine=0;iLine<8;iLine++)
	{
	  a[iLine]=0;  //�б�ǳ�ʼ������ʾ���г�ͻ
	  for(iColumn=0;iColumn<8;iColumn++)
	   Queen[iLine][iColumn]='*';
	}
	
	//�����ӶԽ��߱�ǳ�ʼ������ʾû�г�ͻ
	for(iLine=0;iLine<15;iLine++)
	  b[iLine]=c[iLine]=0;
	
	qu(0);
	return 0;
}




void qu(int i)
{
	int iColumn;
	
	for(iColumn=0;iColumn<8;iColumn++)
	{
	  if(a[iColumn]==0&&b[i-iColumn+7]==0&&c[i+iColumn]==0) //����޳�ͻ
	  {
	   Queen[iColumn]='@'; //�Żʺ�
	   a[iColumn]=1;   //��ǣ���һ�θ����ϲ��ܷŻʺ�
	   b[i-iColumn+7]=1;  //��ǣ���һ�θ����Խ����ϲ��ܷŻʺ�
	   c[i+iColumn]=1;   //��ǣ���һ�θôӶԽ����ϲ��ܷŻʺ�
	   if(i<7) qu(i+1);  //����л�û�б����꣬������һ��
	   else     //�������
	   {
	    //�������״̬
	    int iLine,iColumn;
	    printf("��%d��״̬Ϊ��\n",++iQueenNum);
	    for(iLine=0;iLine<8;iLine++)
	    {
	     for(iColumn=0;iColumn<8;iColumn++)
	      printf("%c  ",Queen[iLine][iColumn]);
	     printf("\n");
	    }
	    printf("\n\n");
	   }
	   
	   //���ǰ�εĻʺ���õ��º���ķ���������ζ���������Ҫ������ݣ�����
	   Queen[iColumn]='*';
	   a[iColumn]=0;
	   b[i-iColumn+7]=0;
	   c[i+iColumn]=0;
	  }
	}
} 