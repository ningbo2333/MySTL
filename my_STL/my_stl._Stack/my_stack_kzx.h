#pragma once
#include<vector>
#include<list>
namespace kzx_stack {
	template<class T,class Container>
	class stack {
	private:
		Container _con;
	public:
		void push(const T& x) {
			_con.push_back(x);
		}
		void pop() {
			_con.pop_back();
		}
		T& top() {
			return _con.back();
		}
		bool empty() {
			return _con.empty();
		}
		size_t size() {
			return _con.size();
		}
	};


	void  test_stack_1() {
		stack<int, list<int>> st;
		st.push(1);
		st.push(2);
		st.push(3);
		st.push(4);
		st.push(5);
		st.push(6);
		st.push(7);
		while (!st.empty()) {
			cout << st.top()<<" ";
			st.pop();
		}
	}
}



