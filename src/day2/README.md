

## L1-002 打印沙漏 (20分)

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

**注意：**

- 每行前面的空格要打，后面的不用打
- 2，3 一直没过，发现是如果符号数目不足以构成一个沙漏，还是要输出一个符号，然后剩余的符号数量减去 1 再输出。

```cpp
#include<iostream>
#include<map>
#include<string>
#include<stack>
#include<vector>
#include<queue>
#include<deque>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>

using namespace std;

int countLevel(int num, int* use_num)
{
	int cnt = 0, cur_num = 1;
	while (cur_num <= num)
	{
		cnt++;
		cur_num += 2 * (2 * cnt + 1);
	}
	// 最多一层的符号数
	*use_num = cur_num - 2 * (2 * cnt + 1);
	// cnt 多加了一次
	--cnt;

	return cnt;
}

int main(void)
{
	int num;
	char ch;
	
	cin >> num >> ch;

	int use_num;// 已经使用的符号数
	int level = countLevel(num, &use_num);

	// 输入 num 为 0，level 为 -1
	if (level <= 0)
	{
		if (num <= 0)
			cout << "0" << endl;
		else
		{
			// 如果 level <= 0 但是 num 不为 0 （有可用的符号）
			// 则应该输出一个符号，并且把剩余的符号数目减去 1
			cout << ch << endl;
			cout << num - 1 << endl;
		}
		return 0;
	}

	int i;
	// 打印沙漏上半部分（包含最中间的 *）
	for (i = level; i >= 0; i--)
	{
		int space = level - i;
		while (space-- > 0)
			cout << " ";
		int ch_num = 2 * i + 1;
		while (ch_num-- > 0)
			cout << ch;
		cout << endl;
	}

	// 打印下半部分
	for (i = 1; i <= level; i++)
	{
		int space = level - i;
		while (space-- > 0)
			cout << " ";
		int ch_num = 2 * i + 1;
		while (ch_num-- > 0)
			cout << ch;
		cout << endl;
	}
	
	int left = num - use_num;
	cout << left << endl;

	return 0;
}
```



## L1-003 **个位数统计** (15分)

![](https://hairrrrr.github.io/assets/2020-11-22-2.png)

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
#include<unordered_map>
#include<unordered_set>

using namespace std;

int digit[10];

int main(void)
{
	string num;

	cin >> num;

	for (auto& e : num)
	{
		digit[e - '0']++;
	}

	for (int i = 0; i < 10; i++)
	{
		if (digit[i] != 0)
			cout << i << ":" << digit[i] << endl;
	}

	return 0;
}
```



## L1-005 考试座位号 (15分)

每个 PAT 考生在参加考试时都会被分配两个座位号，一个是试机座位，一个是考试座位。正常情况下，考生在入场时先得到试机座位号码，入座进入试机状态后，系统会显示该考生的考试座位号码，考试时考生需要换到考试座位就座。但有些考生迟到了，试机已经结束，他们只能拿着领到的试机座位号码求助于你，从后台查出他们的考试座位号码。

### 输入格式：

输入第一行给出一个正整数 *N*（≤1000），随后 *N* 行，每行给出一个考生的信息：`准考证号 试机座位号 考试座位号`。其中`准考证号`由 16 位数字组成，座位从 1 到 *N* 编号。输入保证每个人的准考证号都不同，并且任何时候都不会把两个人分配到同一个座位上。

考生信息之后，给出一个正整数 *M*（≤*N*），随后一行中给出 *M* 个待查询的试机座位号码，以空格分隔。

### 输出格式：

对应每个需要查询的试机座位号码，在一行中输出对应考生的准考证号和考试座位号码，中间用 1 个空格分隔。

### 输入样例：

```in
4
3310120150912233 2 4
3310120150912119 4 1
3310120150912126 1 3
3310120150912002 3 2
2
3 4
```

### 输出样例：

```out
3310120150912002 2
3310120150912119 1
```



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
#include<unordered_map>
#include<unordered_set>

using namespace std;


int main(void)
{
	unordered_map<int, pair<string, int>> m;
	int N, M;
	
	cin >> N;

	while (N--)
	{
		pair<string, int> p;
		int test;
		
		cin >> p.first >> test >> p.second;
		m[test] = p;
	}
	
	cin >> N;
	while (N--)
	{
		int test;
		cin >> test;
		cout << m[test].first << " " << m[test].second << endl;
	}

	return 0;
}
```



## L1-006 连续因子 (20分)

一个正整数 *N* 的因子中可能存在若干连续的数字。例如 630 可以分解为 3×5×6×7，其中 5、6、7 就是 3 个连续的数字。给定任一正整数 *N*，要求编写程序求出最长连续因子的个数，并输出最小的连续因子序列。

### 输入格式：

输入在一行中给出一个正整数 *N*（1<*N*<2^31）。

### 输出格式：

首先在第 1 行输出最长连续因子的个数；然后在第 2 行中按 `因子1*因子2*……*因子k` 的格式输出最小的连续因子序列，其中因子按递增顺序输出，1 不算在内。

### 输入样例：

```in
630
```

### 输出样例：

```out
3
5*6*7
```



C++

**注意：**

- 如果只有一个因子，则输出最小的
- **第六个点运行超时** ::question::question::question:

```cpp
#include<iostream>
#include<map>
#include<string>
#include<stack>
#include<vector>
#include<queue>
#include<deque>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>

using namespace std;

bool isPrime(int n)
{
	if (n == 1) return false;
	if (n == 2 || n == 3) return true;
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0)
			return false;
	return true;
}

// 连续因子的区间 [L,R)
int L, R;

int main(void)
{
	int N;
	cin >> N;
	
	// 素数输出本身即可
	if (isPrime(N))
	{
		cout << 1 << endl << N << endl;
		return 0;
	}
	
	// i 为连续因式左端点，左端点一定小于 根号 N
	// 但是还是要写 <= ，如果不写，考虑 9 的情况
	for (int i = 2; i * i <= N; i++)
	{
		int j = i;
		int n = N;
		while (n % j == 0)
		{
			n /= j;
			j++;
		}
		
		if (j - i > R - L)
		{
			L = i;
			R = j;
		}
	}

	cout << R - L << endl;
	for (int i = L; i <= R - 1; i++)
	{
		if (i == R - 1)
			cout << i << endl;
		else 
			cout << i << "*";
	}

	return 0;
}
```

