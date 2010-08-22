// queen.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
static int a[8];
static int b[15];
static int c[15];
static int iQueenNum=0;  //记录总的棋盘状态数
static char Queen[8][8];

void qu(int i);  //参数i代表行


int _tmain(int argc, _TCHAR* argv[])
{
	int iLine,iColumn;

	//棋盘初始化，空格为*，放置皇后的地方为@
	for(iLine=0;iLine<8;iLine++)
	{
	  a[iLine]=0;  //列标记初始化，表示无列冲突
	  for(iColumn=0;iColumn<8;iColumn++)
	   Queen[iLine][iColumn]='*';
	}
	
	//主、从对角线标记初始化，表示没有冲突
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
	  if(a[iColumn]==0&&b[i-iColumn+7]==0&&c[i+iColumn]==0) //如果无冲突
	  {
	   Queen[iColumn]='@'; //放皇后
	   a[iColumn]=1;   //标记，下一次该列上不能放皇后
	   b[i-iColumn+7]=1;  //标记，下一次该主对角线上不能放皇后
	   c[i+iColumn]=1;   //标记，下一次该从对角线上不能放皇后
	   if(i<7) qu(i+1);  //如果行还没有遍历完，进入下一行
	   else     //否则输出
	   {
	    //输出棋盘状态
	    int iLine,iColumn;
	    printf("第%d种状态为：\n",++iQueenNum);
	    for(iLine=0;iLine<8;iLine++)
	    {
	     for(iColumn=0;iColumn<8;iColumn++)
	      printf("%c  ",Queen[iLine][iColumn]);
	     printf("\n");
	    }
	    printf("\n\n");
	   }
	   
	   //如果前次的皇后放置导致后面的放置无论如何都不能满足要求，则回溯，重置
	   Queen[iColumn]='*';
	   a[iColumn]=0;
	   b[i-iColumn+7]=0;
	   c[i+iColumn]=0;
	  }
	}
} 