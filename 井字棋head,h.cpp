#include<iostream>
#define SEVERPORT 3333 
using namespace std; 
char m[3][3],p1 = 'a',p2 = 'b';

//��ʼ��

void init()
{
	for (int i=0;i<3;i++)
		for (int j=0;j<3;j++)
			m[i][j] = ('0' + 3 * i + j);
}

//��ʾ������Ϣ

void display(char p, int time)
{
	system("clear");
	cout << "\t�Ծ���...\t\t\tʱ�䣺 "<< time << endl << endl;
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
	cout<<"\t"<<"x => �����Լ� "<<endl;
	cout<<"\t"<<"@ => ����Է��Ѿ��µĸ���"<<endl;
	cout<<"\t"<<"0~9������ => �������ӵĵط�"<<endl; 
} 

int check(int x, int y)
{
	return x >= 0 && x<3 && y >= 0 && y < 3;
}

//����

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
			cout << endl <<"��ǰλ���Ѿ��������ˣ�"<< endl <<"����س���������..."<<endl;
			while (cin.get() != '\n');
			return 1; 
		}
		else
		{
			cout << endl << "�����λ�ò��������У�������()0~8" << endl << "����س���������..." << endl;
			while (cin.get() != '\n');
			return 1; 
		}
		return 0;
} 

//��ʱ��˳�����ӣ������Զ����ӵ�λ��

int overTime()
{
	for (int i=0;i<3;i++)
		for (int j=0;j<3;j++)
			if ((m[i][j] - '0') == (3 * i + j ))
				return 3 * i + j;
	return -1;	
} 

//��Ϸ��������1����Ϸû��������0

int isGameOver(char p, int x, int y)
{
	int sum = 0;
	//�жϺ�����
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
	 //�ж�������
	 for (int i=-2;i<=2;i++)
	 {
	 	if(check(x,y+1)&&m[x][y+i] == p)
			sum++;
		else
			sum=0;
		if(sum == 3)
			return 1;
	 } 
	 //�ж����ϵ�����
	 for (int i=-2;i<=2;i++)
	 {
	 	if(check(x+1,y+1)&&m[x+1][y+i] == p)
			sum++;
		else
			sum=0;
		if(sum == 3)
			return 1;
	 } 
	 //�ж����µ�����
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
