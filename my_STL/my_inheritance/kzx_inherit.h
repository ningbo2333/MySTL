#pragma once

class person {
private:
	int _age;
	bool _sex;
protected:
	string _name;
public:
	person(int age = 18, bool sex = 1, string name = "null") :_age(age), _sex(sex), _name(name) {//Ĭ�Ϲ��캯��
		cout << "person()"<<endl;
	}
	person(const person& s) :_age(s._age), _sex(s._sex), _name(s._name) {//�������캯��
		cout << "person(const person&s)"<<endl;
	}
	person& operator=(const person& s) {
		cout << "person& operator=(const person&s)" << endl;
		_age = s._age, _sex = s._sex, _name = s._name;
		return *this;
	}
	~person()//��������
	{
		cout << "~person()" << endl;
	}

};

class Student :public person {
private:
	int _stu_id;
public:
	Student(int age=20,bool sex=0,string name="xiaohong", int id = 1) :person(age, sex, name), _stu_id(id) {
		cout << "Student()"<<endl;//Ĭ�Ϲ��캯��
	}
	Student(const Student& s):person(s) {//������Ŀ������캯������������û�������ָ��������
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
			cout << "��ͨƱ" << endl;
	}
};


class stu :public person_price {
public:
	void buy() {
		cout << "ѧ��Ʊ" << endl;
	}
};


class solder :public person_price {
public:
	void buy() {
		cout << "��������Ʊ" << endl;
	}
};


