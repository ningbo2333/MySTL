#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<list>
#include<map>
#include<string>
#include<queue>
//#include<priority_queue>
using namespace std;

//void f(const int& x) { cout << "const ��ֵ" << endl; }
//void f(int&& x) { cout << "��ֵ" << endl; }
//void f(int& x) { cout << "��ֵ"<<endl; }
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
//	// 1. C++11�Ļ����ŵ��б��ʼ��
//	//int x = 1;
//	//int y{ 2 };//��ʼ����������
//	//vector<int>v{1, 2, 3, 4};//��������Ҳ֧��
//	//vector<int>v = {1, 2, 3, 4};//��������Ҳ֧��
//	//list<int>l{5, 6, 8, 7, 9};//listҲ֧��
//	//map<string, int>mp{{"one", 1}, { "two",2 }};//mapҲ֧���Զ���
//	//map<string, int>mp = {{"one", 1}, {"two",2}};//mapҲ֧���Զ���
//	//��Ҳ���ԣ�ʵ��Ҳ�ǵ�����Ĺ��캯��
//	//student s1("С��",18);
//	//student s1={"С��",18};
//	//student s1{"С��",18};	//	����������һ��
//	//
//	//2.����ʶ��(�˽�)
//	//int a = 10, b = 20;
//	//auto c = a + b;
//	//cout << typeid(c).name()<<endl;//���ӡ��int����ĸ����ʾ����
//	////2.1�������ǲ�֪��c�����ͣ���������Ҫ����һ����cһ�������͵ı�����ô������decltype(c)
//	//decltype(c) d;//������һ������d����c������һ��
//	//
//	//
//	//3. Ĭ�ϳ�Ա��������
//	//������Ƕ�����һ���������캯����
//	//ͨ����������Ǳ����ڶ��幹�캯�����Ų��ᱨ��
//	//������������ϵͳĬ������һ�����캯���������Լ����죬�������������ͻᱨ����ô����취:
//	//class A{
//	//public:
//	//	//A() = default;//ָ����ʾ����ϵͳ����һ��Ĭ�Ϲ��캯����ϵͳĬ�����ɵ�
//	//	//A(const A& temp) {
//	//	//	//������һ���������캯��
//	//	//}
//	//	//3.1������Ƕ���һ�����󣬲��ܱ���ֵ�����ܱ���������ô����
//	//	A& operator=(const A& a) = delete;
//	//	A(const A& a) = delete;//����ֵ�Ϳ������캯��ɾ�������������������������൱��
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
//	////auto add1 = [](int x, int  y) ->int {return x + y; };//û��ʡ��->type�İ汾
//	//auto add1 = [](int x, int  y){return x + y; };//һ�����->int����ʡ�ԣ���Ϊreturn �����Ϳ�����
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
	if(nums.size()==0) throw(string("����f1������"));
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




