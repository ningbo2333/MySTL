#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;
#include"pd.h"








//template<class T, class Container = vector<T>>
//class priority_queue {
//private:
//	Container _con;
//public:
//	void adjustup(int child=0) {
//		int parent = (child - 1) / 2;
//		while (child > 0) {
//			if (_con[child] > _con[parent]) {
//				swap(_con[child], _con[parent]);
//				child = parent;
//				parent = (parent - 1) / 2;
//			}
//			else { break; }
//		}
//	}
//	void push(const T& x) {
//		_con.push_back(x);
//		adjustup(_con.size() - 1);
//	}
//	void pop() {
//		swap(_con[0], _con[_con.size() - 1]);
//		_con.pop_back();
//	}
//	size_t size() { return _con.size(); }
//	//bool empty{return _con.empty();}
//
//
//};

//void test() {
//	priority_queue<int> q;
//	q.push(0);
//	q.push(4);
//	q.push(3);
//	q.push(2);
//	q.push(1);
//}






int main() {
	//vector<int> nums;
	//nums.push_back(8);
	//nums.push_back(100);
	//nums.push_back(1);
	//nums.push_back(5);
	//nums.push_back(12);
	//nums.push_back(100);
	//nums.push_back(500);
	//nums.push_back(12);
	//nums.push_back(12);

	////adjustup(nums);
	//heapsort(nums);
	//for (auto& e : nums) {
	//	cout << e << " ";
	//}
	kzx_priority_queue::test();
	//test();
	return 0;
}









