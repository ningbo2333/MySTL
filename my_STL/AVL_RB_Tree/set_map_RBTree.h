#pragma once


enum Color { RED, BLACK };
template<class T>//定义红黑树的节点
struct RBTreenode {
	Color _col;//定义颜色
	T _data;
	RBTreenode<T>* _left;
	RBTreenode<T>* _right;
	RBTreenode<T>* _parent;
	RBTreenode(const T& data) :_left(nullptr), _right(nullptr), _parent(nullptr), _data(data), _col(RED) {}
	//RBTreenode(const pair<K, V>& kv) : _left(nullptr), _right(nullptr), _parent(nullptr), _kv(kv), _col(RED) {}

};


template<class T>//迭代器
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
		if (_node->_right) {//右边为空
			Node* subLeft = _node->_right;
			while (subLeft->_right) {
				subLeft = subLeft->_left;
			}
			_node = subLeft;
		}
		else {//如果右边为空，在父亲的左边，那么就直接返回他的父亲，但是如果在父亲的右边，那就需要进入下边的while循环里了
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
			_root->_col = BLACK;//将根节点的颜色变成黑色的
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
			if (grandfather->_left == parent) {//都在左边
				Node* uncle = grandfather->_right;
				if (uncle && uncle->_col == RED) {//第一种情况，叔叔和父亲都为红
					parent->_col = uncle->_col = BLACK;
					cur = grandfather;
					parent = cur->_parent;
				}
				else {
					if (parent->_right == cur) {
						RotateL(parent);
						swap(parent, cur);//这里交换的是指针，并不是节点
					}
					RotateR(grandfather);
					parent->_col = BLACK;
					grandfather->_col = RED;
					break;
				}
			}
			else if (grandfather->_right == parent) {//都在右边
				Node* uncle = grandfather->_left;
				if (uncle && uncle->_col == RED) {//第一种情况，叔叔存在且为红
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



	void RotateR(Node*& parent)//右旋
		//单旋，右旋，右边高，右边的往下压
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

	void RotateL(Node*& parent) {//左旋
		//单旋，左旋，左边高
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		Node* ppnode = parent->_parent;

		parent->_right = subRL;
		//父的右指向子的右节点
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
		//中序遍历子函数
		if (root == nullptr) return;
		_midorder(root->_left);
		cout << koft(root->_data) << " ";
		_midorder(root->_right);
	}

	void midorder() {//中序遍历
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

