#pragma once



template<class T>
bool is_equal(T a,T b){
	return a == b;
}

template<>	//ģ����ػ�
bool is_equal<char*>(char* a, char* b) {
	return strcmp(a,b)==0;
}

template<class T1,class T2>
class Data {
private:
	T1 a1;
	T2 b1;
public:
	Data() { cout << "ԭģ����: template<T1,T2>"<<endl; }
};


template<>		//ȫ�ػ�
class Data<int,char>{
private:
	int a;
	char b;
public:
	Data() { cout << "ȫ�ػ�: template<int,char>" << endl; }


};

template<class T2>		//ƫ�ػ�
class Data<int, T2> {
private:
	int a;
	char b;
public:
	Data() { cout << "ƫ�ػ�: template<int,char>" << endl; }


};


template<class T1,class T2>		//ƫ�ػ�
class Data<T1*, T2*> {			//���ﴫ�������ж�T1,T2Ϊָ�룬���������ػ�ģ������
private:
	int a;
	char b;
public:
	Data() { cout << "ƫ�ػ� * * ָ������: template<T1*,T2*>" << endl; }


};