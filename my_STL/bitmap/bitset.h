#pragma once

//位图
class my_bitset {
private:
	vector<int> _bits;
	size_t nums;
public:
	my_bitset(size_t N) {
		_bits.resize(N / 32 + 1);
		nums = 0;
	}


	//把第n个位置成1
	void set(size_t n) {
		size_t index = n / 32;
		size_t i = n % 32;
		_bits[index] |= (1 << i);

	}

	//把第x位置为0
	void reset(size_t x) {
		size_t index = x / 32;
		size_t i = x % 32;
		_bits[index] &= (~(1 << i));
	}

	//判断X映射的位置在不在，是否为1
	bool test(size_t x) {
		size_t index = x / 32;
		size_t i = x % 32;
		return _bits[index] & (1 << i);
	}
};


struct hash_str1 {
	// BKDR 哈希字符串算法
	size_t operator ()(const string& str) {
		size_t hash = 0;
		for (size_t i = 0; i < str.size(); i++) {
			hash *= 131;
			hash += str[i];
		}
		return hash;
	}
};


struct hash_str2 {
	// RS  hash字符串算法
	size_t operator ()(const string& str) {
		size_t hash = 0;
		size_t magic = 63689;//魔数
		for (size_t i = 0; i < str.size(); i++) {
			hash *= magic;
			hash += str[i];
			hash *= 378551;
		}
		return hash;
	}
}; 


struct hash_str3 {
	// SDBM hash 算法
	size_t operator ()(const string& str) {
		size_t hash = 0;
		for (size_t i = 0; i < str.size(); i++) {
			hash *= 65599;
			hash += str[i];
		}
		return hash;
	}
};


//布隆过滤器
template <class K=string,class Hash1= hash_str1,class Hash2= hash_str2,class Hash3= hash_str3>	//一种计算字符串映射位置的哈希算法，可以有三个，都是仿函数
class bloomfilter {
private:
	my_bitset _bs;
	size_t _N;
public:
	bloomfilter(size_t num):_bs(5*num),_N(5*num){}

	void set(const K& key) {
		//这里的Hash()是一个仿函数的匿名对象，所以要加()
		size_t index1 = Hash1()(key) % _N;//计算第一个哈希算法的下标
		size_t index2 = Hash2()(key) % _N;//计算第一个哈希算法的下标
		size_t index3 = Hash3()(key) % _N;//计算第一个哈希算法的下标
		
		//将三个对应的映射位置都置为1
		_bs.set(index1);
		_bs.set(index2);
		_bs.set(index3);
	}
	
	//判断一个数存在不存在
	bool test(const K& key) {
		size_t index1 = Hash1()(key) % _N;//计算第一个哈希算法的下标
		size_t index2 = Hash2()(key) % _N;//计算第一个哈希算法的下标
		size_t index3 = Hash3()(key) % _N;//计算第一个哈希算法的下标
		if (_bs.test(index1) == false) return false;
		if (_bs.test(index2) == false) return false;
		if (_bs.test(index3) == false) return false;
		return true;
	}

};





