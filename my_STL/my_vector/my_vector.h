#pragma once
#include<iostream>
#include<assert.h>
#include<algorithm>
#include<string>
namespace kzx_vector {

	template<class T>
	class vector {
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		vector() :_start(nullptr), _finish(nullptr), _end_of_storage(nullptr) {

		}

		vector(vector<T>& tmp) {
			//_start = new T[tmp.capacity()];
			//_finish = _start ;
			//_end_of_storage = _start + tmp.capacity();
			//for (int i = 0; i < tmp.size(); i++) {
			//	*_finish = tmp[i];
			//	_finish++;
			//}		//朴素写法
			_start=_finish=_end_of_storage = nullptr;
			reserve(tmp.capacity());//先将容量开好，省时间
			for (auto& e : tmp) {
				push_back(e);//每次向后推入数据
			}
		}

		~vector() {
			delete[] _start;
		}
		void push_back(const T& x) {
			if (size() == capacity()) {
				size_t newcapacity = capacity() == 0 ? 2 : capacity() * 2;//新容量扩容，需要判断是否为空的容量
				reserve(newcapacity);
			}
			*_finish= x;
			_finish++;
		}

		void reserve(size_t newcapacity) {//扩容
			size_t  len = size();
			T* temp = new T[newcapacity];
			if (capacity()!=0) {
				for (int i = 0; i < len; i++) {
					temp[i] = *_start;
				}
			}
			delete[]_start;
			
			_start = temp;
			_finish = _start + len;
			_end_of_storage = _start +newcapacity;
		}

		void pop_back()//尾删
		{
			assert(_start < _finish);
			_finish--;
		}

		void insert(iterator pos,const T &x) {//插入元素
			assert(pos <=_finish);
			size_t len= pos-_start;
			if (_finish==_end_of_storage) {
				size_t newcapacity = capacity() == 0 ? 2 : capacity() * 2;//新容量扩容，需要判断是否为空的容量
				reserve(newcapacity);
				pos = _start + len;
			}
			iterator it = end()-1;
			while (it >= pos) {
				*(it+1) = *it;
				it--;
			}
			*pos = x;
			_finish++;
		}

		iterator erase(iterator pos) {//删除/释放某个位置的元素
			assert(pos>=_start || pos<_finish);
			while (pos != end()) {
				*pos = *(pos + 1);
				pos++;
			}
			_finish--;
			return pos + 1;
		}


		void resize(size_t i,const T& val=T()) {//重新设置长度，这里要注意分情况讨论
			if (i <= size()) {
				_finish = _start + i;}
			else if (i > size() && i < capacity()) {
				size_t sub = i - size();
				while (sub > 0) {
					*_finish = val;
					_finish++;
					sub--;
				}
			}
			else if (i > size() && i > capacity()) {
				size_t newcapacity = capacity() == 0 ? 2 : 2 * capacity();
				reserve(newcapacity);
				size_t sub = i - size();
				while (sub > 0) {
					*_finish = val;
					_finish++;
					sub--;
				}
			}

		}

		T& operator[](size_t i) {
			assert(i < size());
			return *(_start + i);
		}

		const T& operator[] (size_t i) const//只读
		{
			return *(_start + i);
		}


		vector<T>& operator=(vector<T>& v) {//重载赋值运算符
	

			vector<T>temp(v);//创建一个临时变量
			swap(_start, v._start);
			swap(_finish,v._finish);//因为一开始就是空，要换的是个临时变量
			swap(_end_of_storage, v._end_of_storage);
			return *this;
			//reserve(v.capacity());
			//_start =_finish=_end_of_storage= nullptr;
			//for(auto& e : v) {
			//	push_back(e);
			//}
			//return *this;		//写法二


			//reserve(v.capacity());
			//for (int i = 0; i < v.size(); i++) {
			//	*_finish = v[i];
			//	_finish++;
			//}		//朴素写法
			//return *this;
		}

		iterator begin() {//迭代器开始的位置
			return _start;}
	
		const_iterator begin() const{//const性质的迭代器开始的位置
			return _start;}

		iterator end() {//迭代器结束的位置
			return _finish;}

		const_iterator end() const{//const类型的迭代器
			return _finish; }
		size_t size() { return _finish - _start; }//获取vector的长度，指针相减

		size_t capacity() { return _end_of_storage - _start; }//获取容量


	private:
		iterator _start;//定义开始
		iterator _finish;//定义有效的结束
		iterator _end_of_storage;//定义容量的位置



	};


	

	void test1() {
		//vector<int> v;
		//v.push_back(1);
		//v.push_back(2);
		//v.push_back(3);
		//v.push_back(4);
		//v.push_back(5);
		//v.push_back(6);
		//v.push_back(6);
		//v.insert(v.begin() + 2,100);
		//v.push_back(8);
		//cout << v.capacity()<<endl;
		//v.resize(10);//1 2 100 3 4 5 6 6 8
		//vector<int>::const_iterator it = v.begin();
		//for (auto& e : v) {
		//	cout << e << " ";
		//}
		//v.erase(v.begin());
		//vector<int> v2;
		//cout << endl;
		//v2 = v;
		//for (auto& e : v2) {
		//	cout << e << " ";
		//}
		//for (int i = 0; i < v.size(); i++) {
		//	std::cout << v[i] << " ";
		//}
		//vector<int>::iterator it = v.begin();
		//while(it!=v.end()){
		//	std::cout <<*it<< " ";
		//	it++;
		//}
		/*cout << endl;
		vector<int>::const_iterator cit = v.begin();
		for (auto& e : v) {
			cout << e<<" ";
		}*/
		//while (cit != v.end()) {
		//	cout<<*cit ;
		//	cit++;
		//}
		string s1 = "1111";
		string s2 = "1111";
		vector<string> s;
		s.push_back("1111166666665555555");
		s.push_back("1111166666665555555");
		s.push_back("1111166666665555555");
		for (auto e : s) {
			cout << e << endl;
		}

	}
}



