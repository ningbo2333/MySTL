#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
using namespace std;
#include"map_set.h"
//#include"RBTree.h"
#include"AVL.h"


void test_AVL() {
	AVLTree<int, int> avt;
	vector<int>nums{5,1,2,10,-5,-10,-6,12,66,99,-51,11,54,-35,0};
	for (auto& e : nums) {
		avt.insert(make_pair(e, e));
	}
	avt.midorder();
	cout << endl;
	if (avt.is_Balance()) {
		cout << "是平衡搜索二叉树";
	}
	else {
		cout << "不是平衡搜索二叉树，代码有错误的地方";
	}
}





//void test_BRTree() {
//	RBTree<int, int> br;
//	vector<int>nums{5, 1, 2, 10, -5, -100,-101, -6, 12, 66, 54, -35, 0};
//	for (auto& e : nums) {
//		br.insert(make_pair(e, e));
//	}
//	br.midorder();
//	cout << endl;
//}


int main() {
	//test_AVL();
	//test_BRTree();
	//kzx::test_map();
	kzx::test_my_set();
	kzx::test_my_map();
	return 0;
}
