#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

template<class T>
class vector {
private:
	T* _a;//定义指向数组的指针
	int _capacity;//容量
	int _size;//定义当前的长度
public:
	vector():_a(nullptr),_capacity(0),_size(0){}
	~vector() { 
		assert(_a);
		delete _a; }
	void push_back(const T&);
	void pop_back();
	int size() { return _size; }
	T& operator[](int& i) {  
		return _a[i]; }
};


template<class T>
void vector<T>::push_back(const T&num) {
	if (_size == _capacity) {
		int newcapacity = _capacity == 0 ? 2 : 2 * _capacity;//判断当前的容量是否为0，如果是0，那么新的为2，如果不是0，就为旧的的2倍
		T* tmp = new T[newcapacity];
		if (_a) {//如果原来第一次是空，则跳过这个赋值过程
			memcpy(tmp, _a, sizeof(T) * _size);//利用memcpy函数拷贝到新的，其中拷贝的是字节数
		}
		delete _a;
		_a = tmp;
		_capacity = newcapacity;
	}
	_a[_size++] = num;
}

template<class T>
void vector<T>::pop_back() {
	_size--;
}

//template<class T>
//template<class T>
//template<class T>






