#include<iostream>
#define SEVERPORT 3333 
using namespace std; 
char m[3][3],p1 = 'a',p2 = 'b';

//初始化

void init()
{
	for (int i=0;i<3;i++)
		for (int j=0;j<3;j++)
			m[i][j] = ('0' + 3 * i + j);
}

//显示棋盘信息

void display(char p, int time)
{
	system("clear");
	cout << "\t对局中...\t\t\t时间： "<< time << endl << endl;
	cout << endl << endl;
	for (int i=0;i<3;i++)
	{
		cout << "\t";
		for (int j=0;j<3;j++)
		{
			cout << "_";
			if (m[i][j] == p)
				cout << "x";
			else if (m[i][j] == ('0' + 3 * i + j ))
				cout << m[i][j];
			else
				cout << "@";
			cout << "_";
			if (j != 2)
				cout << "|";
		}
		cout << endl;
	} 
	cout<<"\t"<<"x => 代表自己 "<<endl;
	cout<<"\t"<<"@ => 代表对方已经下的格子"<<endl;
	cout<<"\t"<<"0~9的数字 => 可以落子的地方"<<endl; 
} 

int check(int x, int y)
{
	return x >= 0 && x<3 && y >= 0 && y < 3;
}

//下子

int input(char p,int x,int y)
{
	if (check(x,y))
		if (m[x][y] == ('0' + 3 * x + y))
		{
			m[x][y] = p;
			return 0;
		}
		else
		{
			cout << endl <<"当前位置已经有棋子了！"<< endl <<"输入回车继续下子..."<<endl;
			while (cin.get() != '\n');
			return 1; 
		}
		else
		{
			cout << endl << "输入的位置不在棋盘中，请输入()0~8" << endl << "输入回车继续下子..." << endl;
			while (cin.get() != '\n');
			return 1; 
		}
		return 0;
} 

//超时按顺序下子，返回自动下子的位置

int overTime()
{
	for (int i=0;i<3;i++)
		for (int j=0;j<3;j++)
			if ((m[i][j] - '0') == (3 * i + j ))
				return 3 * i + j;
	return -1;	
} 

//游戏结束返回1，游戏没结束返回0

int isGameOver(char p, int x, int y)
{
	int sum = 0;
	//判断横坐标
	for (int i=-2;i<=2;i++)
	{
		if(check(x+1,y)&&m[x+i][y] == p)
			sum++;
		else
			sum=0;
		if(sum == 3)
			return 1;
	 } 
	 sum = 0;
	 //判断纵坐标
	 for (int i=-2;i<=2;i++)
	 {
	 	if(check(x,y+1)&&m[x][y+i] == p)
			sum++;
		else
			sum=0;
		if(sum == 3)
			return 1;
	 } 
	 //判断左上到右下
	 for (int i=-2;i<=2;i++)
	 {
	 	if(check(x+1,y+1)&&m[x+1][y+i] == p)
			sum++;
		else
			sum=0;
		if(sum == 3)
			return 1;
	 } 
	 //判断左下到右上
	  for (int i=-2;i<=2;i++)
	 {
	 	if(check(x+1,y-1)&&m[x+1][y-i] == p)
			sum++;
		else
			sum=0;
		if(sum == 3)
			return 1;
	 }  
	 return 0;
 } 
