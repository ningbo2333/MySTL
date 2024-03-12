#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<list>
#include<map>
#include<string>
#include<queue>
//#include<priority_queue>
using namespace std;

//void f(const int& x) { cout << "const 左值" << endl; }
//void f(int&& x) { cout << "右值" << endl; }
//void f(int& x) { cout << "左值"<<endl; }
//template<class T>
//void function(T&& x) {
//	f(forward<T>(x));
//}
//vector<int> topKFrequent(vector<int>& nums, int k) {
//	vector<int>res;
//	map<int, int>mp;
//	for (auto& e : nums) mp[e]++;
//
//	priority_queue < pair<int, int>, vector<pair<int, int>>, [](auto& a, auto& b) { return a.second > b.second; }> q;
//
//	//priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
//	for (auto& e : mp) {
//		q.push(make_pair(e.second,e.first));
//	}
//	while (k) {
//		res.push_back(q.top().first);
//		q.pop();
//		k--;
//	}
//	return res;
//
//}

//int main() {
//	// 1. C++11的花括号的列表初始化
//	//int x = 1;
//	//int y{ 2 };//初始化，不常用
//	//vector<int>v{1, 2, 3, 4};//其他容器也支持
//	//vector<int>v = {1, 2, 3, 4};//其他容器也支持
//	//list<int>l{5, 6, 8, 7, 9};//list也支持
//	//map<string, int>mp{{"one", 1}, { "two",2 }};//map也支持自定义
//	//map<string, int>mp = {{"one", 1}, {"two",2}};//map也支持自定义
//	//类也可以，实际也是调用类的构造函数
//	//student s1("小明",18);
//	//student s1={"小明",18};
//	//student s1{"小明",18};	//	这三个功能一样
//	//
//	//2.类型识别(了解)
//	//int a = 10, b = 20;
//	//auto c = a + b;
//	//cout << typeid(c).name()<<endl;//会打印出int的字母，表示整形
//	////2.1假设我们不知道c的类型，但是我们要定义一个跟c一样的类型的变量那么可以用decltype(c)
//	//decltype(c) d;//定义了一个变量d，和c的类型一样
//	//
//	//
//	//3. 默认成员函数控制
//	//如果我们定义了一个拷贝构造函数，
//	//通常情况下我们必须在定义构造函数，才不会报错，
//	//但是我们想让系统默认生成一个构造函数，不想自己构造，但是如果不定义就会报错，那么解决办法:
//	//class A{
//	//public:
//	//	//A() = default;//指定显示的让系统生成一个默认构造函数，系统默认生成的
//	//	//A(const A& temp) {
//	//	//	//定义了一个拷贝构造函数
//	//	//}
//	//	//3.1如果我们定义一个对象，不能被赋值，不能被拷贝，那么可以
//	//	A& operator=(const A& a) = delete;
//	//	A(const A& a) = delete;//将赋值和拷贝构造函数删除掉，这两个函数不存在了相当于
//	//};
//	////A a1;
//	////A a2(a1);
//	//int b;
//	//const int a = 10;
//	//function(10);
//	//function(a);
//	//function(b);
//	//int c = 10;
//	//int a = 4, b = 5;
//	////auto add1 = [](int x, int  y) ->int {return x + y; };//没有省略->type的版本
//	//auto add1 = [](int x, int  y){return x + y; };//一般这个->int可以省略，因为return 的类型可以推
//	//auto add2 = [=]() ->int {return a + b; };
//	//int  q = add1(a, b);
//	//int w = add2();
//	//cout << monotoneIncreasingDigits(1231);
//	vector<int>v{ 4, 1, -1, 2, -1, 2, 3 };
//	//topKFrequent(v, 2);
//	sort(v.begin(), v.end(), [](int& a, int& b) {return a < b; });
//	return 0;
//}



void f1(vector<int>& nums) {
	if(nums.size()==0) throw(string("函数f1的问题"));
}

int main() {
	vector<int>v;
	try {
		f1(v);
	}
	catch (string s) {
		cout << s << endl;
	}
	return 0;

}




