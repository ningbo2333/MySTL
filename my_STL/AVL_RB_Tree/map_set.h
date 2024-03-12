#pragma once
#include"set_map_RBTree.h"
namespace kzx {

template<class K,class V>//模拟实现map
class my_map {
public:
	struct MapKOfT {//仿函数，返回map的frist
		const K& operator()(const pair<K,V>& kv) {
			return kv.first;
		}
	};

	private:
		RBTree<K, pair<K, V>,MapKOfT> _t;
public:
		typedef typename RBTree<K, pair<K,V>, MapKOfT>::iterator iterator;//定义map的迭代器，这里注意要加额外加typename
		bool insert(const pair<K,V>& kv) {
			return _t.insert(kv);
		}
		void print() {
			_t.midorder();
		}
		iterator begin() {
			return _t.begin();
		}
		iterator end() { return _t.end(); }

};


template<class K>
class my_set {
	//模拟实现set
public:
	struct SetKOfT{//仿函数，set只有一个值，那么就是返回的该值
		const K& operator()(const K& data) {
			return data;
	}
	};
private:
	RBTree<K, K,SetKOfT>_t;
public:
	typedef typename RBTree<K, K, SetKOfT>::iterator iterator;
	bool insert(const K& x) {
		return _t.insert(x);
		//红黑树的插入
	}
	void print() {
		_t.midorder();
		//红黑树的中序遍历
	}
	iterator begin() {
		return _t.begin();
	}
	iterator end() { return _t.end(); }
};

void test_my_map() {
	my_map<int, int>m;
	vector<int>nums{6, 1, 2, 10, -5, -85, -101, -6, 12, 66, 54, -35, 0};
	for (auto& e : nums) {
		m.insert(make_pair(e, e));
	}
	//m.print();
	my_map<int,int>::iterator it = m.begin();
	while (it != m.end()) {
		cout << it->first << ":"<<it->second<<endl;
		++it;
	}
	cout << endl;
}


void test_my_set() {
	my_set<int>se;
	vector<int>nums{99, 1, 2, 10, -5, -95, -101, -6, 12, 66, 54, -35, 0};
	for (auto& e : nums) {
		se.insert(e);
	}
	//se.print();
	my_set<int>::iterator it = se.begin();
	while (it != se.end()) {
		cout << *it<<" ";
		++it;
	}
	cout << endl;
	for (auto& e : se) {
		cout << e << " ";
	}
	cout << endl;
}

}


