#pragma once



//template <class K>
//struct BSnode{//���������������ڵ�
//	K _key;
//	BSnode<K>* _left;
//	BSnode<K>* _right;
//	BSnode(const K& key):_key(key),_left(nullptr),_right(nullptr){}
//};
//
//
//template <class K>
//class BStree {
//	typedef BSnode<K> node;
//	node* _root=nullptr;
//public:
//	//��������
//	bool BS_insert(const K& key) {
//		if (_root == nullptr) {//��һ��
//			_root =new node(key);
//			return true;
//		}
//		node* last=nullptr;
//		node* cur = _root;//������һ���Ľڵ�
//		while (cur) {
//			last = cur;
//			if (key > cur->_key) {
//				cur = cur->_right;
//			}
//			else if (key < cur->_key) {
//				cur = cur->_left;
//			}
//			else {
//				return false;
//			}
//		}
//		cur =new node(key);
//		if (cur->_key > last->_key) {//�ж���һ��������߻����ұ�
//			last->_right = cur;
//		}
//		else {
//			last->_left = cur;
//		}
//		return true;
//	}
//
//	//����Ԫ��(����д��)
//	bool find(const K& key) {
//		node* cur = _root;
//		while (cur) {
//			if (key > cur->_key) {
//				cur = cur->_right;
//			}
//			else if (key < cur->_key) {
//				cur = cur->_left;
//			}
//			else {
//				//cout << "���ҳɹ�" << endl;
//				return true;
//			}
//		}
//		//cout << "����ʧ��" << endl;//�����û�У���ʱcurΪnullptr,����false
//		return false;
//	}
//
//
//	//bool _find(node* root,const K& key) {
//	//	if (root == nullptr) {
//	//		cout << "����ʧ��" << endl;
//	//		return false;
//	//	}
//	//	if (root->_key == key) {
//	//		cout <<"����" <<key << "�����ҳɹ�" << endl;
//	//		return true;
//	//	}
//	//	if (key > root->_key) {
//	//		_find(root->_right, key);
//	//	}
//	//	if (key < root->_key) {
//	//		_find(root->_left,key);
//	//	}
//	//}
//	////����Ԫ��(�ݹ�д��)
//	//bool find(const K& key){//����Ԫ��(�ݹ�д��)
//	//	return _find(this->_root, key);
//	//}
//
//	//ɾ��Ԫ��
//	bool erase(const K& key) {
//		if (!find(key)) {
//			cout << "Ԫ����û�и�Ԫ��,ɾ��ʧ��"<<endl;
//			return false;
//		}
//		node* cur = _root;
//		node* last = cur;
//		while (cur->_key != key) {
//			last = cur;
//			if (key > cur->_key) {
//				cur = cur->_right;
//			}
//			else {
//				cur = cur->_left;
//			}
//		}//�ҵ�Ҫɾ�Ľڵ�
//		node* del_left = cur->_left;
//		node* del_right = cur->_right;
//
//		if (!del_left) {//����Ϊ�գ�����ָ��ɾ����
//			if (cur == _root) {
//				_root = cur->_right;
//			}
//			if (last->_left == cur) {
//				last->_left = cur->_right;
//			}
//			else {
//				last->_right = cur->_right;
//			}
//			delete cur;
//			cur = nullptr;
//			return true;
//		}
//		if (!del_right) {//����Ϊ�գ�����ԭ��ָ���Ǳߣ���ָ���ǱߵĽڵ�ΪҪɾ���ұ�
//			if (cur == _root) {
//				_root = cur->_left;
//			}
//			if (last->_right == cur) {
//				last->_right = cur->_left;
//			}
//			else {
//				last->_left = cur->_left;
//			}
//			delete cur;
//			cur = nullptr;
//			return true;
//		}
//		node* minright = cur->_right;//������Ҷ���Ϊ�գ���Ҫ������������ҵ���С�����滻Ҫɾ��ֵ
//		node* last_right = cur;//�������������������󣬼��Ҵ�������Сֵ���滻
//		while (minright->_left) {
//			last_right = minright;
//			minright = minright->_left;
//		}
//		if (last_right->_left == minright) {//Ҫ�ж���һ����ָ��
//			last_right->_left = minright->_right;
//		}
//		else {
//			last_right->_right = minright->_right;
//		}
//		cur->_key = minright->_key;
//		delete minright;
//		minright = nullptr;
//		return true;
//	}
//
//
//	//��������������Ľ������˳�򷵻ص�
//	void _inorder(node* root) {//��Ϊ�ǵݹ飬�������������private����������������Ҫдһ���Ӻ�����ʵ��
//		if (root == nullptr) { return; }
//		_inorder(root->_left);
//		cout << root->_key << " ";
//		_inorder(root->_right);
//	}
//	void inorder() {
//		_inorder(_root);
//	}
//
//};



//template <class K,class V>
//struct BSnode {//���������������ڵ�
//	K _key;
//	V _value;
//	BSnode<K,V>* _left;
//	BSnode<K,V>* _right;
//	BSnode(const K& key,const V& value) :_value(value), _key(key), _left(nullptr), _right(nullptr) {}
//};
//
//
//template <class K,class V>//key-valueģ��
//class BStree {
//	typedef BSnode<K,V> node;
//	node* _root = nullptr;
//public:
//	//��������
//	bool BS_insert(const K& key,const V& value) {
//		if (_root == nullptr) {//��һ��
//			_root = new node(key,value);
//			return true;
//		}
//		node* last = nullptr;
//		node* cur = _root;//������һ���Ľڵ�
//		while (cur) {
//			last = cur;
//			if (key > cur->_key) {
//				cur = cur->_right;
//			}
//			else if (key < cur->_key) {
//				cur = cur->_left;
//			}
//			else {
//				return false;
//			}
//		}
//		cur = new node(key,value);
//		if (cur->_key > last->_key) {//�ж���һ��������߻����ұ�
//			last->_right = cur;
//		}
//		else {
//			last->_left = cur;
//		}
//		return true;
//	}
//
//	//����Ԫ��(����д��)
//	node* find(const K& key) {
//		node* cur = _root;
//		while (cur) {
//			if (key > cur->_key) {
//				cur = cur->_right;
//			}
//			else if (key < cur->_key) {
//				cur = cur->_left;
//			}
//			else {
//				//cout << "���ҳɹ�" << endl;
//				return cur;
//			}
//		}
//		//cout << "����ʧ��" << endl;//�����û�У���ʱcurΪnullptr,����false
//		return nullptr;
//	}
//
//		//��������������Ľ������˳�򷵻ص�
//	void _inorder(node* root) {//��Ϊ�ǵݹ飬�������������private����������������Ҫдһ���Ӻ�����ʵ��
//		if (root == nullptr) { return; }
//		_inorder(root->_left);
//		cout << root->_key << ": "<<root->_value<<endl;
//		_inorder(root->_right);
//	}
//	void inorder() {
//		_inorder(_root);
//	}
//
//
//
//
//};





//void test01() {
//	int arr[] = { 5,1,7,3,6,4,8,2 };
//	BStree<int> t;
//	for (auto i : arr) {
//		t.BS_insert(i);
//	}
//	t.inorder();
//	cout << endl;
//	for (auto i : arr) {
//		t.erase(i);
//		t.inorder();
//		cout << endl;
//	}
//
//	//t.erase(4);
//	//t.inorder();
//	//cout << endl;
//
//	//t.erase(2);
//	//t.inorder();
//	//cout << endl;
//	//t.inorder();
//	//cout << endl;
//}




//void test02() {//�ֵ�		key-valueģ��
	/*BStree<string, string> dict;
	dict.BS_insert("find", "����");
	dict.BS_insert("go", "ȥ");
	dict.BS_insert("string", "�ַ���");
	dict.BS_insert("apply", "����");
	dict.BS_insert("order", "˳��");
	dict.BS_insert("int", "����");
	string str;*/
	//while (cin >> str) {
	//	BSnode<string,string>* findnode = dict.find(str);
	//	if (findnode) {
	//		cout << findnode->_value<<endl;
	//	}
	//	else {
	//		cout << "�ֵ����޴˵��ʡ�" << endl;
	//	}
	//}
	//string str_arr[] = { "ƻ��","����","ƻ��","�㽶","����","ƻ��","����","����","����","����","ƻ��","�㽶" };
	//BStree<string, int>num;
	//for (auto i : str_arr) {
	//	num.BS_insert(i, 0);
	//}
	//for (auto e : str_arr) {
	//	BSnode<string,int>* node = num.find(e);
	//	if (node) {
	//		node->_value++;
	//	}
	//}
	//num.inorder();
	//dict.inorder();
//}

//template <class T>
//struct Treenode{//���������������ڵ�
//	T _key;
//	Treenode<T>* _left;
//	Treenode<T>* _right;
//	Treenode(const T& key):_key(key),_left(nullptr),_right(nullptr){}
//};


//����ƽ��������Ľڵ�
template<class T>
struct Treenode {
	T _key;
	Treenode<T>* _left;
	Treenode<T>* _right;
	Treenode(const T& num) :_key(num) , _left(nullptr) , _right(nullptr) {}
};


template<class T>
class BSTree {
	typedef Treenode<T> node;
	node* _root;
public:
	BSTree():_root(nullptr){}


	bool insert(const T& val) {		//	����Ԫ��(��)
		if (_root == nullptr) {
			_root = new node(val);
			//��һ�β���Ԫ��
		}
		node* parent = _root;
		node* last = _root;
		//������һ����λ�ã�Ҫ��Ȼ������
		while (parent) {
			//��parentΪ��ʱ�������λֵ����Ҫ�����λ��
			last = parent;
			if (val > parent->_key) {
				//���ڵ�ǰ�ڵ��ֵ�������ұ�
				parent = parent->_right;
			}
			else if (val < parent->_key) {
				//С�ڵ�ǰ�ڵ��ֵ,���뵽���
				parent = parent->_left;
			}
			else { return false; }
			//������ڣ���ô����false������ʧ��
		}
		parent = new node(val);
		//����һ���ڵ������������ж�����һ������߻����ұ�
		if (val > last->_key) {
			last->_right = parent;
		}
		else {
			last->_left=parent;
		}
		return true;
	}


	bool find(const T& target) {//����Ԫ�� (��)
		node* cur = _root;
		while (cur) {
			if (cur->_key == target) {
				return true;
				//�ҵ�����true
			}
			else if (target > cur->_key) {
				cur = cur->_right;
			}
			else if (target < cur->_key) {
				cur = cur->_left;
			}
		}
		//�ߵ����ﻹû�ҵ��������ʱ�Ѿ����˸�������false
		return false;
	}

	bool erase(const T& target) {
		if (!find(target)) {
			return false;
		}
		node* cur = _root;
		node* last = _root;
		while (cur->_key!=target) {
			last = cur;
			if (target > cur->_key) {
				cur = cur->_right;
			}
			else if(target<cur->_key) {
				cur = cur->_left;
			}
			else if(target == cur->_key) {
				break;
			}
		}
		if (cur->_left == nullptr) {
			//�����Ϊ��
			node* temp = cur->_right;
			if (cur == _root) {
				//���ɾ���ľ��Ǹ��ڵ㣬�պø������û��
				_root = temp;
				delete cur;
				cur = nullptr;
				return true;
			}
			if(last->_left == cur) {//����ԭ��ָ���Ǳߣ������ָ���ҵ���
				last->_left = temp;
			}
			if(last->_right==cur) {
				last->_right = temp;
			}
			delete cur;
			cur = nullptr;
			return true;
		}
		if (cur->_right == nullptr) {
			node* temp = cur->_left;
			if (cur == _root) {
				//����Ǹ��ڵ�������
				_root = temp;
				delete cur;
				cur = nullptr;
				return true;
			}
			if (last->_left == cur) {//����ԭ��ָ���Ǳߣ������ָ���ҵ���
				last->_left = temp;
			}
			else {
				last->_right = temp;
			}
			delete cur;
			cur = nullptr;
			return true;
		}
		node* minright = cur->_right;
		node* minright_last = cur;
		while (minright->_left) {
			minright_last = minright;
			minright = minright->_left;
		}
		swap(cur->_key, minright->_key);
		//��Ϊ�գ����ĸ���ָ��������,��Ϊ�յĻ�����߿϶��ǿյģ���Ϊ�����ҵľ������Ϊ�յģ����Բ��ÿ����ұߵ����
		node* temp = minright->_right;
		if (minright_last->_left == minright) {
			minright_last->_left=temp;
		}
		else {
			minright_last->_right = temp;
		}
		delete minright;
		minright = nullptr;
		return true;
	}

	void print() {//��ӡ�����������Ԫ��
		midorder();
		cout << endl;

	}

	void _midorder(node* root) {//�������
		if (root == nullptr) return;
		_midorder(root->_left);
		cout << root->_key << " ";
		_midorder(root->_right);
	}
	void midorder() {//��Ϊ��thisָ�룬�������Ӻ���������һЩ
		_midorder(_root);
	}
	bool empty() {
		if (_root == nullptr) {
			return true;
		}
		return false;
	}

};

static int sum = 0;
void test_my_write_BS() 
{
	BSTree<int> bst;
	//bst.insert(3);
	//bst.insert(1);
	//bst.insert(0);
	//bst.insert(5);
	//bst.insert(2);
	//bst.insert(6);
	//bst.insert(15);
	//bst.insert(-2);
	//bst.insert(-3);
	//bst.insert(24);
	//bst.insert(16);
	//bst.print();

	//bst.erase(15);
	//bst.print();
	//bst.erase(6);
	//bst.print();
	//bst.erase(0);
	//bst.print();
	//bst.erase(-2);
	//bst.print();
	//bst.erase(24);
	//bst.print();
	//bst.erase(16);
	//bst.print();
	//bst.erase(1);
	//bst.print();
	//bst.erase(-3);
	//bst.print();
	//bst.erase(3);
	//bst.print();
	//bst.erase(2);
	//bst.print();
	//bst.erase(5);
	//bst.print();
	//5, 3, 6, 2, 4, null, 7
	bst.insert(5);
	bst.insert(3);
	bst.insert(6);
	bst.insert(2);
	bst.insert(4);
	bst.insert(7);
	bst.erase(5);

}





