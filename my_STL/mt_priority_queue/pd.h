#pragma once
#include<vector>

namespace kzx_priority_queue {
	//仿函数
template<class T>
struct less {
	bool operator()(const T& a, const T& b) {
		return a < b;
	}
};
//仿函数
template<class T>
struct greater {
	bool operator()(const T& a, const T& b) {
		return a > b;
	}
};



template<class T,class Container=vector<T>,class Compare=less<T>>
class priority_queue {
private:
	Container _con;
public:
	//向上调整
	void adjustup(int child) {
		Compare com;
		int parent = (child - 1) / 2;
		while (child > 0) {
			if (com( _con[parent],_con[child])) {
				swap(_con[child], _con[parent]);
				child = parent;
				parent = (parent - 1) / 2;
			}
			else { break; }
		}
	}
	//向下调整
	void adjustdown(int root) {
		Compare com;
		int parent = root;
		int child = (root*2)+1;
		while (child<_con.size()) {
			if (child+1<_con.size()&&com(_con[child] , _con[child + 1])) {
				child += 1;
			}
			if (com(_con[parent],_con[child] )) {
				swap(_con[child], _con[parent]);
				parent=child;
				child= parent*2+1;
			}
			else {
				break; }
		}
	}
	void push(const T& x) {//推进数据
		_con.push_back(x);
		adjustup(_con.size() - 1);//每次进一个，则再最后边进行向上调整
	}
	void pop() {
		swap(_con[0],_con[_con.size()-1]);//因为堆顶的数据是要删的，那么每次交换堆底和堆顶，然后向下调整，保证堆顶是次大（次小）的
		_con.pop_back();
		adjustdown(0);//向下调整
	}
	T& top() {
		return _con[0];//取堆顶元素
	}
	size_t size() { return _con.size(); }

	bool empty(){return _con.empty();}//判断是否为空
	
	
};

void test() {
	priority_queue<int,vector<int>,greater<int>> q;
	q.push(0);
	q.push(4);
	q.push(3);
	q.push(2);
	q.push(1);
	q.push(1000);
	q.push(20);
	q.push(51);
	q.push(13);
	q.push(-12);
	while (!q.empty()) {
		cout << q.top()<<" ";
		q.pop();
}

}


}








//void adjustdown(vector<int>&nums,int root=0,int len=0)//向下调整
//{
//	int parent = root,child=2*parent+1;
//	while (child < len) {
//		if (child < len&&nums[child] < nums[child + 1]) {
//			child += 1;
//		}
//		if (child < len && nums[child] > nums[parent]) {
//			swap(nums[child], nums[parent]);
//			parent = child;
//			child = 2 * parent+1;
//		}
//		if (child < len && nums[parent] > nums[child]) {
//			break;
//		}
//	}
//}
//
//void heapsort(vector<int>&nums) {
//	int len = nums.size()-1;
//	int end = (len-1)  / 2;
//	while (end >= 0) {
//	adjustdown(nums,end,len);
//	end--;
//	}
//
//}


