#pragma once
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cstring>
#include<algorithm>
namespace kzx {
	//class string {
	//private:
	//	char* _str;
	//public:
	//	string(const char* str="") :_str(new char[strlen(str) + 1]) {
	//		strcpy(_str, str);
	//	}
	//	string(const string& s):_str(new char[strlen(s._str)+1]){
	//		strcpy(_str, s._str);
	//	}
	//	string& operator=(const string& s) {
	//		if (this != &s) {
	//			delete[] _str;
	//			_str = new  char[strlen(s._str) + 1];
	//			strcpy(_str, s._str);
	//		}
	//		return *this;
	//	}
	//	char& operator[](size_t i) { return _str[i]; }
	//	size_t size() { return strlen(_str); }
	//	~string() { delete [] _str; _str = nullptr; }
	//	//ostream& operator=(ostream& out) {
	//	//	out << _str;
	//	//	return out;
	//	//}
	//};
	//void test_string() {
	//	string s1;
	//	string s2("hehehehe");
	//	string s3(s2);
	//	string s4 = s3;
	//	string* s = &s1;
	//	s1 = s4;
	//	for (int i = 0; i < s1.size(); i++) {
 // 			std::cout << s1[i] << " ";
	//	}
	//	std::cout << std::endl;
	//	for (int i = 0; i < s2.size(); i++) {
	//		std::cout << s2[i] << " ";
	//	}
	//	//std::cout << s3;
	//}
	class string {
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	public:
		string(const char* str = "") :_str(new char[strlen(str) + 1]) {//构造函数
			strcpy(_str, str);
			_size = strlen(str);
			_capacity = _size;
		}
		string(const string& s) :_str(new char[strlen(s._str) + 1]) {//拷贝复制函数
			strcpy(_str, s._str);
			_size = strlen(s._str);
			_capacity = _size;
		}
		~string() { delete[] _str; _str = nullptr; _size = 0; _capacity = _size; }//析构函数
		char& operator[](int& i) {//运算符[]重载
			return _str[i];
		}
		const char& operator[](int& i)const {//const类型的运算符重载[]
			return _str[i];
		}
		string& operator=(string& s) {//赋值运算符重载=
			delete[]_str;
			_str = new char[strlen(s._str) + 1];
			strcpy(_str, s._str);
			_size = s._size;
			_capacity = s._capacity;
			return *this;
		}
		void push_back(char ch)//增加数据
		{
			if (_size== _capacity) {
				size_t newcapacity = _capacity == 0 ? 2 : 2 * _capacity;
				char* temp = new char[newcapacity+1];
				strcpy(temp, _str);
				delete [] _str;
				_str = temp;
				_capacity = newcapacity;
			}
			_str[_size] = ch;
			_size++;
			_str[_size] = '\0';
		}

		void append(const char *str){//添加字符串，append
			size_t len = strlen(str);
			if (_size + len > _capacity) {
				char* temp = new char[len + _size + 1];
				strcpy(temp, _str);
				delete [] _str;
				_str = temp;
				_capacity = len + _size;
			}
			strcpy(_str + _size-1,str);
			_size = len+_size;

		}
		string& operator+=(const char* s) {//运算符重载  +
			this->append(s);
			return *this;
		}
		string& insert(size_t pos, char ch) {//在下标为pos处，插入一个字母ch
			if (_size== _capacity) {
				size_t newcapacity = _capacity == 0 ? 2 : 2 * _capacity;
				char* temp = new char[newcapacity + 1];
				strcpy(temp, _str);
				delete[] _str;
				_str = temp;
				_capacity = newcapacity;
			}
			for (int i = _size; i >= pos; i--) {
				_str[i+1] = _str[i];
			}
			_str[pos] = ch;
			return *this;

		}
		string& insert(size_t pos, const char* ch) {//在下标为pos处插入一个字符串ch
			int len = strlen(ch);
			if (len + _size > _capacity) {
				char* temp = new char[len + _size + 1];
				strcpy(temp, _str);
				delete[] _str;
				_str = temp;
				_capacity = len + _size;
			}
			for (int i = pos; i <= _size; i++) {
				_str[i + len] = _str[i];
			}
			for (int i = 0; i < len; i++) {
				_str[i + pos] = ch[i];
			}
			return *this;

		}
		string& resize(size_t n, char ch = '\0')//重新定义长度，这里为缺省，如果传值，则用传值的数，如果没有传值，那么就用'\0'
		{
			if (n < _size) {
				_str[n] = '\0';
				_size = n;
			}
			else {
				if (n > _capacity) {
					size_t newcapacity = _capacity == 0 ? 2 :n+1;
					char* temp = new char[newcapacity + 1];
					strcpy(temp, _str);
					delete[] _str;
					_str = temp;
					_capacity = newcapacity;
				}
				for (int i = _size; i < n; i++) {
					_str[i] = ch;
				}
				_size = n;
				_str[_size] = '\0';
			}
			return *this;

		}
		string& erase(size_t pos, size_t len = -1) {
			if (len >= _size - pos) {
				_str[pos] = '\0';
				_size = pos;
			}
			else {
				for (int i = 0; i <= _size - pos-len; i++) {
					_str[i+pos] = _str[i +pos+len];
				}
				_size -= len;
				_str[pos + len + 1] = '\0';
			}
			return *this;
		}
		size_t find(const char ch,size_t pos=0) {//找元素为ch的字符，返回对应下标
			for (size_t i = pos; i < _size; i++) {
				if (_str[i] == ch) {
					return i;
				}
			}
			return -1;
		}
		size_t find(const char *str, size_t pos = 0)//找相应的字符串，返回对应的开始的下标
		{
			char* p= strstr(_str, str);
			if (p == nullptr) return -1;
			else return p - _str;
		}
		bool operator<(string& s) {//运算符重载，判断大小
			int ret = strcmp(_str, s._str);//利用c库中的比较字符的函数
			return ret < 0;
		}
		bool operator==(string&s){
			int ret = strcmp(_str, s._str);
			return ret == 0;
}
		bool operator>(string& s) {
			int ret = strcmp(_str, s._str);
			return ret > 0;
		}
		bool operator<=(string& s) {
			return *this < s || *this == s;
		}
		bool operator>=(string& s) {
			return *this > s || *this == s;
		}
		bool operator!=(string& s) {
			return !(*this == s);
		}

		friend std::ostream& operator<<(std::ostream& cout, const string& s);//运算符重载  <<
		//此处为友元函数，因为运算符重载一般只能穿越一个参数，这里必须要用友元
		friend istream& operator>>(istream& in, string& s);

		int size() const{ return _size; }//返回当前长度
		int capcity() const{ return _capacity; }//返回当前容量
		typedef char* iterator;//迭代器


		iterator begin() {return _str;}//迭代器
		iterator end() { return _str + _size; }//迭代器
	};


	std::ostream& operator<<(std::ostream& cout, const string& s) {
		for (int i = 0; i < s.size(); i++) {
			cout << s[i];
		}
		return cout;
	}

	istream& operator>>(istream& in, string& s) {
		while (1) {
			char ch;
			ch=in.get();
			if (ch == ' ' || ch == '\0'||ch=='\n') {
				break;
			}
			else {
				s.push_back(ch);
			}
		}
		return in;
	}


	void test_string1() {
		//string s1;
		//string s2("hahahehe");
		//string s3(s2);
		//string s4;
		//s4 = s2;
		//s2.push_back('A');
		//s2.push_back('A');
		//s2.push_back('A');
		//s2.push_back('A');
		//s2.push_back('A');
		//s2.push_back('A');
		//s2.push_back('B');
		//s2.append("haha");//hahaheheAAAAAABhahafa
		//s2+="fa";
		//s2.insert(8, 'z');
		//s2.erase(9, 6);
		//cout << "下标为:" << s2.find('z')<<endl;
		//cout << s2.find("zha")<<endl;
		//cout <<s2<< endl;//hahaheheAAAAAABhahahahahafafaasf
		string s1 = "1111";
		string s2 = "1111";
		//cout << s3;
	}
}


