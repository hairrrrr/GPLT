## 7-2 后天 (5分)

如果今天是星期三，后天就是星期五；如果今天是星期六，后天就是星期一。我们用数字1到7对应星期一到星期日。给定某一天，请你输出那天的“后天”是星期几。

### 输入格式：

输入第一行给出一个正整数`D`（1 ≤ `D` ≤ 7），代表星期里的某一天。

### 输出格式：

在一行中输出`D`天的后天是星期几。

### 输入样例：

```in
3
```

### 输出样例：

```out
5
```



C++

```cpp
#include<bits/stdc++.h>

using namespace std;

int  main(void)
{
    int n;
    cin >> n;
    // (n - 1) % 7 + 1 将 1 ~ 7 映射为 0 ~ 6
    // (n + 1) --> (n - 1 + 2)
    cout << ( (n + 1) % 7 + 1 ) << endl;
    
    return 0;
}
```



## 7-3 装睡 (10分)

你永远叫不醒一个装睡的人 —— 但是通过分析一个人的呼吸频率和脉搏，你可以发现谁在装睡！医生告诉我们，正常人睡眠时的呼吸频率是每分钟15-20次，脉搏是每分钟50-70次。下面给定一系列人的呼吸频率与脉搏，请你找出他们中间有可能在装睡的人，即至少一项指标不在正常范围内的人。

### 输入格式：

输入在第一行给出一个正整数*N*（≤10）。随后*N*行，每行给出一个人的名字（仅由英文字母组成的、长度不超过3个字符的串）、其呼吸频率和脉搏（均为不超过100的正整数）。

### 输出格式：

按照输入顺序检查每个人，如果其至少一项指标不在正常范围内，则输出其名字，每个名字占一行。

### 输入样例：

```in
4
Amy 15 70
Tom 14 60
Joe 18 50
Zoe 21 71
```

### 输出样例：

```out
Tom
Zoe
```



C++

**注意**

可以边输入边输出。

```cpp
#include<bits/stdc++.h>

using namespace std;

int main(void)
{
	int n;
	cin >> n;

	while (n--)
	{
		string name;
		int breath, palse;
		cin >> name >> breath >> palse;
		if (breath < 15 || breath > 20 || palse < 50 || palse > 70)
			cout << name << endl;
		else
			continue;
	}

	return 0;
}
```



## 7-4 新胖子公式 (10分)

根据钱江晚报官方微博的报导，最新的肥胖计算方法为：体重(kg) / 身高(m) 的平方。如果超过 25，你就是胖子。于是本题就请你编写程序自动判断一个人到底算不算胖子。

### 输入格式：

输入在一行中给出两个正数，依次为一个人的体重（以 kg 为单位）和身高（以 m 为单位），其间以空格分隔。其中体重不超过 1000 kg，身高不超过 3.0 m。

### 输出格式：

首先输出将该人的体重和身高代入肥胖公式的计算结果，保留小数点后 1 位。如果这个数值大于 25，就在第二行输出 `PANG`，否则输出 `Hai Xing`。

### 输入样例 1：

```in
100.1 1.74
```

### 输出样例 1：

```out
33.1
PANG
```

### 输入样例 2：

```in
65 1.70
```

### 输出样例 2：

```out
22.5
Hai Xing
```

C++

**注意**

体重(kg) / 身高(m) 的平方 含义是 体重(kg) / (身高(m) 的平方)

```cpp
#include<bits/stdc++.h>

using namespace std;

int main(void)
{
	double wei, hei;

	cin >> wei >> hei;
	
	double res = wei / (hei * hei);
	printf("%.1f\n", res);

	if (res > 25)
		cout << "PANG" << endl;
	else
		cout << "Hai Xing" << endl;

	return 0;
}
```



## 7-5 稳赢 (15分)

大家应该都会玩“锤子剪刀布”的游戏：两人同时给出手势，胜负规则如图所示：

![img](https://images.ptausercontent.com/367)

现要求你编写一个稳赢不输的程序，根据对方的出招，给出对应的赢招。但是！为了不让对方输得太惨，你需要每隔*K*次就让一个平局。

### 输入格式：

输入首先在第一行给出正整数*K*（≤10），即平局间隔的次数。随后每行给出对方的一次出招：`ChuiZi`代表“锤子”、`JianDao`代表“剪刀”、`Bu`代表“布”。`End`代表输入结束，这一行不要作为出招处理。

### 输出格式：

对每一个输入的出招，按要求输出稳赢或平局的招式。每招占一行。

### 输入样例：

```in
2
ChuiZi
JianDao
Bu
JianDao
Bu
ChuiZi
ChuiZi
End
```

### 输出样例：

```out
Bu
ChuiZi
Bu
ChuiZi
JianDao
ChuiZi
Bu
```



C++

**注意**

- `continue` 的使用

```cpp
#include<bits/stdc++.h>

using namespace std;

const char* win[3] = { "ChuiZi", "JianDao", "Bu" };
int flg;

int main(void)
{
	string str;
	int K;

	cin >> K;
	cin >> str;

	while (str != "End")
	{
		if (flg++ == K)
		{
			cout << str << endl;
			flg = 0;
			// 注意这里不能 continue
		}
		else
		{
			if (str == win[0])
				cout << win[2] << endl;
			else if (str == win[1])
				cout << win[0] << endl;
			else
				cout << win[1] << endl;
		}
		cin >> str;
	}

	return 0;
}
```



## 7-6 幸运彩票 (15分)

彩票的号码有 6 位数字，若一张彩票的前 3 位上的数之和等于后 3 位上的数之和，则称这张彩票是幸运的。本题就请你判断给定的彩票是不是幸运的。

### 输入格式：

输入在第一行中给出一个正整数 N（≤ 100）。随后 N 行，每行给出一张彩票的 6 位数字。

### 输出格式：

对每张彩票，如果它是幸运的，就在一行中输出 `You are lucky!`；否则输出 `Wish you good luck.`。

### 输入样例：

```in
2
233008
123456
```

### 输出样例：

```out
You are lucky!
Wish you good luck.
```

C++

```cpp
#include<bits/stdc++.h>

using namespace std;

int Left, Right;
int flg;

int main(void)
{
	int N;
	cin >> N;

	while (N--)
	{
		string num;
		cin >> num;
		for (auto& e : num)
		{
			if (flg++ < 3)
			{
				Left += e - '0';
			}
			else
			{
				Right += e - '0';
			}
		}
		if (Left == Right)
			cout << "You are lucky!" << endl;
		else
			cout << "Wish you good luck." << endl;

		Left = Right = 0;
		flg = 0;
	}

	return 0;
}
```

更短：

```cpp
#include<bits/stdc++.h>

using namespace std;

int main(void)
{
	int N;
	cin >> N;

	while (N--)
	{
		string num;
		cin >> num;
		if (num[0] + num[1] + num[2] == num[3] + num[4] + num[5])
			cout << "You are lucky!" << endl;
		else
			cout << "Wish you good luck." << endl;
	}

	return 0;
}
```



## 7-7 Left-pad (20分)

根据新浪微博上的消息，有一位开发者不满NPM（Node Package Manager）的做法，收回了自己的开源代码，其中包括一个叫left-pad的模块，就是这个模块把javascript里面的React/Babel干瘫痪了。这是个什么样的模块？就是在字符串前填充一些东西到一定的长度。例如用`*`去填充字符串`GPLT`，使之长度为10，调用left-pad的结果就应该是`******GPLT`。Node社区曾经对left-pad紧急发布了一个替代，被严重吐槽。下面就请你来实现一下这个模块。

### 输入格式：

输入在第一行给出一个正整数`N`（≤104）和一个字符，分别是填充结果字符串的长度和用于填充的字符，中间以1个空格分开。第二行给出原始的非空字符串，以回车结束。

### 输出格式：

在一行中输出结果字符串。

### 输入样例1：

```in
15 _
I love GPLT
```

### 输出样例1：

```out
____I love GPLT
```

### 输入样例2：

```
4 *
this is a sample for cut
```

### 输出样例2：

```
 cut
```

C++

**注意**

- `cut` 的含义是输出字符串后 N 个字符
- 注意在 `getline` 之前吸收 `cin` 后的换行符

```cpp
#include<bits/stdc++.h>

using namespace std;

int main(void)
{
	int N;
	char ch;
	string str;

	cin >> N >> ch;
	getchar();
	getline(cin, str);

	if (str.size() > N)
		cout << str.substr(str.size() - N, N) << endl;
	else if (str.size() == N)
		cout << str << endl;
	else
	{
		for (int i = 0; i < N - str.size(); i++)
			cout << ch;
		cout << str << endl;
	}

	return 0;
}
```



7-8 打印沙漏 (20分)

本题要求你写个程序把给定的符号打印成沙漏的形状。例如给定17个“*”，要求按下列格式打印

```
*****
 ***
  *
 ***
*****
```

所谓“沙漏形状”，是指每行输出奇数个符号；各行符号中心对齐；相邻两行符号数差2；符号数先从大到小顺序递减到1，再从小到大顺序递增；首尾符号数相等。

给定任意N个符号，不一定能正好组成一个沙漏。要求打印出的沙漏能用掉尽可能多的符号。

### 输入格式:

输入在一行给出1个正整数N（≤1000）和一个符号，中间以空格分隔。

### 输出格式:

首先打印出由给定符号组成的最大的沙漏形状，最后在一行中输出剩下没用掉的符号数。

### 输入样例:

```in
19 *
```

### 输出样例:

```out
*****
 ***
  *
 ***
*****
2
```

C++

```cpp
#include<bits/stdc++.h>

using namespace std;

int main(void)
{
	int N;
	char ch;
	cin >> N >> ch;

	int num = (N - 1) / 2;
	// 计算行数
	int sum = 0;
	int i;
	for (i = 1; ; i++)
	{
		sum += 2 * i + 1;
		if (sum > num)
			break;
	}
	int used = 1 + 2 * (sum - (i * 2 + 1));
	int level = i - 1;
	

	if (level == 0)
		cout << ch << endl << N - 1 << endl;
	else
	{
		// i--
		// 输出沙漏最中间的一个 *
		for (i = level; i >= 0; i--)
		{
			int pad = level - i;
			while (pad--)
				cout << " ";
			for (int j = 0; j < 2 * i + 1; j++)
				cout << ch;
			cout << endl;
		}

		for (i = 1; i <= level; i++)
		{
			int pad = level - i;
			while (pad--)
				cout << " ";
			for (int j = 0; j < 2 * i + 1; j++)
				cout << ch;
			cout << endl;
		}
		cout << N - used << endl;
	}

	return 0;
}
```



## L1-011 A-B (20分)

本题要求你计算*A*−*B*。不过麻烦的是，*A*和*B*都是字符串 —— 即从字符串*A*中把字符串*B*所包含的字符全删掉，剩下的字符组成的就是字符串*A*−*B*。

### 输入格式：

输入在2行中先后给出字符串*A*和*B*。两字符串的长度都不超过104，并且保证每个字符串都是由可见的ASCII码和空白字符组成，最后以换行符结束。

### 输出格式：

在一行中打印出*A*−*B*的结果字符串。

### 输入样例：

```in
I love GPLT!  It's a fun game!
aeiou
```

### 输出样例：

```out
I lv GPLT!  It's  fn gm!
```

C++

```cpp
#include<bits/stdc++.h>

using namespace std;

int main(void)
{
	unordered_set<char> s;
	string A, B;
	getline(cin, A);
	getline(cin, B);

	for (auto& e : B)
	{
		s.insert(e);
	}

	for (auto& e : A)
	{
		if (s.find(e) == s.end())
			cout << e;
	}
	cout << endl;

	return 0;
}
```

字符串输入如果写成：

```cpp
	getline(cin, A);
	cin >> B;
```

有一个点会过不了。



## 7-9 关于堆的判断 (25分)

将一系列给定数字顺序插入一个初始为空的小顶堆`H[]`。随后判断一系列相关命题是否为真。命题分下列几种：

- `x is the root`：`x`是根结点；
- `x and y are siblings`：`x`和`y`是兄弟结点；
- `x is the parent of y`：`x`是`y`的父结点；
- `x is a child of y`：`x`是`y`的一个子结点。

### 输入格式：

每组测试第1行包含2个正整数`N`（≤ 1000）和`M`（≤ 20），分别是插入元素的个数、以及需要判断的命题数。下一行给出区间[−10000,10000]内的`N`个要被插入一个初始为空的小顶堆的整数。之后`M`行，每行给出一个命题。题目保证命题中的结点键值都是存在的。

### 输出格式：

对输入的每个命题，如果其为真，则在一行中输出`T`，否则输出`F`。

### 输入样例：

```in
5 4
46 23 26 24 10
24 is the root
26 and 23 are siblings
46 is the parent of 23
23 is a child of 10
```

### 输出样例：

```out
F
T
F
T
```

C++

**注意**

- 2，4  测试点没有过

`make_heap` 是 `<algorithm>` 头中的函数，下面是常用接口的演示：

```cpp
// range heap example
#include <iostream>     // std::cout
#include <algorithm>    // std::make_heap, std::pop_heap, std::push_heap, std::sort_heap
#include <vector>       // std::vector

int main () {
  int myints[] = {10,20,30,5,15};
  std::vector<int> v(myints,myints+5);

  std::make_heap (v.begin(),v.end());
  std::cout << "initial max heap   : " << v.front() << '\n';

  std::pop_heap (v.begin(),v.end()); v.pop_back();
  std::cout << "max heap after pop : " << v.front() << '\n';

  v.push_back(99); std::push_heap (v.begin(),v.end());
  std::cout << "max heap after push: " << v.front() << '\n';

  std::sort_heap (v.begin(),v.end());

  std::cout << "final sorted range :";
  for (unsigned i=0; i<v.size(); i++)
    std::cout << ' ' << v[i];

  std::cout << '\n';

  return 0;
}
```

.

```cpp
#include<bits/stdc++.h>

using namespace std;

int main(void)
{
	vector<int> heap;
	
	int N, M;
	cin >> N >> M;

	// 数组第一个元素不用
	heap.push_back(0);
	while (N--)
	{
		int n;
		cin >> n;
		heap.push_back(n);
	}
	make_heap(heap.begin() + 1, heap.end(), greater<int>());

	getchar();
	while (M--)
	{
		string str;
		int flg = 0; // 置零
		getline(cin, str);
		if (str[str.length() - 1] == 't')
		{
			int root;
			sscanf(str.c_str(), "%d", &root);
			if (heap[1] == root)
				flg = 1;
		}
		else if (str[str.length() - 1] == 's')
		{
			int x, y;
			sscanf(str.c_str(), "%d %*s %d", &x, &y);
			int idx1 = find(heap.begin() + 1, heap.end(), x) - heap.begin();
			int idx2 = find(heap.begin() + 1, heap.end(), y) - heap.begin();
			if (x != y && idx1 / 2 == idx2 / 2)
				flg = 1;
		}
		else
		{
			int x, y;
			char diff[10] = {0};
			sscanf(str.c_str(), "%d %*s %*s %s %*s %d", &x, diff, &y);
			int idx1 = find(heap.begin() + 1, heap.end(), x) - heap.begin();
			int idx2 = find(heap.begin() + 1, heap.end(), y) - heap.begin();
			if (strcmp(diff, "parent") == 0)
			{
				if (idx1  == idx2 / 2)
					flg = 1;
			}
			else
			{
				if (idx1 / 2 == idx2)
					flg = 1;
			}
		}
		if (flg)
			cout << "T" << endl;
		else
			cout << "F" << endl;
	}

	return 0;
}
```

自己手写一个向上调整函数，就直接过了

```cpp
#include<bits/stdc++.h>

using namespace std;

vector<int> heap;

void ShiftUp(int child)
{
	int parent = child / 2;
	while (parent > 0)
	{
		// 小堆
		if (heap[parent] > heap[child])
		{
			swap(heap[parent], heap[child]);
			child = parent;
			parent = child / 2;
		}
		else
			break;
	}
}

int main(void)
{
	int N, M;
	cin >> N >> M;

	// 数组第一个元素不用
	heap.push_back(0);
	while (N--)
	{
		int n;
		cin >> n;
		heap.push_back(n);
		ShiftUp(heap.size() - 1);
	}
	
	getchar();
	while (M--)
	{
		string str;
		int flg = 0; // 置零
		getline(cin, str);
		if (str[str.length() - 1] == 't')
		{
			int root;
			sscanf(str.c_str(), "%d", &root);
			if (heap[1] == root)
				flg = 1;
		}
		else if (str[str.length() - 1] == 's')
		{
			int x, y;
			sscanf(str.c_str(), "%d %*s %d", &x, &y);
			int idx1 = find(heap.begin() + 1, heap.end(), x) - heap.begin();
			int idx2 = find(heap.begin() + 1, heap.end(), y) - heap.begin();
			if (x != y && idx1 / 2 == idx2 / 2)
				flg = 1;
		}
		else
		{
			int x, y;
			char diff[10] = {0};
			sscanf(str.c_str(), "%d %*s %*s %s %*s %d", &x, diff, &y);
			int idx1 = find(heap.begin() + 1, heap.end(), x) - heap.begin();
			int idx2 = find(heap.begin() + 1, heap.end(), y) - heap.begin();
			if (strcmp(diff, "parent") == 0)
			{
				if (idx1  == idx2 / 2)
					flg = 1;
			}
			else
			{
				if (idx1 / 2 == idx2)
					flg = 1;
			}
		}
		if (flg)
			cout << "T" << endl;
		else
			cout << "F" << endl;
	}

	return 0;
}
```



## 7-10 愿天下有情人都是失散多年的兄妹 (25分)

呵呵。大家都知道五服以内不得通婚，即两个人最近的共同祖先如果在五代以内（即本人、父母、祖父母、曾祖父母、高祖父母）则不可通婚。本题就请你帮助一对有情人判断一下，他们究竟是否可以成婚？

### 输入格式：

输入第一行给出一个正整数`N`（2 ≤ `N` ≤104），随后`N`行，每行按以下格式给出一个人的信息：

```
本人ID 性别 父亲ID 母亲ID
```

其中`ID`是5位数字，每人不同；性别`M`代表男性、`F`代表女性。如果某人的父亲或母亲已经不可考，则相应的`ID`位置上标记为`-1`。

接下来给出一个正整数`K`，随后`K`行，每行给出一对有情人的`ID`，其间以空格分隔。

注意：题目保证两个人是同辈，每人只有一个性别，并且血缘关系网中没有乱伦或隔辈成婚的情况。

### 输出格式：

对每一对有情人，判断他们的关系是否可以通婚：如果两人是同性，输出`Never Mind`；如果是异性并且关系出了五服，输出`Yes`；如果异性关系未出五服，输出`No`。

### 输入样例：

```in
24
00001 M 01111 -1
00002 F 02222 03333
00003 M 02222 03333
00004 F 04444 03333
00005 M 04444 05555
00006 F 04444 05555
00007 F 06666 07777
00008 M 06666 07777
00009 M 00001 00002
00010 M 00003 00006
00011 F 00005 00007
00012 F 00008 08888
00013 F 00009 00011
00014 M 00010 09999
00015 M 00010 09999
00016 M 10000 00012
00017 F -1 00012
00018 F 11000 00013
00019 F 11100 00018
00020 F 00015 11110
00021 M 11100 00020
00022 M 00016 -1
00023 M 10012 00017
00024 M 00022 10013
9
00021 00024
00019 00024
00011 00012
00022 00018
00001 00004
00013 00016
00017 00015
00019 00021
00010 00011
```

### 输出样例：

```out
Never Mind
Yes
Never Mind
No
Yes
No
Yes
No
No
```

C++

```cpp
#include<bits/stdc++.h>

using namespace std;

struct person
{
	int id;
	char sex;
	int father;
	int mother;

	person(int _id = -1, char _sex = 'M')
		:id(_id)
		, sex(_sex)
		,father(-1)
		,mother(-1)
	{}
};

unordered_map<int, person> m;

bool Find(int id1, int id2, int cnt)
{
	if (cnt >= 4) return true;
	if (id1 == -1 || id2 == -1) return true;
	if (m[id1].father != -1 && m[id1].father == m[id2].father
		|| m[id1].mother != -1 && m[id1].mother == m[id2].mother)
		return false;
	return Find(m[id1].father, m[id2].father, cnt + 1)
		&& Find(m[id1].mother, m[id2].mother, cnt + 1)
		&& Find(m[id1].father, m[id2].mother, cnt + 1)
		&& Find(m[id1].mother, m[id2].father, cnt + 1);
 }

int main(void)
{
	
	int N, K;

	cin >> N;

	while (N--)
	{
		person p;
		cin >> p.id >> p.sex >> p.father >> p.mother;
		m[p.id] = p;
		// 创建父母亲信息，为了下面同性通婚判断使用
		// 为了避免覆盖前面我们输入的数据，仅在父母id不存在时创建
		if (p.father != -1 && m.find(p.father) == m.end())
			m[p.father] = person(p.father, 'M');
		if (p.mother != -1 && m.find(p.mother) == m.end())
			m[p.mother] = person(p.mother, 'F');
	}
	cin >> K;
	
	while (K--)
	{
		int id1, id2;
		cin >> id1 >> id2;
		if (m[id1].sex == m[id2].sex)
			cout << "Never Mind" << endl;
		else
		{
			if (Find(id1, id2, 0))
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
	}

	return 0;
}
```

