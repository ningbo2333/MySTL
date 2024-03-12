#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include"template_more.h"

int main() {

	//char* ch1 = "asdcds";
	//char* ch2 = "asdcds";
	//cout << is_equal(1, 1)<<endl;
	//cout << is_equal(ch1, ch2);
	Data<char, char> d1;		//正常类模板对象
	Data<int, char> d2;			//全特化的对象
	Data<int, double> d3;		//偏特化的对象
	Data<char*, char*>d4;		//偏特化，遇到指定类型的对象
	Data<char*, int*>d5;		//偏特化，遇到指定类型的对象
	system("pause");
	return 0;
}







