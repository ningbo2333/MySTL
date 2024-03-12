#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
using namespace std;
#include"smatrptr.h"
int f1(int a, int b) {
	int* p = new int;
	smartprt<int>p0(p);//交给智能指针保管，出了作用域自动销毁
	smartprt<int>p1(new int);//也可以直接new一个，当指针用
	*p1 = 10;//正常赋值操作
	smartprt<pair<int, int>>p2(new pair<int, int>);
	p2->first = 10, p2->second = 20;//正常箭头操作
	if (b == 0) {
		throw string("除0错误");
	}
	delete [] p;
	return a / b;
}

int main() {
	//int a, b;
	//cin >> a >> b;
	//try {
	//	cout << f1(a, b) << endl;
	//}
	//catch (string s) {
	//	cout << s << endl;
	//}
	
	//智能指针的坑
	smartprt<int>p1(new int);
	smartprt<int>p2(p1);
	smartprt<int>p3(new int);
	p3 = p2;
	//p2和p1指向的一样，导致析构的时候析构了两次，报错

	//解决方案
	//1.管理权转移   C++98提出，管理权转移  auto_ptr
	//2.防止拷贝	C++11提出，直接不让拷贝
	//3.引用计数	C++11提出，引用计数的共享拷贝
	return 0;
}