#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

template<class T>
class vector {
private:
	T* _a;//����ָ�������ָ��
	int _capacity;//����
	int _size;//���嵱ǰ�ĳ���
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
		int newcapacity = _capacity == 0 ? 2 : 2 * _capacity;//�жϵ�ǰ�������Ƿ�Ϊ0�������0����ô�µ�Ϊ2���������0����Ϊ�ɵĵ�2��
		T* tmp = new T[newcapacity];
		if (_a) {//���ԭ����һ���ǿգ������������ֵ����
			memcpy(tmp, _a, sizeof(T) * _size);//����memcpy�����������µģ����п��������ֽ���
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






