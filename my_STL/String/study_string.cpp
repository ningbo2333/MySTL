#define _CRT_SECURE_NO_WARNINGS 1
using namespace std;
#include"my_string.h"

int string2int(const string& nums) {//���ַ���ת��Ϊ����
	int sum = 0;
	for (int i = 0; i < nums.size(); i++) {
		sum = (sum * 10) + (nums[i]-'0');
	}
	return sum;
}




int firstUniqChar(string s) {
	int index = -1;
	vector<int>v(128, 0);
	for (int i = 0; i < s.size(); i++) {
		if (v[s[i]] != 0) {
			v[s[i]]++;
		}
		if (v[s[i]] == 0) {
			v[s[i]] = 1;
		}

	}
	for (int i = 0; i < s.size(); i++) {
		if (v[s[i]] == 1) {
			index = i;
			break;
		}
	}
	return index;
}
int main() {
	//cout << firstUniqChar("Leetcode");//j-Ih-gfE-dCba//������

	//string n = "1235480";
	//string i="1";
	//cout << i.capacity();//���������
	//string::iterator sit = n.begin();//�������������ȵ������ص��ǿ�ʼ�ط���ָ��
	//sort(n.begin(), n.end());
	//while (sit != n.end()) {//end()��ͬ�ڽ����ط���ָ��
	//	cout << *sit << " ";
	//	sit++;
	//}
	//cout << endl;
	//string::reverse_iterator rsit = n.rbegin();//�������ĵ�����
	//while (rsit != n.rend()) {
	//	cout << *rsit<<" ";
	//	rsit++;
	//}
	//cout << endl;
	//for (auto i:n ) {//��Χforѭ��
	//	cout << i << " ";
	//}
	//cout << string2int(n);
	//string s1="string.cpp.zip";
	//string s2="string.c";
	//string s3="string.txt";
	//size_t pos1 = s1.rfind('.');
	//size_t pos2 = s2.rfind('.');
	//size_t pos3 = s3.rfind('.');
	//if (pos1 != string::npos) {
	//	cout << s1.substr(pos1)<<endl;
	//}
	//if (pos2 != string::npos) {
	//	cout << s2.substr(pos2) << endl;
	//}	
	//if (pos3 != string::npos) {
	//	cout << s3.substr(pos3) << endl;
	//}
	kzx::test_string1();
	return 0;
}


