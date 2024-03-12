#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include <iomanip>
using namespace std;
#include"kzx_inherit.h"


class A {
public:
	virtual void fun() { cout << "A"<<endl; }
private:
	int _A;
};


class a :public A {
public :
	void fun() {cout << "a"<<endl;}
};

void print_buy(person_price& p) {
	p.buy();
}


int main() {
	////*****
	//Student s;
	//Student s2(s);
	//person_price p;
	//stu s1;
	//solder j;
	//print_buy(p);
	//print_buy(s1);
	//print_buy(j);
	//person p1(18,1,"jack");
	//person p2 = p1;
	////*****
	//Student s1,s2;
	//s1 = s2;
	/*A A1;
	a a1;*/
	//A& cur = A1;
	//cur.fun();
	//A& cur1 = a1;
	//cur1.fun();
	return 0;
}




