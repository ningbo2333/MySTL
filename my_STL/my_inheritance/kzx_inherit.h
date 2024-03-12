#pragma once

class person {
private:
	int _age;
	bool _sex;
protected:
	string _name;
public:
	person(int age = 18, bool sex = 1, string name = "null") :_age(age), _sex(sex), _name(name) {//默认构造函数
		cout << "person()"<<endl;
	}
	person(const person& s) :_age(s._age), _sex(s._sex), _name(s._name) {//拷贝构造函数
		cout << "person(const person&s)"<<endl;
	}
	person& operator=(const person& s) {
		cout << "person& operator=(const person&s)" << endl;
		_age = s._age, _sex = s._sex, _name = s._name;
		return *this;
	}
	~person()//析构函数
	{
		cout << "~person()" << endl;
	}

};

class Student :public person {
private:
	int _stu_id;
public:
	Student(int age=20,bool sex=0,string name="xiaohong", int id = 1) :person(age, sex, name), _stu_id(id) {
		cout << "Student()"<<endl;//默认构造函数
	}
	Student(const Student& s):person(s) {//派生类的拷贝构造函数，这里可以用基类引用指向派生类
		_stu_id = s._stu_id;
	}
	Student& operator=(const Student& s) {
		person::operator=(s);
		_stu_id = s._stu_id;
		return *this;
	}
	~Student()
	{
		cout << "~Student()" << endl;
	}
};




class person_price {
public:
	virtual void buy() {
			cout << "普通票" << endl;
	}
};


class stu :public person_price {
public:
	void buy() {
		cout << "学生票" << endl;
	}
};


class solder :public person_price {
public:
	void buy() {
		cout << "军人优先票" << endl;
	}
};


