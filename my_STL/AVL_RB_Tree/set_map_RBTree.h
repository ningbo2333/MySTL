#pragma once


enum Color { RED, BLACK };
template<class T>//���������Ľڵ�
struct RBTreenode {
	Color _col;//������ɫ
	T _data;
	RBTreenode<T>* _left;
	RBTreenode<T>* _right;
	RBTreenode<T>* _parent;
	RBTreenode(const T& data) :_left(nullptr), _right(nullptr), _parent(nullptr), _data(data), _col(RED) {}
	//RBTreenode(const pair<K, V>& kv) : _left(nullptr), _right(nullptr), _parent(nullptr), _kv(kv), _col(RED) {}

};


template<class T>//������
struct __TreeIterator {
	typedef RBTreenode<T> Node;
	typedef __TreeIterator<T> self;
	Node* _node;
	
	T& operator*() {
		return _node->_data;
	}
	
	T* operator->() {
		return &_node->_data;
	}
	
	self& operator++() {
		if (_node->_right) {//�ұ�Ϊ��
			Node* subLeft = _node->_right;
			while (subLeft->_right) {
				subLeft = subLeft->_left;
			}
			_node = subLeft;
		}
		else {//����ұ�Ϊ�գ��ڸ��׵���ߣ���ô��ֱ�ӷ������ĸ��ף���������ڸ��׵��ұߣ��Ǿ���Ҫ�����±ߵ�whileѭ������
			Node* cur= _node;
			Node* parent = cur->_parent;
			while (parent && parent->_right == cur) {
				cur = cur->_parent;
				parent = parent->_parent;
			}
			_node = parent;
		}
		return *this;
	}
	self& operator--() {
		return *this;
	}

	bool operator!=(const self& s) {
		return _node!= s._node;
	}
	__TreeIterator(Node* node) :_node(node) {}

};



template <class K, class T,class KOfT>
class RBTree {
private:
	typedef RBTreenode<T> Node;
	Node* _root = nullptr;
public:
	typedef __TreeIterator<T> iterator;
	bool insert(const T& data) {
		if (_root == nullptr) {
			_root = new Node(data);
			_root->_col = BLACK;//�����ڵ����ɫ��ɺ�ɫ��
			return true;
		}
		KOfT koft;
		Node* parent = _root;
		Node* cur = _root;
		while (cur) {
			parent = cur;
			if (koft(data) > koft(cur->_data)) {
				cur = cur->_right;
			}
			else if (koft(data) < koft(cur->_data)) {
				cur = cur->_left;
			}
			else { return false; }
		}
		cur = new Node(data);
		if (koft(cur->_data) > koft(parent->_data)) {
			parent->_right = cur;
			cur->_parent = parent;
		}
		else if (koft(cur->_data) < koft(parent->_data)) {
			parent->_left = cur;
			cur->_parent = parent;
		}
		cur->_col = RED;
		while (parent && parent->_col == RED) {
			Node* grandfather = parent->_parent;
			if (grandfather->_left == parent) {//�������
				Node* uncle = grandfather->_right;
				if (uncle && uncle->_col == RED) {//��һ�����������͸��׶�Ϊ��
					parent->_col = uncle->_col = BLACK;
					cur = grandfather;
					parent = cur->_parent;
				}
				else {
					if (parent->_right == cur) {
						RotateL(parent);
						swap(parent, cur);//���ｻ������ָ�룬�����ǽڵ�
					}
					RotateR(grandfather);
					parent->_col = BLACK;
					grandfather->_col = RED;
					break;
				}
			}
			else if (grandfather->_right == parent) {//�����ұ�
				Node* uncle = grandfather->_left;
				if (uncle && uncle->_col == RED) {//��һ����������������Ϊ��
					uncle->_col = parent->_col = BLACK;
					grandfather->_col = RED;
				}
				else {
					if (parent->_left == cur) {
						RotateR(parent);
						swap(parent, cur);
					}
					RotateL(grandfather);
					grandfather->_col = RED;
					parent->_col = BLACK;
					break;
				}
			}
		}
		_root->_col = BLACK;
		return true;
	}



	void RotateR(Node*& parent)//����
		//�������������ұ߸ߣ��ұߵ�����ѹ
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		Node* ppnode = parent->_parent;

		parent->_left = subLR;
		if (subLR) {
			subLR->_parent = parent;
		}

		subL->_right = parent;
		parent->_parent = subL;

		if (parent == _root) {
			_root = subL;
			subL->_parent = nullptr;
		}
		else {
			if (ppnode->_left == parent) {
				ppnode->_left = subL;
			}
			else {
				ppnode->_right = subL;
			}
			subL->_parent = ppnode;
		}
	}

	void RotateL(Node*& parent) {//����
		//��������������߸�
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		Node* ppnode = parent->_parent;

		parent->_right = subRL;
		//������ָ���ӵ��ҽڵ�
		if (subRL) {
			subRL->_parent = parent;
		}

		subR->_left = parent;
		parent->_parent = subR;

		if (_root == parent) {
			_root = subR;
			subR->_parent = nullptr;

		}
		else {
			if (ppnode->_left == parent) {
				ppnode->_left = subR;
			}
			else {
				ppnode->_right = subR;
			}
			subR->_parent = ppnode;
		}
	}


	void _midorder(Node* root) {
		KOfT koft;
		//��������Ӻ���
		if (root == nullptr) return;
		_midorder(root->_left);
		cout << koft(root->_data) << " ";
		_midorder(root->_right);
	}

	void midorder() {//�������
		_midorder(_root);
	}


	iterator begin() {
		Node* cur = _root;
		while (cur && cur->_left) {
			cur = cur->_left;
		}
		return iterator(cur);
	}

	iterator end() {
		return iterator(nullptr);
	}
};

