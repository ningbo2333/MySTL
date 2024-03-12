#pragma once



template<class T>
bool is_equal(T a,T b){
	return a == b;
}

template<>	//模板的特化
bool is_equal<char*>(char* a, char* b) {
	return strcmp(a,b)==0;
}

template<class T1,class T2>
class Data {
private:
	T1 a1;
	T2 b1;
public:
	Data() { cout << "原模板类: template<T1,T2>"<<endl; }
};


template<>		//全特化
class Data<int,char>{
private:
	int a;
	char b;
public:
	Data() { cout << "全特化: template<int,char>" << endl; }


};

template<class T2>		//偏特化
class Data<int, T2> {
private:
	int a;
	char b;
public:
	Data() { cout << "偏特化: template<int,char>" << endl; }


};


template<class T1,class T2>		//偏特化
class Data<T1*, T2*> {			//这里传入后，如果判断T1,T2为指针，则进入这个特化模板类中
private:
	int a;
	char b;
public:
	Data() { cout << "偏特化 * * 指针类型: template<T1*,T2*>" << endl; }


};