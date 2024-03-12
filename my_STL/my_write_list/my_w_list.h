#pragma once
#include<assert.h>
namespace kzx {
	//定义节点的数据结构
	template<class T>
	struct __list_node {
		__list_node* _next;
		__list_node* _prev;
		T _data;
	};

	//定义迭代器
	template<class T,class Ref,class Ptr>
	struct __list_iterator {
		typedef __list_node<T> Node;
		typedef __list_iterator<T, Ref, Ptr> self;
		Node* node;
		__list_iterator(Node* temp):node(temp) {}
		Ref& operator*() {
			return node->_data; }
		self& operator++() {
			node = node->_next;
			return *this;
		}
		self& operator--() {
			node = node->_prev;
			return *this;
		}
		self& operator++(int) {
			self temp = *this;
			++(*this);
			return temp;
		}
		self& operator+(int x) {
			while (x > 0) {
				++(*this);
				x--;
			}
			return *this;
		}

		bool operator!=(const self &temp) {
			return node != temp.node;
		}

	};



	//定义链表，包含一个头节点
	template<class T>
	class list {
	public:
		typedef __list_node<T> Node;
		typedef __list_iterator<T, T&, T*> iterator;
		typedef __list_iterator<T,const T&,const T*> const_iterator;

	private:
		Node* head;
	public:
		list() {//构造函数
			head = new Node;
			head->_next = head;
			head->_prev = head;
			head->_data = T();
		}
		~list()//构析函数
		{
			Node* cur = head->_next;
			while (cur!= head) {
				Node* temp = cur;
				cur = cur->_next;
				delete temp;

			}
			delete head;

		}
		list(const list<T>& lt) {
			const_iterator it = lt.begin();
			head = new Node;
			head->_next = head;
			head->_prev = head;
			while (it != lt.end()) {
				this->push_back(*it);
				it++;
			}
		}
		void push_back(const T& x) {

			Node* tail = head->_prev;
			Node* newnode = new Node;
			newnode->_data = x;
			tail->_next = newnode;
			newnode->_prev = tail;
			newnode->_next = head;
			head->_prev = newnode;
		}
		void pop_back(){//尾删
			erase(--end());
		}
		void pop_front() {//头删
			erase(begin());
		}
		void insert(iterator pos, const T& x) {
			Node* temp = pos.node;
			Node* prev = temp->_prev;
			Node* newnode = new Node;
			newnode->_data = x;
			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = temp;
			temp->_prev = newnode;
		}

		iterator erase(iterator pos) {
			assert(pos != end());//不能删除头节点
			Node* cur = pos.node;
			Node* prev = pos.node->_prev;
			Node* next = pos.node->_next;
			prev->_next = next;
			next->_prev = prev;
			delete cur;
			return pos++;
		}


		list<T>& operator=(const list<T>& lt) {
			list<T>* temp = new list<T>(lt);
			swap(head, temp->head);
			return *this;
		}


		iterator begin() {
			return iterator(head->_next);
		}
		const_iterator begin() const{
			return const_iterator(head->_next);
		}
		iterator end() {
			return iterator(head);
		}
		const_iterator end() const{
			return const_iterator(head);
		}
	};


	void test_list_1() {
		list<int> l;
		l.push_back(1);
		l.push_back(2);
		l.push_back(3);
		l.push_back(4);
		l.push_back(5);
		l.push_back(6);
		l.insert(l.begin(), 0);
		l.erase(l.begin());
		l.pop_back();
		for (auto e : l) {
			std::cout << e << " ";}
		cout << endl;
		list<int>::iterator it = l.begin();
		while (it != l.end()) {
			cout << *it << " ";
			++it;
		}
		cout << endl;

		list<int>l2(l);
		for (auto e : l2) {
			cout << e<<" ";
		}
		cout << endl;

		list<int>l3;
		l3 = l;
		for (auto e : l3) {
			cout << e *10<< " ";
		}
		cout << endl;
	}

}








