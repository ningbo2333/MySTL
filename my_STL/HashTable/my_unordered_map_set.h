#pragma once
#include"HashTable.h"






template<class K, class V,class hash=hashfun<K>>
class my_unordered_map {
	struct MapOfT {		//仿函数
		//取传入类型的Key值，如果传的是key-value模型
		const K& operator()(const pair<K,V>& kv) {
			return kv.first;
		}
	};
private:
	HashTbale<K, pair<K, V>,MapOfT,hash> hash_map;
public:
	typedef typename _HashIterator<K, pair<K, V>, MapOfT, hash> Iterator;  // 这里需要放到publlic区
	pair<Iterator,bool> insert(const pair<K, V>& kv) {
		return hash_map.insert(kv);
	}
	Iterator begin() {
		return hash_map.begin();
	}
	Iterator end() {
		return hash_map.end();
	}
	V& operator[](const K& key) {
		pair<Iterator, bool> ret = hash_map.insert(make_pair(key,V()));
		return ret.first->second;
	}
	 
};

template<class K, class hash = hashfun<K>>
class my_unordered_set {
public:
	struct SetOfT {
		//取k 这里模型是Key
		const K& operator()(const K& key) {//仿函数
			return key;
		}
	};
private:
	HashTbale<K, K, SetOfT, hash> hash_set;

public:
	typedef typename _HashIterator<K, K, SetOfT, hash> Iterator;

	pair<Iterator, bool> insert(const K& k) {
		return hash_set.insert(k);
	}
	Iterator begin() {
		return hash_set.begin();
	}
	Iterator end() {
		return hash_set.end();
	}


};