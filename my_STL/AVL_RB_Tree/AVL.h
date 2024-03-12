#pragma once

template<class K, class V>
struct AVLTreeNode {
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;
	pair<K, V> _kv;
	int _bf;//平衡因子
	AVLTreeNode(const pair<K, V>& kv) :_left(nullptr), _right(nullptr), _parent(nullptr), _bf(0), _kv(kv) {}

};

template <class K, class V>
class AVLTree {
private:
	typedef AVLTreeNode<K, V> Node;
	Node* _root = nullptr;
public:
	bool insert(const pair<K, V>& new_kv) {
		if (_root == nullptr) {
			_root = new Node(new_kv);
			return true;
		}
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur) {
			parent = cur;
			if (new_kv.first > cur->_kv.first) {
				cur = cur->_right;
			}
			else if (new_kv.first < cur->_kv.first) {
				cur = cur->_left;
			}
			else {
				return false;
			}
		}
		cur = new Node(new_kv);
		if (cur->_kv.first > parent->_kv.first) {
			parent->_right = cur;
			cur->_parent = parent;
		}
		if (cur->_kv.first < parent->_kv.first) {
			parent->_left = cur;
			cur->_parent = parent;
		}

		while (parent) {
			//从这里开始检查平衡因子，一直遇到有问题或者没有问题为止
			if (parent->_left == cur) {
				parent->_bf--;
			}
			else if (parent->_right == cur) {
				parent->_bf++;
			}
			if (parent->_bf == 0) {
				break;
			}
			else if (parent->_bf == 1 || parent->_bf == -1) {
				cur = parent;
				parent = parent->_parent;
			}
			else if (parent->_bf == -2 || parent->_bf == 2) {
				//旋转处理
				if (parent->_bf == -2) {
					if (parent->_left->_bf == -1) {
						RotateR(parent);
					}
					else if (parent->_left->_bf == 1) {
						RotateLR(parent);
					}
				}
				else if (parent->_bf == 2) {
					if (parent->_right->_bf == 1) {
						RotateL(parent);
					}
					else if (parent->_right->_bf == -1) {
						RotateRL(parent);
					}
				}
				break;
			}
		}
		return true;
	}


	void RotateL(Node*& parent) {
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
		parent->_bf = subR->_bf = 0;
	}

	void RotateR(Node*& parent)
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
		parent->_bf = subL->_bf = 0;
	}
	void RotateLR(Node*& parent) {
		//双旋，先左旋，再右旋
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		RotateL(subL);
		RotateR(parent);
		if (subLR->_bf == 1) {
			subLR->_bf = 0;
			subL->_bf = -1;
			parent->_bf = 0;
		}
		else if (subLR->_bf == -1) {
			subLR->_bf = 0;
			subL->_bf = 0;
			parent->_bf = 1;
		}
		else if (subLR->_bf == 0) {
			subLR->_bf = 0;
			subL->_bf = 0;
			parent->_bf = 0;
		}
	}

	void RotateRL(Node*& parent) {
		//双旋，先右旋，再左旋
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		int bf_val = subRL->_bf;
		RotateR(subR);
		RotateL(parent);
		if (bf_val == 1) {
			subRL->_bf = 0;
			subR->_bf = 0;
			parent->_bf = -1;
		}
		else if (bf_val == -1)
		{
			subRL->_bf = 0;
			subR->_bf = 1;
			parent->_bf = 0;
		}
		else if (bf_val == 0) {
			subRL->_bf = 0;
			subR->_bf = 0;
			parent->_bf = 0;
		}
	}

	void _midorder(Node* root) {
		//中序遍历子函数
		if (root == nullptr) return;
		_midorder(root->_left);
		cout << root->_kv.first << " ";
		_midorder(root->_right);
	}

	void midorder() {//中序遍历
		_midorder(_root);
	}

	int Height(Node* root) {
		if (root == nullptr) return 0;
		int left = Height(root->_left);
		int right = Height(root->_right);
		return max(left, right) + 1;
	}

	bool _is_Balance(Node* root) {
		if (root == nullptr) return true;
		int  Left_High = Height(root->_left);
		int  Right_High = Height(root->_right);
		return abs(Left_High - Right_High) < 2 && _is_Balance(root->_left) && _is_Balance(root->_right);
	}

	bool is_Balance() {
		return _is_Balance(_root);
	}


};

