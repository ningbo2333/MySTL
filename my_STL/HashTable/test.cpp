#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
using namespace std;
#include"HashTable.h"
#include"my_unordered_map_set.h"




// //�����Ǳ�ɢ�еĲ���*******
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
// //�����Ǳ�ɢ�еĲ���**********

//void test_open_hash() {
//	//HashTbale<int, int, SetOfT<int>>hash;
//	//hash.insert(5);
//	//hash.insert(88);
//	//HashNode<int>* it = hash.find(78);
//	//HashNode<int>* it2 = hash.find(7888);//����Ԫ��
//	//hash.erase(88);
//	//hash.erase(452);
//	//HashTbale<string, string, SetOfT<string>,hashstring<string>>hash;	//û���ػ���
//	//hash.insert("hello");
//	//HashTbale<string, string, SetOfT<string>>hash2;						//�����ػ���
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
	mp.insert(make_pair("name", "����"));
	mp.insert(make_pair("wait", "�ȴ�"));
	mp.insert(make_pair("broke", "����"));
	mp.insert(make_pair("basic", "������"));
	mp.insert(make_pair("project", "��Ŀ"));
	mp.insert(make_pair("class", "�༶"));
	mp.insert(make_pair("silcent", "��Ĭ��"));
	mp["hello"] = "���";
	mp["year"] = "��";
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