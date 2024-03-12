#pragma once

enum Color { RED, BLACK };

template<class K, class V>
struct RBTreenode {
	Color _col;//������ɫ
	pair<K, V> _kv;
	RBTreenode<K, V>* _left;
	RBTreenode<K, V>* _right;
	RBTreenode<K, V>* _parent;
	RBTreenode(const pair<K, V>& kv) :_left(nullptr), _right(nullptr), _parent(nullptr), _kv(kv),_col(RED) {}
	//RBTreenode(const pair<K, V>& kv) : _left(nullptr), _right(nullptr), _parent(nullptr), _kv(kv), _col(RED) {}

};

template <class K, class V>
class RBTree {
private:
	typedef RBTreenode<K, V> Node;
	Node* _root = nullptr;

public:
	bool insert(const pair<K, V>& kv) {
		if (_root == nullptr) {
			_root = new Node(kv);
			_root->_col = BLACK;//�����ڵ����ɫ��ɺ�ɫ��
			return true;
		}
		Node* parent = _root;
		Node* cur = _root;
		while (cur) {
			parent = cur;
			if (kv.first > cur->_kv.first) {
				cur = cur->_right;
			}
			else if (kv.first < cur->_kv.first) {
				cur = cur->_left;
			}
			else { return false; }
		}
		cur = new Node(kv);
		if (cur->_kv.first > parent->_kv.first) {
			parent->_right = cur;
			cur->_parent = parent;
		}
		else if (cur->_kv.first < parent->_kv.first) {
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
		//��������Ӻ���
		if (root == nullptr) return;
		_midorder(root->_left);
		cout << root->_kv.first << " ";
		_midorder(root->_right);
	}

	void midorder() {//�������
		_midorder(_root);
	}
};



