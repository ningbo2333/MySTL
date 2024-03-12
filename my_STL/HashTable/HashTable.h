#pragma once

//***********�����Ǳ�ɢ��
	//enum State {//����״̬
	//	EMPTY,
	//	EXITS,//���ڡ�ɾ������
	//	DELETE,
	//};

	//template <class T>
	//struct HashData {//��ϣ���Ԫ��
	//	T _data;
	//	State _state;//״̬
	//};

	//template<class K>
	//struct SetOfT {
	//	const K& operator()(const K& key) {
	//		return key;
	//	}
	//};
	//template <class K, class T>
	//struct MapOfT {		//�º���
	//	const K& operator()(const T& kv) {
	//		return kv.first;
	//	}
	//};

	//template <class K, class T, class KeyOfT>
	//class HashTable {//��ɢ�У�����̽��
	//private:
	//	vector<HashData<T>>_tables;//�����ϣ��
	//	size_t _num;//���������ж��ٸ�Ԫ��
	//public:

	//	KeyOfT koft;
	//	bool insert(const T& d) {
	//		if (_tables.size()==0 || _num * 10 / _tables.size() >= 7) {//���һ��ʼΪ�գ��������㸺�����Ӵﵽĳ������
	//			size_t newsize = _tables.size() == 0 ? 10 : 2 * _tables.size();
	//			vector<HashData<T>>newtables;
	//			newtables.resize(newsize);
	//			for (size_t i = 0; i < _tables.size(); i++) {//����ӳ�䣬��Ϊsize���ˣ�ӳ���ϵҲ���ܱ���
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
	//			_tables.swap(newtables);//�ִ�д��
	//			����
	//		}
	//		if (_tables.size() == 0 || _num * 10 / _tables.size() >= 7) {//���һ��ʼΪ�գ��������㸺�����Ӵﵽĳ������
	//			HashTable<K, T, KeyOfT> newhash;
	//			size_t newsize = _tables.size() == 0 ? 10 : 2 * _tables.size();
	//			newhash._tables.resize(newsize);
	//			for (size_t i = 0; i < _tables.size(); i++) {
	//				if (_tables[i]._state == EXITS) {
	//					newhash.insert(_tables[i]._data);//����insert���ɵĲ����µģ�ӳ���ϵҲ��֮������
	//				}
	//			}
	//			_tables.swap(newhash._tables);//�ִ�д��

	//		}
	//		KeyOfT koft;
	//		size_t index = koft(d) % _tables.size();//����ӳ��λ�ã������±�
	//		while (_tables[index]._state == EXITS) {
	//			if (koft(_tables[index]._data) == koft(d)) {
	//				return false;//�����������У��������ֵ���Ѿ���ֱ�ӷ���
	//			}
	//			if (_tables[index]._state == EMPTY) {
	//				break;//�ҵ�һ����λ�ã�����ѭ��
	//			}
	//			index++;
	//			if (index == _tables.size()) {//����ӵ���������ĳ��ȣ������߶�û�п�λ����
	//				index = 0;
	//			}
	//		}
	//		_tables[index]._data = d;
	//		_tables[index]._state = EXITS;//����״̬
	//		_num++;						//��ϣ���Ԫ�ظ�����һ
	//		return true;
	//	}
	//	HashData<T>* find(const K& key) {
	//		KeyOfT koft;
	//		size_t index = key % _tables.size();
	//		while (_tables[index]._state != EMPTY) {
	//			if (koft(_tables[index]._data) == key) {
	//				����Ҫע���ҵ���ֵ��״̬������Ǵ��ڣ���ô��ֱ�ӷ��أ������ɾ�����������ֵ�Ѿ���ɾ���ˣ����ؿ�ָ��
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
	//***************�����Ǳ�ɢ��


// //********************�����ǿ�ɢ��(��ϣͰ)





template<class K>
struct hashfun {
	//�º�����������Ĭ�Ͽ��Գ������ε��±�����µķº���
	const K& operator()(const K& key) {
		return key;
	}
};

////*******д��1,����һ���µĶ�Ӧ���͵ĵķº���

//template<class K>		
//struct hashstring {
//	//����string���ͣ�������Ҫ��stringת��Ϊ���Σ������ҳ���ӦҪ������±�
//	const size_t& operator()(const K& str) {
//		size_t sum = 0;
//		for (size_t i = 0; i < str.size(); i++) {
//			sum += str[i];
//		}
//		return sum;
//	}
//};

//*****д��2 :  �ػ�
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

template<class K, class T, class KOFT, class _hash = hashfun<K>>//ǰ�����������ﴫ��Ĭ�ϲ����󣬺�߾Ͳ�Ҫ�ٴ���
class HashTbale;//����һ�������������±ߵ�HashIterator�����ҵ�����

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
//ȱʡĬ��Ϊ�������ε��±꣬�����������Ҫ�Լ��ٴ�
//class _hash=hashfun<K>,_hash�ķº��������� :  ȡ��key-value ����keyģ�͵�key��
//Ȼ��������key�ǳ�����Ա�Ϊ���εģ���ô����Ĭ�ϵ�ȱʡ�º�����ֱ�ӷ������Σ����������������Ҫ������±��λ�ã�
//������ǿ��Գ���ģ�����ṹ�������������Ҫ�ֶ�ȥ���Σ����������������������±�λ��
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

	~HashTbale()//��������
	{
		Clear();
	}

	size_t hashfunc(const K& key) {//���±�תΪ���Σ����������Ĭ�ϵľ�������
		_hash hash;
		size_t index = hash(key);
		return index;
	}

	pair<Iterator,bool> insert(const T& d) {		//��ɢ�й�ϣ��Ĳ���
		KOFT koft;
		if (_num == _tables.size()) {//������������
			size_t newsize = _tables.size() == 0 ? 10 : _tables.size() * 2;
			vector<Node*>newtables;
			newtables.resize(newsize);
			for (size_t i = 0; i < _tables.size(); i++) {
				Node* cur = _tables[i];
				while (cur) {
					Node* next = cur->_next;
					size_t index = hashfunc(koft(cur->_data)) % newsize;//index�Ǽ��������ٱ��ж�Ӧ��ӳ��λ��
					cur->_next = newtables[index];
					newtables[index] = cur;
					cur = next;
				}
				_tables[i] = nullptr;//���ھɱ�����ݣ�û�����ˣ��Ѿ��Ƶ��±����ˣ��ÿգ�����Ϊ��ߵ��ִ�д��
			}
			_tables.swap(newtables);//����һ�£��±������ڵ��ˣ��ɱ�������������ͷţ����ù�
		}

		size_t index = hashfunc(koft(d))%_tables.size();//û�����ݣ��������ݺ������µ���������
		Node* cur = _tables[index];
		while (cur) {
			if (koft(cur->_data) == koft(d)) {
				return make_pair(Iterator(cur,this),false);//�Ѿ��е�
			}
			cur = cur->_next;
		}
		Node* newnode = new Node(d);
		newnode->_next = _tables[index];
		//ͷ��
		_tables[index]=newnode;
		_num++;
		return make_pair(Iterator(newnode,this),true);
	}


	Node* find(const T& d) {
		KOFT koft;
		size_t index = hashfunc(koft(d)) % _tables.size();//�����±꣬���������ٱ��ж�Ӧ��ӳ��λ��
		Node* cur = _tables[index];//�ҵ���Ӧλ�õĵ�һ���ڵ�
		while (cur) {
			if (koft(cur->_data) == koft(d)) {//��������ң��ҵ����ؽڵ��ָ��
				return cur;
			}
			else {
				cur = cur->_next;
			}
		}
		return nullptr;//�ߵ���������ҵ�ͷ�ˣ�����nullptr
	}
	bool erase(const T& d) {
		KOFT koft;
		size_t index = hashfunc(koft(d)) % _tables.size();//�����±�
		Node* last = nullptr;//������һ��λ��
		Node* cur = _tables[index];//�ҵ���Ӧλ�õĵ�һ���ڵ�
		while (cur) {
			if (koft(cur->_data) == koft(d)) {//��������ң��ҵ����ؽڵ��ָ��
				if (!last) {//���lastΪnullptr����ô����Ҫɾ�ľ��ǵ�һ���ڵ�
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

	void Clear() {//����ÿһ���ڵ�
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
//�����ǿ�ɢ��




