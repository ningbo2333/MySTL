#pragma once


template<class T>
class smartprt {
private:
	T* _ptr;
	int* _pcount;
public:
	smartprt(T* ptr) :_ptr(ptr),_pcount(new int(1)) {}//���캯��ʱ���ʼ��Ϊ1
	

	smartprt(smartprt<T> &sp):_ptr(sp._ptr),_pcount(sp._pcount){
		++(*_pcount);//����һ�Σ�pcount��һ��
	}
	//1.����Ȩת��   C++98���������Ȩת��  auto_ptr
	//smartprt(smartprt<T>&ap):_ptr(ap._ptr){
	//	ap._ptr = nullptr;//ת�ƹ���Ȩ���൱�ڰ�ԭ���ĸ��ÿգ��Լ�ָ��ԭ������
	//	//���ְ취��ʵ��
	//}
	//2.��ֹ������ֱ�Ӷ��幹�캯��=0������ʵ��
	//3.����һ����̬�ڴ�ļ�����

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
			cout << "����ָ���ͷ�:"<<_ptr<<endl;
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

