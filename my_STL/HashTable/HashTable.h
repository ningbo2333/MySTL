#pragma once

//***********以下是闭散列
	//enum State {//定义状态
	//	EMPTY,
	//	EXITS,//存在。删除。空
	//	DELETE,
	//};

	//template <class T>
	//struct HashData {//哈希表的元素
	//	T _data;
	//	State _state;//状态
	//};

	//template<class K>
	//struct SetOfT {
	//	const K& operator()(const K& key) {
	//		return key;
	//	}
	//};
	//template <class K, class T>
	//struct MapOfT {		//仿函数
	//	const K& operator()(const T& kv) {
	//		return kv.first;
	//	}
	//};

	//template <class K, class T, class KeyOfT>
	//class HashTable {//闭散列，线性探测
	//private:
	//	vector<HashData<T>>_tables;//定义哈希表
	//	size_t _num;//定义现在有多少个元素
	//public:

	//	KeyOfT koft;
	//	bool insert(const T& d) {
	//		if (_tables.size()==0 || _num * 10 / _tables.size() >= 7) {//如果一开始为空，或者满足负载因子达到某个条件
	//			size_t newsize = _tables.size() == 0 ? 10 : 2 * _tables.size();
	//			vector<HashData<T>>newtables;
	//			newtables.resize(newsize);
	//			for (size_t i = 0; i < _tables.size(); i++) {//重新映射，因为size变了，映射关系也可能变了
	//				if (_tables[i]._state == EXITS) {
	//					size_t index = koft(_tables[i]._data) % newsize;
	//					while (newtables[index]._state == EXITS) {
	//						index++;
	//						if (index == newsize) {
	//							index = 0;
	//						}
	//					}
	//					newtables[index]._data = _tables[i]._data;

	//				}
	//			}
	//			_tables.swap(newtables);//现代写法
	//			增容
	//		}
	//		if (_tables.size() == 0 || _num * 10 / _tables.size() >= 7) {//如果一开始为空，或者满足负载因子达到某个条件
	//			HashTable<K, T, KeyOfT> newhash;
	//			size_t newsize = _tables.size() == 0 ? 10 : 2 * _tables.size();
	//			newhash._tables.resize(newsize);
	//			for (size_t i = 0; i < _tables.size(); i++) {
	//				if (_tables[i]._state == EXITS) {
	//					newhash.insert(_tables[i]._data);//调用insert，旧的插入新的，映射关系也随之更新了
	//				}
	//			}
	//			_tables.swap(newhash._tables);//现代写法

	//		}
	//		KeyOfT koft;
	//		size_t index = koft(d) % _tables.size();//计算映射位置，就是下标
	//		while (_tables[index]._state == EXITS) {
	//			if (koft(_tables[index]._data) == koft(d)) {
	//				return false;//如果插入过程中，存在这个值了已经，直接返回
	//			}
	//			if (_tables[index]._state == EMPTY) {
	//				break;//找到一个空位置，打破循环
	//			}
	//			index++;
	//			if (index == _tables.size()) {//如果加到等于数组的长度，代表后边都没有空位置了
	//				index = 0;
	//			}
	//		}
	//		_tables[index]._data = d;
	//		_tables[index]._state = EXITS;//更新状态
	//		_num++;						//哈希表的元素个数加一
	//		return true;
	//	}
	//	HashData<T>* find(const K& key) {
	//		KeyOfT koft;
	//		size_t index = key % _tables.size();
	//		while (_tables[index]._state != EMPTY) {
	//			if (koft(_tables[index]._data) == key) {
	//				这里要注意找到的值的状态，如果是存在，那么就直接返回，如果是删除，代表这个值已经被删除了，返回空指针
	//				if (_tables[index]._state == EXITS) {
	//					return &_tables[index];
	//				}
	//				else {
	//					return nullptr;
	//				}
	//			}
	//			index++;
	//			if (index == _tables.size()) {
	//				index = 0;
	//			}
	//		}
	//		return nullptr;
	//	}
	//	bool erase(const K& key) {
	//		HashData<T>* res = find(key);
	//		if (res) {
	//			res->_state = DELETE;
	//			_num--;
	//			return true;
	//		}
	//		else {
	//			return false;
	//		}
	//	}
	//};
	//***************以上是闭散列


// //********************以下是开散列(哈希桶)





template<class K>
struct hashfun {
	//仿函数，这里是默认可以出来整形的下标情况下的仿函数
	const K& operator()(const K& key) {
		return key;
	}
};

////*******写法1,定义一个新的对应类型的的仿函数

//template<class K>		
//struct hashstring {
//	//对于string类型，我们需要把string转换为整形，才能找出对应要加入的下标
//	const size_t& operator()(const K& str) {
//		size_t sum = 0;
//		for (size_t i = 0; i < str.size(); i++) {
//			sum += str[i];
//		}
//		return sum;
//	}
//};

//*****写法2 :  特化
template<>
struct hashfun<string> {
	const size_t& operator()(const string& str) {
		size_t sum = 0;
		for (size_t i = 0; i < str.size(); i++) {
			sum += str[i];
		}
		return sum;
	}
};



template<class T>
struct HashNode {
	T _data;
	HashNode* _next;
	HashNode(const T& data) :_data(data), _next(nullptr) {

	}
};

template<class K, class T, class KOFT, class _hash = hashfun<K>>//前置声明。这里传了默认参数后，后边就不要再传了
class HashTbale;//创建一个声明，这样下边的HashIterator就能找到他了

template<class K, class T, class KeyOfT,class Hash = hashfun<K>>
struct _HashIterator {
	typedef HashNode<T> Node;
	typedef _HashIterator<K,T,KeyOfT,Hash> Self;
	typedef HashTbale<K, T, KeyOfT, Hash> HT;
	Node* _node;
	HT* _ht;
	_HashIterator(Node* node,HT* ht):_node(node),_ht(ht){}
	T& operator*() {
		return _node->_data;
	}
	T* operator->() {
		return &(_node->_data);
	}
	
	Self& operator++() {
		Node* cur = _node;
		if (_node->_next) {
			_node = cur->_next;
			return *this;
		}
		else {
			KeyOfT koft;
			size_t index = _ht->hashfunc(koft(cur->_data)) % _ht->_tables.size();
			index++;
			for (; index < _ht->_tables.size(); index++) {
				if (_ht->_tables[index]) {
					_node = _ht->_tables[index];
					return *this;
				}
			}		
			_node = nullptr;
			return *this;
		}
	}

	bool operator!=(const Self& s) {
		return _node != s._node;
	}
};



template<class K,class T,class KOFT,class _hash>
//缺省默认为返回整形的下标，如果有特殊需要自己再传
//class _hash=hashfun<K>,_hash的仿函数的作用 :  取出key-value 或者key模型的key，
//然后如果这个key是常规可以变为整形的，那么就是默认的缺省仿函数，直接返回整形，进而可以求出我们要插入的下标的位置，
//如果不是可以常规的，比如结构体或者容器，需要手动去传参，进而可以正常求出插入的下标位置
class HashTbale {
	typedef HashNode<T> Node;
private:
	size_t _num;
	vector<Node*> _tables;


public:
	friend struct _HashIterator<K, T, KOFT, _hash>;
	typedef _HashIterator<K, T, KOFT,_hash> Iterator;
	
	Iterator begin() {
		for (size_t i = 0; i < _tables.size(); i++) {
			if (_tables[i]) {
				return Iterator(_tables[i],this);
			}
		}
		return end();
	}
	Iterator end() {
		return Iterator(nullptr,this);
	}

	~HashTbale()//析构函数
	{
		Clear();
	}

	size_t hashfunc(const K& key) {//将下标转为整形，这里如果是默认的就是整形
		_hash hash;
		size_t index = hash(key);
		return index;
	}

	pair<Iterator,bool> insert(const T& d) {		//开散列哈希表的插入
		KOFT koft;
		if (_num == _tables.size()) {//处理增容问题
			size_t newsize = _tables.size() == 0 ? 10 : _tables.size() * 2;
			vector<Node*>newtables;
			newtables.resize(newsize);
			for (size_t i = 0; i < _tables.size(); i++) {
				Node* cur = _tables[i];
				while (cur) {
					Node* next = cur->_next;
					size_t index = hashfunc(koft(cur->_data)) % newsize;//index是计算数据再表中对应的映射位置
					cur->_next = newtables[index];
					newtables[index] = cur;
					cur = next;
				}
				_tables[i] = nullptr;//对于旧表的数据，没有用了，已经移到新表上了，置空，方便为后边的现代写法
			}
			_tables.swap(newtables);//交换一下，新表变成现在的了，旧表会随析构函数释放，不用管
		}

		size_t index = hashfunc(koft(d))%_tables.size();//没有增容，或者增容后的情况下的正常插入
		Node* cur = _tables[index];
		while (cur) {
			if (koft(cur->_data) == koft(d)) {
				return make_pair(Iterator(cur,this),false);//已经有的
			}
			cur = cur->_next;
		}
		Node* newnode = new Node(d);
		newnode->_next = _tables[index];
		//头插
		_tables[index]=newnode;
		_num++;
		return make_pair(Iterator(newnode,this),true);
	}


	Node* find(const T& d) {
		KOFT koft;
		size_t index = hashfunc(koft(d)) % _tables.size();//查找下标，计算数据再表中对应的映射位置
		Node* cur = _tables[index];//找到对应位置的第一个节点
		while (cur) {
			if (koft(cur->_data) == koft(d)) {//依次向后找，找到返回节点的指针
				return cur;
			}
			else {
				cur = cur->_next;
			}
		}
		return nullptr;//走到这里代表找到头了，返回nullptr
	}
	bool erase(const T& d) {
		KOFT koft;
		size_t index = hashfunc(koft(d)) % _tables.size();//查找下标
		Node* last = nullptr;//保存上一个位置
		Node* cur = _tables[index];//找到对应位置的第一个节点
		while (cur) {
			if (koft(cur->_data) == koft(d)) {//依次向后找，找到返回节点的指针
				if (!last) {//如果last为nullptr，那么代表要删的就是第一个节点
					_tables[index] = cur->_next;
				}
				else {
					last->_next = cur->_next;
				}
				delete cur;
				cur = nullptr;
				_num--;
				return true;
			}
			else {
				last = cur;
				cur = cur->_next;
			}
		}
		return false;
	}

	void Clear() {//清理每一个节点
		for (size_t index = 0; index < _tables.size(); index++) {
			Node* cur = _tables[index];
			while (cur) {
				Node* next = cur->_next;
				delete cur;
				cur = next;
			}
			_tables[index] = nullptr;
		}
	}



};
//以上是开散列




