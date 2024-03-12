#define _CRT_SECURE_NO_WARNINGS 1
using namespace std;
#include"map_set.h"
#include<vector>
#include<map>
#include<algorithm>
#include<set>
#include<string>
#include <unordered_map>
void test_set() {
	set<int> s;
	s.insert(3);
	s.insert(1);
	s.insert(4);
	s.insert(8);
	s.insert(0);
	s.insert(2);
	s.insert(5);
	set<int>::iterator it = s.begin();
	while (it != s.end()) {
		cout << *it++ << " ";
	}

}

void test_map01() {
	map<string, int> m;
	//m.insert(pair<string, int>("Æ»¹û", 2));
	//m.insert(pair<string, int>("²¤ÂÜ", 5));
	//m.insert(pair<string, int>("Î÷¹Ï", 8));
	//m.insert(make_pair("Àæ", 3));
	//map<string, int>::iterator it = m.begin();
	//while (it != m.end()) {
	//	cout << it->first << ":" << it->second<<endl;
	//	it++;
	//}
	//cout << endl;
	//for (auto& e : m) {
	//	cout << e.first << ":" << e.second << endl;
	//}
	string str[] = { "Î÷¹Ï","Æ»¹û","Ïã½¶","Æ»¹û" ,"Æ»¹û" ,"Æ»¹û","Ïã½¶","Ïã½¶","Ó£ÌÒ" };
	for (auto& e : str) {
		//map<string, int>::iterator it = m.find(e);
		//if (m.find(e) == m.end()) {
		//	m.insert(make_pair(e, 1));
		//}
		//else {
		//	it->second++;
		//}
		m[e]++;
	}
	for (auto& e : m) {
		cout << e.first << ":" << e.second << endl;
	}
}

vector<string> topKFrequent(vector<string>& words, int k) {
	map<string, int> m;
	vector<string> v;
	for (auto& e : words) {
		m[e]++;
	}
	int max_val = 0;
	for (auto e : m) {
		if (e.second > max_val) {
			max_val = e.second;
		}
	}
	for (auto& e : m) {
		if (e.second == max_val) {
			v.push_back(e.first);
		}
	}
	return v;
}



int totalFruit(vector<int>& nums) {
	unordered_map<int, int> mp;
	if (nums.size() == 1) return 1;
	int left = 0, right = 0, res = 1;
	// while(right<nums.size()&&mp.size()<2){
	//     mp[nums[right]]++;
	//     res=max(res,right-left+1);
	//     right++;
	// }
	// while(right<nums.size()){
	//     if(!mp.count(nums[right])){
	//         int temp=left;
	//         while(mp[nums[temp]]!=0){
	//             nums[temp]--;
	//             left++;
	//         }
	//         mp.erase(nums[temp]);
	//     }
	//     mp[nums[right]]++;
	//     res=max(right-left+1,res);
	//     right++;
	// }
	for (left = 0; left < nums.size(); left++) {
		right = left;
		while (right < nums.size() && mp.size() <= 2) {
			mp[nums[right]]++;
			right++;
		}
		mp.clear();
		res = max(res, right - left);
	}
	return res;
}
vector<int> findAnagrams(string s, string p) {
	unordered_map<char, int> hash_p;
	unordered_map<char, int> hash_s;
	for (auto& e : "qazwsxedcrfvtgbyhnujmikolp") {
		hash_p[e];
		hash_s[e];
	}
	for (auto& e : p) {
		hash_p[e]++;
	}
	int left = 0, right = 0;
	vector<int> res;
	while (right < p.size()) {
		hash_s[s[right]]++;
		right++;
	}
	while (right <= s.size()) {
		if (hash_s == hash_p) {
			res.push_back(left);
		}
		hash_s[s[left]]--;
		hash_s[s[right]]++;
		left++;
		right++;
	}
	return res;

}



int countRepeatedNumbers(int n, int m) {
	int count = 0;

	for (int num = n; num <= m; ++num) {
		string numStr = to_string(num);
		int length = numStr.length();

		
		if (length % 2 == 0) {
			
			string firstHalf = numStr.substr(0, length / 2);
			string secondHalf = numStr.substr(length / 2, length / 2);

			if (firstHalf == secondHalf) {
				++count;
			}
		}
	}

	return count;
}

int main() {
	int n, m;
	cout << "Enter two positive integers n and m (n <= m): ";
	cin >> n >> m;

	if (n <= m) {
		int result = countRepeatedNumbers(n, m);
		cout << "The number of repeated twice numbers in [" << n << ", " << m << "] is: " << result << endl;
	}
	else {
		cout << "Invalid input: n should be less than or equal to m." << endl;
	}

	return 0;
}


//int main() {
	//test_set();
	//test_map01();
	//vector<string> str = { "the","day","is","sunny","the","the","the","sunny","is","is" };
	//vector<string>v=topKFrequent(str, 4);
	//lengthOfLongestSubstring("aabaab!bb");
	//vector<string>v{"eat", "tea", "tan", "ate", "nat", "bat"};
	//totalFruit(v);
	//groupAnagrams(v);
	//string s1, s2;
	//s1 = "cbaebabacd";
	//s2 = "abc";
	//findAnagrams(s1,s2);
//}


