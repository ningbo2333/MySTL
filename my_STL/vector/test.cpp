#define _CRT_SECURE_NO_WARNINGS 1
#include"vector.h"

void test_push_pack() {
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.pop_back();
	for (int i = 0; i < v1.size(); i++) {
		cout << v1[i] << " ";
	}
	cout << endl;
}

int main() {
	test_push_pack();

	return 0;
}




