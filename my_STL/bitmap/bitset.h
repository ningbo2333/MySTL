#pragma once

//λͼ
class my_bitset {
private:
	vector<int> _bits;
	size_t nums;
public:
	my_bitset(size_t N) {
		_bits.resize(N / 32 + 1);
		nums = 0;
	}


	//�ѵ�n��λ�ó�1
	void set(size_t n) {
		size_t index = n / 32;
		size_t i = n % 32;
		_bits[index] |= (1 << i);

	}

	//�ѵ�xλ��Ϊ0
	void reset(size_t x) {
		size_t index = x / 32;
		size_t i = x % 32;
		_bits[index] &= (~(1 << i));
	}

	//�ж�Xӳ���λ���ڲ��ڣ��Ƿ�Ϊ1
	bool test(size_t x) {
		size_t index = x / 32;
		size_t i = x % 32;
		return _bits[index] & (1 << i);
	}
};


struct hash_str1 {
	// BKDR ��ϣ�ַ����㷨
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
	// RS  hash�ַ����㷨
	size_t operator ()(const string& str) {
		size_t hash = 0;
		size_t magic = 63689;//ħ��
		for (size_t i = 0; i < str.size(); i++) {
			hash *= magic;
			hash += str[i];
			hash *= 378551;
		}
		return hash;
	}
}; 


struct hash_str3 {
	// SDBM hash �㷨
	size_t operator ()(const string& str) {
		size_t hash = 0;
		for (size_t i = 0; i < str.size(); i++) {
			hash *= 65599;
			hash += str[i];
		}
		return hash;
	}
};


//��¡������
template <class K=string,class Hash1= hash_str1,class Hash2= hash_str2,class Hash3= hash_str3>	//һ�ּ����ַ���ӳ��λ�õĹ�ϣ�㷨�����������������Ƿº���
class bloomfilter {
private:
	my_bitset _bs;
	size_t _N;
public:
	bloomfilter(size_t num):_bs(5*num),_N(5*num){}

	void set(const K& key) {
		//�����Hash()��һ���º�����������������Ҫ��()
		size_t index1 = Hash1()(key) % _N;//�����һ����ϣ�㷨���±�
		size_t index2 = Hash2()(key) % _N;//�����һ����ϣ�㷨���±�
		size_t index3 = Hash3()(key) % _N;//�����һ����ϣ�㷨���±�
		
		//��������Ӧ��ӳ��λ�ö���Ϊ1
		_bs.set(index1);
		_bs.set(index2);
		_bs.set(index3);
	}
	
	//�ж�һ�������ڲ�����
	bool test(const K& key) {
		size_t index1 = Hash1()(key) % _N;//�����һ����ϣ�㷨���±�
		size_t index2 = Hash2()(key) % _N;//�����һ����ϣ�㷨���±�
		size_t index3 = Hash3()(key) % _N;//�����һ����ϣ�㷨���±�
		if (_bs.test(index1) == false) return false;
		if (_bs.test(index2) == false) return false;
		if (_bs.test(index3) == false) return false;
		return true;
	}

};





