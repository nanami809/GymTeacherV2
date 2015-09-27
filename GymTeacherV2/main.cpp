#include "Header.h";

void main()
{
	int i;
	int specialnum[specialnum_num];//特殊数
	int studentnum[student_num];//学号
	string answer[100];//用字符串存储答案

	Init(specialnum,studentnum);	
	countoff(studentnum,specialnum,answer);
	cout <<endl<< "谢谢参与！";
	cin >> i;
}
