#pragma once
#include<vector>
#include<list>
namespace kzx_queue {
	template<class T, class Container>
	class queue {
	private:
		Container _con;
	public:
		void push(const T& x) {
			_con.push_back(x);
		}
		void pop() {
			_con.pop_front();
		}
		T& front() {
			return _con.front();
		}
		T& back() {
			return _con.back();
		}
		bool empty() {
			return _con.empty();
		}
		size_t size() {
			return _con.size();
		}
	};


	void  test_queue_1() {
		queue<int, list<int>> st;//queue不能用vector,因为vector没有提供头删pop_front的接口，而且，头删的时间复杂度为O(n)
		st.push(1);
		st.push(2);
		st.push(3);
		st.push(4);
		st.push(5);
		st.push(6);
		st.push(7);
		while (!st.empty()) {
			cout << st.front() << " ";
			st.pop();
		}
	}
}
