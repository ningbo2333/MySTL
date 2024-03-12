#pragma once


template<class T>
class smartprt {
private:
	T* _ptr;
	int* _pcount;
public:
	smartprt(T* ptr) :_ptr(ptr),_pcount(new int(1)) {}//构造函数时候初始化为1
	

	smartprt(smartprt<T> &sp):_ptr(sp._ptr),_pcount(sp._pcount){
		++(*_pcount);//拷贝一次，pcount加一次
	}
	//1.管理权转移   C++98提出，管理权转移  auto_ptr
	//smartprt(smartprt<T>&ap):_ptr(ap._ptr){
	//	ap._ptr = nullptr;//转移管理权，相当于把原来的给置空，自己指向原来的了
	//	//这种办法不实用
	//}
	//2.防止拷贝，直接定义构造函数=0，更不实用
	//3.开辟一个动态内存的计数器

	smartprt& operator=(smartprt<T>& sp) {
		if (&sp != this) {
			cout << "=" << endl;
			smartprt temp(sp);
			swap(_ptr, sp._ptr);
			swap(_pcount, sp._pcount);
			return *this;
		}
	}



	~smartprt()
	{
		if (--(*_pcount)==0 && _ptr) {
			cout << "智能指针释放:"<<_ptr<<endl;
			delete _ptr;
			delete _pcount;
			_pcount = nullptr;
			_ptr = nullptr;
		}
	}
	T& operator*() {
		return *_ptr;}
	T* operator->(){
		return _ptr; }
};

