#include <iostream>
#include <string>

using namespace std;

#define   student_num  100
#define specialnum_num 3

void Init(int *sp, int *st);
bool specialnumisgood(int *sp);
bool isfirstnumincluded(int stn, int fsp);
string sayFBW(int stn, int *sp);
void printanswer(string *a);
void countoff(int *st, int *sp, string *a);

void Init(int *sp,int *st)
{
	int i;
	int temp;
	do{
		cout << "请输入三个特殊数：" << endl << "要求为3个不相等的个位数" << endl << "如果不符合要求会要求您重新输入" << endl;
		for (i = 0; i < specialnum_num; i++)
		{
			cin >> sp[i];
		}
	} while (!specialnumisgood(sp));
	for (i = 0; i < student_num; i++)
	{
		st[i] = i + 1;
	}

}

bool specialnumisgood(int *sp)
{
	int i,j;
	for (i = 0; i < specialnum_num; i++)
		if (sp[i] < 0 || sp[i]>9)
			return false;
	for (i = 0; i < specialnum_num-1; i++)
		for (j = i + 1; j < specialnum_num; j++)
			if (sp[i] == sp[j])
				return false;
	return true;
}

bool isfirstnumincluded(int stn, int fsp)//判断学号中是否含有第一个数
{
	int i;
	char buff[10];//学号最大100 有3位数
	itoa(stn, buff, 10);
	string temp = buff;
	int len = temp.length();
	for (i = 0; i < len; i++)//逐位判断是否包含第一个数
	{
		itoa(fsp, buff, 10);
		string t = buff;
		if (temp[i] == t[0])
			return true;
	}
	return false;
}


void countoff(int *st,int *sp, string *a)//由学号产生报数
{
	int i;
	for (i = 0; i < student_num; i++)//从第一个孩子开始
	{
		if (!isfirstnumincluded(st[i],sp[0]))//学号不包含第一个数
		{
			a[i]=sayFBW(st[i],sp);
		}
		else	a[i] ="Fizz";
	}
	printanswer(a);
}

string sayFBW(int stn,int *sp)
{
	bool isFBW = 0;
	string temp = "";
	if (stn / sp[0] > 0 && stn%sp[0] == 0)
	{
		temp = temp + "Fizz";
		isFBW = 1;
	}		
	if (stn / sp[1] > 0 && stn%sp[1] == 0)
	{
		temp = temp + "Buzz";
		isFBW = 1;
	}		
	if (stn / sp[2] > 0 && stn%sp[2] == 0)
	{
		temp = temp + "Whizz";
		isFBW = 1;
	}
	if (!isFBW)	
    {
		char buff[10];//学号最大100 有3位数
		itoa(stn, buff, 10);
		temp = buff;
	}
	return temp;
}

void printanswer(string *a)
{
	int i;
	for (i = 0; i < student_num; i++)
		cout << a[i] << "\t";
}
