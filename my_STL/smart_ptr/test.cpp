#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
using namespace std;
#include"smatrptr.h"
int f1(int a, int b) {
	int* p = new int;
	smartprt<int>p0(p);//��������ָ�뱣�ܣ������������Զ�����
	smartprt<int>p1(new int);//Ҳ����ֱ��newһ������ָ����
	*p1 = 10;//������ֵ����
	smartprt<pair<int, int>>p2(new pair<int, int>);
	p2->first = 10, p2->second = 20;//������ͷ����
	if (b == 0) {
		throw string("��0����");
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
	
	//����ָ��Ŀ�
	smartprt<int>p1(new int);
	smartprt<int>p2(p1);
	smartprt<int>p3(new int);
	p3 = p2;
	//p2��p1ָ���һ��������������ʱ�����������Σ�����

	//�������
	//1.����Ȩת��   C++98���������Ȩת��  auto_ptr
	//2.��ֹ����	C++11�����ֱ�Ӳ��ÿ���
	//3.���ü���	C++11��������ü����Ĺ�����
	return 0;
}