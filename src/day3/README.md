## L1-007 念数字 (10分)

输入一个整数，输出每个数字对应的拼音。当整数为负数时，先输出`fu`字。十个数字对应的拼音如下：

```
0: ling
1: yi
2: er
3: san
4: si
5: wu
6: liu
7: qi
8: ba
9: jiu
```

### 输入格式：

输入在一行中给出一个整数，如：`1234`。

**提示：整数包括负数、零和正数。**

### 输出格式：

在一行中输出这个整数对应的拼音，每个数字的拼音之间用空格分开，行末没有最后的空格。如 `yi er san si`。

### 输入样例：

```in
-600
```

### 输出样例：

```out
fu liu ling ling
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
	const char* table[11] = {
		"ling", "yi", "er", "san", "si",
		"wu", "liu", "qi", "ba", "jiu", "fu"
	};
	
	string num;
	
	cin >> num;

	for (int i = 0; i < num.length(); i++)
	{
		if (num[i] == '-')
			cout << table[10] << " ";
		else
		{
			int j = num[i] - '0';
			if (i == num.length() - 1)
				cout << table[j] << endl;
			else 
				cout << table[j] << " ";
		}
	}

	return 0;
}
```



## L1-008 求整数段和 (10分)

给定两个整数*A*和*B*，输出从*A*到*B*的所有整数以及这些数的和。

### 输入格式：

输入在一行中给出2个整数*A*和*B*，其中−100≤*A*≤*B*≤100，其间以空格分隔。

### 输出格式：

首先顺序输出从*A*到*B*的所有整数，每5个数字占一行，每个数字占5个字符宽度，向右对齐。最后在一行中按`Sum = X`的格式输出全部数字的和`X`。

### 输入样例：

```in
-3 8
```

### 输出样例：

```out
   -3   -2   -1    0    1
    2    3    4    5    6
    7    8
Sum = 30
```

C++

```cpp
#define _CRT_SECURE_NO_WARNINGS

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
	int A, B;
	cin >> A >> B;

	int flg = 0;
	int sum = 0;
	for (int i = A; i <= B; i++)
	{
		sum += i;
		printf("%5d", i);
		if (++flg % 5 == 0)
			printf("\n");
	}
	if ((B - A + 1) % 5 == 0)
		printf("Sum = %d\n", sum);
	else
		printf("\nSum = %d\n", sum);

	return 0;
}
```



## L1-009 N个数求和 (20分)

本题的要求很简单，就是求`N`个数字的和。麻烦的是，这些数字是以有理数`分子/分母`的形式给出的，你输出的和也必须是有理数的形式。

### 输入格式：

输入第一行给出一个正整数`N`（≤100）。随后一行按格式`a1/b1 a2/b2 ...`给出`N`个有理数。题目保证所有分子和分母都在长整型范围内。另外，负数的符号一定出现在分子前面。

### 输出格式：

输出上述数字和的最简形式 —— 即将结果写成`整数部分 分数部分`，其中分数部分写成`分子/分母`，要求分子小于分母，且它们没有公因子。如果结果的整数部分为0，则只输出分数部分。

### 输入样例1：

```in
5
2/5 4/15 1/30 -2/60 8/3
```

### 输出样例1：

```out
3 1/3
```

### 输入样例2：

```
2
4/3 2/3
```

### 输出样例2：

```
2
```

### 输入样例3：

```
3
1/3 -1/6 1/8
```

### 输出样例3：

```
7/24
```

C++

**注意：**

- 结果采用 `loog long ` 存储
- 为了避免溢出，两个分数相加时对分母求最小公倍数。
- 负数不用特殊处理，直接和分子一起输入

最大公约数：GCD - 辗转辗除法

最小公倍数：LCM - 两数之积除以最大公约数

```cpp
#define _CRT_SECURE_NO_WARNINGS

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

int sum;
long N, Nume, Deno;

// 求最大公约数
inline long long GCD(long long x, long long y)
{
	if (!x || !y)	return 0;
	long long m;
	while (y)
	{
		m = x % y;
		x = y;
		y = m;
	}
	return x;
}

// 求最小公倍数
inline long long LCM(long long x, long long y, long long gcd)
{
	if (!x || !y) return 0;
	// 先 / 再 * 
	return x / gcd * y;
}

inline void simple()
{
	if (Nume == 0) return;

	long long gcd;
	while ((gcd = GCD(Nume, Deno)) != 1)
	{
		Nume /= gcd;
		Deno /= gcd;
	}
}

int main(void)
{
	cin >> N;

	while (N--)
	{
		long long nume, deno;
		// 第一次输入
		if (Deno == 0)
			scanf("%lld/%lld", &Nume, &Deno);
		else
		{
			scanf("%lld/%lld", &nume, &deno);

			long long new_deno = LCM(deno, Deno, GCD(deno, Deno));

			if (new_deno == 0)	continue;

			// 更新分子
			Nume = nume * (new_deno / deno) + Nume * (new_deno / Deno);
			//更新分母
			Deno = new_deno;
			// 化简
			simple();
		}
	}

	if (Deno == 1)
		cout << Nume << endl;
	else if (Nume > Deno)
	{
		long long integer = Nume / Deno;
		cout << integer << " ";
		cout << (Nume - integer * Deno) << "/" << Deno << endl;
	}
	else
		cout << Nume << "/" << Deno << endl;

	return 0;
}
```



找到一个很间接的程序：

```cpp
#include<bits/stdc++.h>
using namespace std;
int n,a,b,up,down=1;
char c;
int main()
{
    cin>>n;
    while(n--)
    {
        cin>>a>>c>>b;
        up=up*b+a*down;                     /*通分*/
        down*=b;
        int k=abs(__gcd(up,down));
        up/=k;                              /*约分*/
        down/=k;
    }
    if(up%down==0)cout<<up/down<<endl;      /*结果为整数*/
    else
    {
        if(up/down)cout<<up/down<<' ';      /*结果大于1*/
        cout<<up-up/down*down<<'/'<<down<<endl;
    }
    return 0;
}
```

参考：https://www.cnblogs.com/LengYun/p/12552318.html



总结：不要想的那么复杂，**先暴力，不行再优化**



## L1-010 比较大小 (10分)

本题要求将输入的任意3个整数从小到大输出。

### 输入格式:

输入在一行中给出3个整数，其间以空格分隔。

### 输出格式:

在一行中将3个整数从小到大输出，其间以“->”相连。

### 输入样例:

```in
4 2 8
```

### 输出样例:

```out
2->4->8
```

C++：

```cpp
#define _CRT_SECURE_NO_WARNINGS

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
	vector<int> v(3);
	
	cin >> v[0] >> v[1] >> v[2];

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++)
	{
		if (i == v.size() - 1)
			cout << v[i] << endl;
		else
			cout << v[i] << "->";
	}

	return 0;
}
```

