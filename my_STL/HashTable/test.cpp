#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
using namespace std;
#include"HashTable.h"
#include"my_unordered_map_set.h"




// //以下是闭散列的测试*******
// 
//void close_hash()
//{
//	HashTable<int,int,SetOfT<int>>hash;
//	hash.insert(4);
//	hash.insert(12);
//	hash.insert(2);
//	hash.insert(15);
//	hash.insert(16);
//	hash.insert(81);
//	hash.insert(19);
//	hash.insert(22);
//	hash.insert(31);
//	hash.insert(45);
//	hash.insert(42);
//	hash.insert(23);
//	hash.insert(47);
//	hash.insert(7);
//	hash.insert(88);
//	hash.insert(99);
//	hash.insert(102);
//}
// //以上是闭散列的测试**********

//void test_open_hash() {
//	//HashTbale<int, int, SetOfT<int>>hash;
//	//hash.insert(5);
//	//hash.insert(88);
//	//HashNode<int>* it = hash.find(78);
//	//HashNode<int>* it2 = hash.find(7888);//查找元素
//	//hash.erase(88);
//	//hash.erase(452);
//	//HashTbale<string, string, SetOfT<string>,hashstring<string>>hash;	//没有特化的
//	//hash.insert("hello");
//	//HashTbale<string, string, SetOfT<string>>hash2;						//经过特化的
//	//hash2.insert("abs");
//
//
//}


void test_my_unordered_set() {
	my_unordered_set<int> mset;
	mset.insert(2);
	mset.insert(48);
	mset.insert(99);
	mset.insert(46);
	mset.insert(57);
	mset.insert(89);
	mset.insert(135);
	mset.insert(64);
	my_unordered_set<int>::Iterator it = mset.begin();
	while (it != mset.end()) {
		cout << *it << " ";
		++it;
	}
}


void test_my_unordered_map(){
	my_unordered_map<string, string> mp;
	mp.insert(make_pair("name", "名字"));
	mp.insert(make_pair("wait", "等待"));
	mp.insert(make_pair("broke", "打破"));
	mp.insert(make_pair("basic", "基本的"));
	mp.insert(make_pair("project", "项目"));
	mp.insert(make_pair("class", "班级"));
	mp.insert(make_pair("silcent", "沉默的"));
	mp["hello"] = "哈喽";
	mp["year"] = "年";
	my_unordered_map<string, string>::Iterator it = mp.begin();
	while (it != mp.end()) {
		cout << it->first << ":" << it->second<<endl;
		++it;
	}
}

int main() {

	//test_open_hash();
	//test_my_unordered_set();
	test_my_unordered_map();
	return 0;
}