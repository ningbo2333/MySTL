#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include"template_more.h"

int main() {

	//char* ch1 = "asdcds";
	//char* ch2 = "asdcds";
	//cout << is_equal(1, 1)<<endl;
	//cout << is_equal(ch1, ch2);
	Data<char, char> d1;		//������ģ�����
	Data<int, char> d2;			//ȫ�ػ��Ķ���
	Data<int, double> d3;		//ƫ�ػ��Ķ���
	Data<char*, char*>d4;		//ƫ�ػ�������ָ�����͵Ķ���
	Data<char*, int*>d5;		//ƫ�ػ�������ָ�����͵Ķ���
	system("pause");
	return 0;
}







