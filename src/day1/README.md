## L1-7 谷歌的招聘 (20分)

2004 年 7 月，谷歌在硅谷的 101 号公路边竖立了一块巨大的广告牌（如下图）用于招聘。内容超级简单，就是一个以 .com 结尾的网址，而前面的网址是一个 10 位素数，这个素数是自然常数 e 中最早出现的 10 位连续数字。能找出这个素数的人，就可以通过访问谷歌的这个网站进入招聘流程的下一步。

![prime.jpg](https://images.ptausercontent.com/57148679-d574-4f49-b048-775c6c07791c.jpg)

自然常数 e 是一个著名的超越数，前面若干位写出来是这样的：e = 2.71828182845904523536028747135266249775724709369995957496696762772407663035354759457138217852516642**7427466391**932003059921... 其中粗体标出的 10 位数就是答案。

本题要求你编程解决一个更通用的问题：从任一给定的长度为 L 的数字中，找出最早出现的 K 位连续数字所组成的素数。

### 输入格式：

输入在第一行给出 2 个正整数，分别是 L（不超过 1000 的正整数，为数字长度）和 K（小于 10 的正整数）。接下来一行给出一个长度为 L 的正整数 N。

### 输出格式：

在一行中输出 N 中最早出现的 K 位连续数字所组成的素数。如果这样的素数不存在，则输出 `404`。注意，原始数字中的前导零也计算在位数之内。例如在 200236 中找 4 位素数，0023 算是解；但第一位 2 不能被当成 0002 输出，因为在原始数字中不存在这个 2 的前导零。

### 输入样例 1：

```in
20 5
23654987725541023819
```

### 输出样例 1：

```out
49877
```

### 输入样例 2：

```in
10 3
2468024680
```

### 输出样例 2：

```out
404
```

C++：

这道题一开始我理解错了，我以为是在 L 个数字中查找 K 个连续素数。但是题目的意思是在 L 个数中查找连续 K 个数字组成的 1 个素数。

```cpp
#include<iostream>
#include<string>

using namespace std;

/*
 * 0 和 1 都不是素数
 * 2 是唯一的偶素数
 */
bool isprime(int dig)
{
	if (dig == 0 || dig == 1)
		return false;
	if (dig == 2)
		return true;
	for (int i = 2; i * i <= dig; i++)
		if (dig % i == 0)
			return false;
	return true;
}

int main(void)
{
	string dig;
	int dignum, num; // dignum --》L，num --》K
	cin >> dignum >> num;
	cin >> dig;

	int i;
	int beg;

	// 下面的 for 循环的控制语句是 i + num <= dignum 
	// 前提是我们假设 num 是大于 0 的。如果 num 小于 0，
	// 会存在越界情况 i (+ 0) == dignum
	if (num == 0)
	{
		cout << "404" << endl;
		return 0;
	}

	for (i = 0; i + num <= dignum; i++)
	{
		string sub = dig.substr(i, num);
		int sub_i = stoi(sub, nullptr, 10);
		if (isprime(sub_i))
		{
			cout << sub << endl;
			return 0;
		}
	}

	cout << "404" << endl;

	return 0;
}
```





## L1-8 阅览室 (20分)

天梯图书阅览室请你编写一个简单的图书借阅统计程序。当读者借书时，管理员输入书号并按下`S`键，程序开始计时；当读者还书时，管理员输入书号并按下`E`键，程序结束计时。书号为不超过1000的正整数。当管理员将0作为书号输入时，表示一天工作结束，你的程序应输出当天的读者借书次数和平均阅读时间。

注意：由于线路偶尔会有故障，可能出现不完整的纪录，即只有`S`没有`E`，或者只有`E`没有`S`的纪录，系统应能自动忽略这种无效纪录。另外，题目保证书号是书的唯一标识，同一本书在任何时间区间内只可能被一位读者借阅。

### 输入格式：

输入在第一行给出一个正整数*N*（≤10），随后给出*N*天的纪录。每天的纪录由若干次借阅操作组成，每次操作占一行，格式为：

`书号`（[1, 1000]内的整数） `键值`（`S`或`E`） `发生时间`（`hh:mm`，其中`hh`是[0,23]内的整数，`mm`是[0, 59]内整数）

每一天的纪录保证按时间递增的顺序给出。

### 输出格式：

对每天的纪录，在一行中输出当天的读者借书次数和平均阅读时间（以分钟为单位的精确到个位的整数时间）。

### 输入样例：

```in
3
1 S 08:10
2 S 08:35
1 E 10:00
2 E 13:16
0 S 17:00
0 S 17:00
3 E 08:10
1 S 08:20
2 S 09:00
1 E 09:20
0 E 17:00
```

### 输出样例：

```out
2 196
0 0
1 60
```



C++

四个测试点有一个没有过

**注意：**

- 多次借书以最后一次结束为准

```cpp
#include<iostream>
#include<map>
#include<string>

using namespace std;

int main(void)
{
	map<int, int> m;
	int day, num, hour, min;
	char op;

	cin >> day;
	if (day <= 0)
	{
		cout << "0 0" << endl;
		return 0;
	}
	while (day--)
	{
		int books = 0, times = 0;
		while (1)
		{
			cin >> num >> op;
			scanf("%d:%d", &hour, &min);
			int time = hour * 60 + min;
			if (num == 0)
			{
				if (books == 0)
					cout << "0 0" << endl;
				else 
					// 四舍五入
					cout << books << " " << int((double(times) / books) + 0.5) << endl;
				
				// 注意要清空树
				m.clear();
				break;
			}
			// 插入
			if (op == 'S')
				// 多次借书，最后一次的时间为准（需要更新节点的 time，不能用 insert）
				m[num] = time;
			// 删除
			else
			{
				auto it = m.find(num);
				if (it != m.end())
				{
					books++;
					times += time - it->second;
				}
			}
		}
	}

	return 0;
}
```

参考：

https://blog.csdn.net/DanBo_C/article/details/88898029



## L2-1 出栈序列的合法性 (25分)

给定一个最大容量为 *M* 的堆栈，将 *N* 个数字按 1, 2, 3, ..., *N* 的顺序入栈，允许按任何顺序出栈，则哪些数字序列是不可能得到的？例如给定 *M*=5、*N*=7，则我们有可能得到{ 1, 2, 3, 4, 5, 6, 7 }，但不可能得到{ 3, 2, 1, 7, 5, 6, 4 }。

### 输入格式：

输入第一行给出 3 个不超过 1000 的正整数：*M*（堆栈最大容量）、*N*（入栈元素个数）、*K*（待检查的出栈序列个数）。最后 *K* 行，每行给出 *N* 个数字的出栈序列。所有同行数字以空格间隔。

### 输出格式：

对每一行出栈序列，如果其的确是有可能得到的合法序列，就在一行中输出`YES`，否则输出`NO`。

### 输入样例：

```in
5 7 5
1 2 3 4 5 6 7
3 2 1 7 5 6 4
7 6 5 4 3 2 1
5 6 4 3 7 2 1
1 7 6 5 4 3 2
```

### 输出样例：

```out
YES
NO
NO
YES
NO
```

C++

**注意：**

- 栈是有大小限制的
- `stack,queue,next_in` 在进行每个出栈顺序前需要判断。

```cpp
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<map>
#include<string>
#include<stack>
#include<vector>
#include<queue>
#include<deque>

using namespace std;

int main(void)
{
	int size, elem_num, seq_num;

	cin >> size >> elem_num >> seq_num;

	int n = seq_num;
	// 下一次入栈的元素
	
	while (n--)
	{
		queue<int> seq;
		stack<int> s;
		int next_in = 1;

		int i;
		for (i = 0; i < elem_num; i++)
		{
			int elem;
			cin >> elem;
			seq.push(elem);
		}

		while (!seq.empty())
		{
			int elem = seq.front();
			seq.pop();

			if (!s.empty() && s.top() == elem)
			{
				s.pop();
				continue;
			}

			while (next_in <= elem_num && next_in != elem)
			{
				// 限制栈的大小
				if (s.size() == size)
					break;
				s.push(next_in++);
			}
			
			if (next_in > elem_num)
			{
				cout << "NO" << endl;
				break;
			}
			// 如果还有元素没有入栈而当前栈已满
			else if (s.size() == size)
			{
				cout << "NO" << endl;
				break;
			}
			else
				// next_in 入栈出栈，下一个入栈的是下一位
				next_in++;
		}
		// 退出 while 可能是内部 break 或 seq 为空
		if(seq.empty())
			cout << "YES" << endl;
	}
	return 0;
}
```



## L2-2 抢红包 (25分)

没有人没抢过红包吧…… 这里给出*N*个人之间互相发红包、抢红包的记录，请你统计一下他们抢红包的收获。

### 输入格式：

![](D:\图片\A pic\OJ\1.png)

### 输出格式：

按照收入金额从高到低的递减顺序输出每个人的编号和收入金额（以元为单位，输出小数点后2位）。每个人的信息占一行，两数字间有1个空格。如果收入金额有并列，则按抢到红包的个数递减输出；如果还有并列，则按个人编号递增输出。

### 输入样例：

```in
10
3 2 22 10 58 8 125
5 1 345 3 211 5 233 7 13 8 101
1 7 8800
2 1 1000 2 1000
2 4 250 10 320
6 5 11 9 22 8 33 7 44 10 55 4 2
1 3 8800
2 1 23 2 123
1 8 250
4 2 121 4 516 7 112 9 10
```

### 输出样例：

```out
1 11.63
2 3.63
8 3.63
3 2.11
7 1.69
6 -1.67
9 -2.18
10 -3.26
5 -3.26
4 -12.32
```

C++:

这道题其实很简单，首先要理解题目的意思。

第一行是抢红包和发红包的总人数 N，下面 N 行是序号为 1 ~ N 的人的 **发红包记录** （抢到红包的人的编号 + 强抢到的金额）。

**注意** ：

- 输出是记得将 分 换成 元 （`/100`）

- 我想复杂了，不需要用 `map` 和 `vector`。直接使用一维数组，用 人的编号 映射数组下标即可（天然哈希表）。不过都差不多（超时的话可以调优。）

- 开始把 `lambda` 表达式写错了！写成了：

  ```cpp
  sort(v.begin(), v.end(), [](const packet& lhs, const packet& rhs)-> bool {
      return lhs.income > rhs.income || lhs.p_num > rhs.p_num 
          || lhs.id < rhs.id;});
  ```

  直接断言错误，显示 invalid comparator 。::question::question::question:

```cpp
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<map>
#include<string>
#include<stack>
#include<vector>
#include<queue>
#include<deque>
#include<algorithm>

using namespace std;

struct packet
{
	int id;
	int income;
	int p_num; // 红包个数

	packet() = default;

	packet(const int& _id)
		:id(_id)
		,income(0)
		,p_num(0)
	{}
};

int main(void)
{
	map<int, packet> p;
	int N;

	cin >> N;

	for (int i = 1; i <= N; i++)
		p.insert(make_pair(i, packet(i)));

	for (int i = 1; i <= N; i++)
	{
		int send_num, get_id, get_num;

		cin >> send_num;
		while (send_num--)
		{
			cin >> get_id >> get_num;
			p[i].income -= get_num;
			p[get_id].income += get_num;
			p[get_id].p_num++;
		}
	}

		vector<packet> v;

		for (auto& e : p)
		{
			v.push_back(e.second);
		}


		sort(v.begin(), v.end(), [](const packet& lhs, const packet& rhs)-> bool {
			if (lhs.income != rhs.income)
				return lhs.income > rhs.income;
			else
			{
				if (lhs.p_num != rhs.p_num)
					return lhs.p_num > rhs.p_num;
				else
					return lhs.id < rhs.id;
			}
			});

		for (auto& e : v)
		{
			printf("%d %.2f\n", e.id, e.income / 100.0);
		}

		return 0;
}
```



## L2-3 二叉搜索树的2层结点统计 (25分)

**二叉搜索树**或者是一棵空树，或者是具有下列性质的二叉树：若它的左子树不空，则左子树上所有结点的值均小于或等于它的根结点的值；若它的右子树不空，则右子树上所有结点的值均大于它的根结点的值；它的左、右子树也分别为二叉搜索树。

将一系列数字按给定顺序插入一棵初始为空的二叉搜索树，你的任务是统计结果树中最下面 2 层的结点数。

输入格式：输入在第一行给出一个正整数 *N* (≤1000)，为插入数字的个数。第二行给出 *N* 个 [−1000,1000] 区间内的整数。数字间以空格分隔。

输出格式：在一行中输出最下面 2 层的结点总数。

输入样例：9 25 30 42 16 20 20 35 -5 28 输出样例：6

C++

```cpp
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

	~BST(){	destroy(_tree); }
	
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

```

这样麻烦的用一个数组记录二叉树的层序的原因是二叉搜索树的深度不好计算。转念一想，为何我们不把二叉搜索树的深度记录下来呢？于是有了下面的实现。理解下面实现的前提是理解下面这段代码：

**求二叉树 K 层节点数**

```cpp
	int GetKLevelNode(Node* tree, int K)
	{
		if (!tree || K <= 0)
			return 0;
		if (tree && K == 1)
			return 1;
		return GetKLevelNode(tree->_left, K - 1) + GetKLevelNode(tree->_right, K - 1);
	}
```

参考文章：https://blog.csdn.net/beitiandijun/article/details/41941211

```cpp
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
		,depth(0)
	{}

	~BST(){	destroy(_tree); }
	
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
```



## L2-4 秀恩爱分得快 (25分)

古人云：秀恩爱，分得快。

互联网上每天都有大量人发布大量照片，我们通过分析这些照片，可以分析人与人之间的亲密度。如果一张照片上出现了 K 个人，这些人两两间的亲密度就被定义为 1/K。任意两个人如果同时出现在若干张照片里，他们之间的亲密度就是所有这些同框照片对应的亲密度之和。下面给定一批照片，请你分析一对给定的情侣，看看他们分别有没有亲密度更高的异性朋友？

### 输入格式：

输入在第一行给出 2 个正整数：N（不超过1000，为总人数——简单起见，我们把所有人从 0 到 N-1 编号。为了区分性别，我们用编号前的负号表示女性）和 M（不超过1000，为照片总数）。随后 M 行，每行给出一张照片的信息，格式如下：

```
K P[1] ... P[K]
```

其中 K（≤ 500）是该照片中出现的人数，P[1] ~ P[K] 就是这些人的编号。最后一行给出一对异性情侣的编号 A 和 B。同行数字以空格分隔。题目保证每个人只有一个性别，并且不会在同一张照片里出现多次。

### 输出格式：

首先输出 `A PA`，其中 `PA` 是与 `A` 最亲密的异性。如果 `PA` 不唯一，则按他们编号的绝对值递增输出；然后类似地输出 `B PB`。但如果 `A` 和 `B` 正是彼此亲密度最高的一对，则只输出他们的编号，无论是否还有其他人并列。

### 输入样例 1：

```in
10 4
4 -1 2 -3 4
4 2 -3 -5 -6
3 2 4 -5
3 -6 0 2
-3 2
```

### 输出样例 1：

```out
-3 2
2 -5
2 -6
```

### 输入样例 2：

```in
4 4
4 -1 2 -3 0
2 0 -3
2 2 -3
2 -1 2 
-3 2
```

### 输出样例 2：

```out
-3 2
```

C++

```cpp

```

