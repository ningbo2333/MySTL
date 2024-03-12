#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<vector>

using namespace std;
#include"bitset.h"

void test_bitset() {//≤‚ ‘ŒªÕº
	my_bitset bst(1200000);
	bst.set(66);
	bst.set(12);
	bst.set(15);
	bst.set(45);
	bst.set(12);
	bst.set(12);
	bst.set(1200000);
	//bst.set(12);
	//bst.set(12);
	//bst.set(12);
	//bst.set(12);
	//bst.set(12);
	for (int i = 0; i <= 1200000; ++i) {
		if (bst.test(i) == 0) continue;
		cout << "µ⁄"<<i<<"Œª:" << bst.test(i)<<endl;
	}


}


void test_bloomfilter() {//≤‚ ‘≤º¬°π˝¬À∆˜
	bloomfilter<>bl(500);
	bl.set("aaaaaddaae");
	bl.set("aaabacaaae");
	bl.set("aaaaadcaee");
	bl.set("aasasdaaae");
	bl.set("aaassaacae");
	cout << bl.test("aaaaaddaae")<<endl;
	cout << bl.test("aaabacaaae")<<endl;
	cout << bl.test("aaaaadcaee")<<endl;
	cout << bl.test("aasasdaaae")<<endl;
	cout << bl.test("aaassaacae")<<endl;

}

int main() {
	test_bitset();
	//test_bloomfilter();
	return 0;
}