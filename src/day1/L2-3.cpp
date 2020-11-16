#include<iostream>
#include<map>
#include<string>
#include<stack>
#include<vector>
#include<queue>
#include<deque>
#include<algorithm>

using namespace std;

template<class T>
struct BSTNode
{
	T _val;
	BSTNode* _left;
	BSTNode* _right;
	BSTNode(const T& val = T())
		:_val(val)
		, _left(nullptr)
		, _right(nullptr)
	{}
};

template<class T>
class BST
{
public:
	typedef BSTNode<T> Node;
private:
	Node* _tree;
public:
	BST()
		:_tree(nullptr)
	{}

	~BST() { destroy(_tree); }

	bool insert(const T& val)
	{
		Node* cur = _tree;
		Node* pcur = nullptr;

		while (cur)
		{
			if (cur->_val >= val)
			{
				pcur = cur;
				cur = cur->_left;
			}
			else
			{
				pcur = cur;
				cur = cur->_right;
			}
		}
		Node* node = new Node(val);

		if (pcur == nullptr)
			_tree = node;
		else
		{
			if (pcur->_val >= val)
				pcur->_left = node;
			else
				pcur->_right = node;
		}

		return true;
	}

	int countLastKLevelNodes(int k)
	{
		if (k <= 0)
			return 0;
		queue<Node*> q;
		vector<Node*> v;
		Node* DELIM = nullptr;

		q.push(_tree);
		q.push(DELIM);
		v.push_back(_tree);
		v.push_back(DELIM);

		while (!q.empty())
		{
			Node* top = q.front();
			q.pop();

			if (top->_left)
			{
				q.push(top->_left);
				v.push_back(top->_left);
			}
			if (top->_right)
			{
				q.push(top->_right);
				v.push_back(top->_right);
			}

			// 此时 q 中只剩最后一个分割符
			if (q.size() == 1)
				break;
			if (q.front() == DELIM)
			{
				q.pop();
				q.push(DELIM);
				v.push_back(DELIM);
			}
		}

		auto rit = v.rbegin();
		int cnt = 0, flg = 0;
		// 倒序遍历 vector
		while (rit != v.rend())
		{
			if (*rit == DELIM)
				flg++;
			else
				cnt++;
			// 每一层后都有一个分隔符
			// 倒序遍历最后 k 层,在遇到第 k + 1 个分隔符时（倒数第 k + 1 层末尾）结束
			if (flg == k + 1)
				break;
			++rit;
		}
		return cnt;
	}

	void destroy(Node* tree)
	{
		if (tree)
		{
			destroy(tree->_left);
			destroy(tree->_right);
			delete tree;
		}
	}
};

int main(void)
{
	BST<int> bst;
	int N;
	cin >> N;

	while (N--)
	{
		int num;
		cin >> num;
		bst.insert(num);
	}

	cout << bst.countLastKLevelNodes(2) << endl;

	return 0;
}

// ================ 方法 2 =============
template<class T>
struct BSTNode
{
	T _val;
	int level;
	BSTNode* _left;
	BSTNode* _right;
	BSTNode(const T& val = T())
		:_val(val)
		, _left(nullptr)
		, _right(nullptr)
	{}
};

template<class T>
class BST
{
public:
	typedef BSTNode<T> Node;
private:
	Node* _tree;
	int depth;
public:
	BST()
		:_tree(nullptr)
		, depth(0)
	{}

	~BST() { destroy(_tree); }

	bool insert(const T& val)
	{
		Node* cur = _tree;
		Node* pcur = nullptr;

		while (cur)
		{
			if (cur->_val >= val)
			{
				pcur = cur;
				cur = cur->_left;
			}
			else
			{
				pcur = cur;
				cur = cur->_right;
			}
		}
		Node* node = new Node(val);

		if (pcur == nullptr)
		{
			_tree = node;
			_tree->level = 1;
			depth = 1;
		}
		else
		{
			if (pcur->_val >= val)
				pcur->_left = node;
			else
				pcur->_right = node;

			node->level = pcur->level + 1;
			// 更新树的深度
			depth = depth > node->level ? depth : node->level;
		}

		return true;
	}

	int countLastKLevelNodes(int k)
	{
		if (k <= 0)
			return 0;
		k = k > depth ? depth : k;
		int cnt = 0;
		while (k > 0)
		{
			// 将倒叙转换为正序
			int level = depth - k + 1;
			cnt += GetKLevelNode(_tree, level);
			k--;
		}
		return cnt;
	}

	void destroy(Node* tree)
	{
		if (tree)
		{
			destroy(tree->_left);
			destroy(tree->_right);
			delete tree;
		}
	}

private:
	int GetKLevelNode(Node* tree, int K)
	{
		if (!tree || K <= 0)
			return 0;
		if (tree && K == 1)
			return 1;
		return GetKLevelNode(tree->_left, K - 1) + GetKLevelNode(tree->_right, K - 1);
	}
};