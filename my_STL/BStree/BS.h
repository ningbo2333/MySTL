#pragma once



//template <class K>
//struct BSnode{//创建二叉搜索数节点
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
//	//插入数据
//	bool BS_insert(const K& key) {
//		if (_root == nullptr) {//第一次
//			_root =new node(key);
//			return true;
//		}
//		node* last=nullptr;
//		node* cur = _root;//保存上一个的节点
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
//		if (cur->_key > last->_key) {//判断上一个链接左边还是右边
//			last->_right = cur;
//		}
//		else {
//			last->_left = cur;
//		}
//		return true;
//	}
//
//	//查找元素(朴素写法)
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
//				//cout << "查找成功" << endl;
//				return true;
//			}
//		}
//		//cout << "查找失败" << endl;//如果都没有，此时cur为nullptr,返回false
//		return false;
//	}
//
//
//	//bool _find(node* root,const K& key) {
//	//	if (root == nullptr) {
//	//		cout << "查找失败" << endl;
//	//		return false;
//	//	}
//	//	if (root->_key == key) {
//	//		cout <<"查找" <<key << "，查找成功" << endl;
//	//		return true;
//	//	}
//	//	if (key > root->_key) {
//	//		_find(root->_right, key);
//	//	}
//	//	if (key < root->_key) {
//	//		_find(root->_left,key);
//	//	}
//	//}
//	////查找元素(递归写法)
//	//bool find(const K& key){//查找元素(递归写法)
//	//	return _find(this->_root, key);
//	//}
//
//	//删除元素
//	bool erase(const K& key) {
//		if (!find(key)) {
//			cout << "元素中没有该元素,删除失败"<<endl;
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
//		}//找到要删的节点
//		node* del_left = cur->_left;
//		node* del_right = cur->_right;
//
//		if (!del_left) {//当左为空，父亲指向删的右
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
//		if (!del_right) {//当右为空，父亲原来指向那边，则指向那边的节点为要删的右边
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
//		node* minright = cur->_right;//当左和右都不为空，需要找左的最大或者右的最小，来替换要删的值
//		node* last_right = cur;//这里是找右子树的最左，即找大树的最小值来替换
//		while (minright->_left) {
//			last_right = minright;
//			minright = minright->_left;
//		}
//		if (last_right->_left == minright) {//要判断下一个的指向
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
//	//中序遍历，出来的结果就是顺序返回的
//	void _inorder(node* root) {//因为是递归，但是类里调的是private变量，所以这里需要写一个子函数来实现
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
//struct BSnode {//创建二叉搜索数节点
//	K _key;
//	V _value;
//	BSnode<K,V>* _left;
//	BSnode<K,V>* _right;
//	BSnode(const K& key,const V& value) :_value(value), _key(key), _left(nullptr), _right(nullptr) {}
//};
//
//
//template <class K,class V>//key-value模型
//class BStree {
//	typedef BSnode<K,V> node;
//	node* _root = nullptr;
//public:
//	//插入数据
//	bool BS_insert(const K& key,const V& value) {
//		if (_root == nullptr) {//第一次
//			_root = new node(key,value);
//			return true;
//		}
//		node* last = nullptr;
//		node* cur = _root;//保存上一个的节点
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
//		if (cur->_key > last->_key) {//判断上一个链接左边还是右边
//			last->_right = cur;
//		}
//		else {
//			last->_left = cur;
//		}
//		return true;
//	}
//
//	//查找元素(朴素写法)
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
//				//cout << "查找成功" << endl;
//				return cur;
//			}
//		}
//		//cout << "查找失败" << endl;//如果都没有，此时cur为nullptr,返回false
//		return nullptr;
//	}
//
//		//中序遍历，出来的结果就是顺序返回的
//	void _inorder(node* root) {//因为是递归，但是类里调的是private变量，所以这里需要写一个子函数来实现
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




//void test02() {//字典		key-value模型
	/*BStree<string, string> dict;
	dict.BS_insert("find", "查找");
	dict.BS_insert("go", "去");
	dict.BS_insert("string", "字符串");
	dict.BS_insert("apply", "申请");
	dict.BS_insert("order", "顺序");
	dict.BS_insert("int", "整形");
	string str;*/
	//while (cin >> str) {
	//	BSnode<string,string>* findnode = dict.find(str);
	//	if (findnode) {
	//		cout << findnode->_value<<endl;
	//	}
	//	else {
	//		cout << "字典中无此单词。" << endl;
	//	}
	//}
	//string str_arr[] = { "苹果","西瓜","苹果","香蕉","西瓜","苹果","西瓜","西瓜","西瓜","西瓜","苹果","香蕉" };
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
//struct Treenode{//创建二叉搜索数节点
//	T _key;
//	Treenode<T>* _left;
//	Treenode<T>* _right;
//	Treenode(const T& key):_key(key),_left(nullptr),_right(nullptr){}
//};


//定义平衡二叉树的节点
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


	bool insert(const T& val) {		//	插入元素(增)
		if (_root == nullptr) {
			_root = new node(val);
			//第一次插入元素
		}
		node* parent = _root;
		node* last = _root;
		//保存上一个的位置，要不然连不上
		while (parent) {
			//当parent为空时候，这个空位值就是要插入的位置
			last = parent;
			if (val > parent->_key) {
				//大于当前节点的值，插入右边
				parent = parent->_right;
			}
			else if (val < parent->_key) {
				//小于当前节点的值,插入到左边
				parent = parent->_left;
			}
			else { return false; }
			//如果等于，那么返回false，插入失败
		}
		parent = new node(val);
		//与上一个节点链接起来，判断连上一个的左边还是右边
		if (val > last->_key) {
			last->_right = parent;
		}
		else {
			last->_left=parent;
		}
		return true;
	}


	bool find(const T& target) {//查找元素 (查)
		node* cur = _root;
		while (cur) {
			if (cur->_key == target) {
				return true;
				//找到返回true
			}
			else if (target > cur->_key) {
				cur = cur->_right;
			}
			else if (target < cur->_key) {
				cur = cur->_left;
			}
		}
		//走到这里还没找到，代表此时已经到了根，返回false
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
			//如果左为空
			node* temp = cur->_right;
			if (cur == _root) {
				//如果删除的就是根节点，刚好根的左边没有
				_root = temp;
				delete cur;
				cur = nullptr;
				return true;
			}
			if(last->_left == cur) {//父亲原来指向那边，就令父亲指向我的右
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
				//如果是根节点的情况下
				_root = temp;
				delete cur;
				cur = nullptr;
				return true;
			}
			if (last->_left == cur) {//父亲原来指向那边，就令父亲指向我的左
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
		//左为空，他的父亲指向他的右,右为空的话，左边肯定是空的，因为我们找的就是左边为空的，所以不用考虑右边的情况
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

	void print() {//打印出中序遍历的元素
		midorder();
		cout << endl;

	}

	void _midorder(node* root) {//中序遍历
		if (root == nullptr) return;
		_midorder(root->_left);
		cout << root->_key << " ";
		_midorder(root->_right);
	}
	void midorder() {//因为有this指针，这里用子函数更方便一些
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





