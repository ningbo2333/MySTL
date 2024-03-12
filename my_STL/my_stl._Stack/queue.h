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
		queue<int, list<int>> st;//queue������vector,��Ϊvectorû���ṩͷɾpop_front�Ľӿڣ����ң�ͷɾ��ʱ�临�Ӷ�ΪO(n)
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
