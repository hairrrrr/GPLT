## 7-11 图着色问题 (25分)

图着色问题是一个著名的NP完全问题。给定无向图*G*=(*V*,*E*)，问可否用*K*种颜色为*V*中的每一个顶点分配一种颜色，使得不会有两个相邻顶点具有同一种颜色？

但本题并不是要你解决这个着色问题，而是对给定的一种颜色分配，请你判断这是否是图着色问题的一个解。

### 输入格式：

输入在第一行给出3个整数*V*（0<*V*≤500）、*E*（≥0）和*K*（0<*K*≤*V*），分别是无向图的顶点数、边数、以及颜色数。顶点和颜色都从1到*V*编号。随后*E*行，每行给出一条边的两个端点的编号。在图的信息给出之后，给出了一个正整数*N*（≤20），是待检查的颜色分配方案的个数。随后*N*行，每行顺次给出*V*个顶点的颜色（第*i*个数字表示第*i*个顶点的颜色），数字间以空格分隔。题目保证给定的无向图是合法的（即不存在自回路和重边）。

### 输出格式：

对每种颜色分配方案，如果是图着色问题的一个解则输出`Yes`，否则输出`No`，每句占一行。

### 输入样例：

```in
6 8 3
2 1
1 3
4 6
2 5
2 4
5 4
5 6
3 6
4
1 2 3 3 1 2
4 5 6 6 4 5
1 2 3 4 5 6
2 3 4 2 3 4
```

### 输出样例：

```out
Yes
Yes
No
No
```

C++

**注意：**

- 如果一个循环里有 `cin`，那么不能 break 这个循环
- 颜色的个数一定要等于 K （大于小于都不行）

思路：首先创建无向图的邻接矩阵。然后根据输入的颜色组合从第个一顶点开始找与之相连（二维数组的一行，但是只用找到副对角线处即可，因为无向图的邻接矩阵是对称的）的顶点，找到后判断两个顶点的颜色是否一样，如果一样，则该颜色组合非法。

```cpp
#include<bits/stdc++.h>
#include<limits.h>

using namespace std;

int Map[501][501];
int flg;

int main(void)
{
	int V, E, K;
	cin >> V >> E >> K;
	
	while (E--)
	{
		int a, b;
		cin >> a >> b;
		Map[a][b] = Map[b][a] = 1;
	}

	int N;
	cin >> N;
	while (N--)
	{
		int color[501] = { 0 };
		set<int> just;
		flg = 0;

		for (int i = 1; i <= V; i++)
		{
			cin >> color[i];
			just.insert(color[i]);
			if (just.size() > K)
			{
				flg = 1;
				// 此处不能 break，因为这个循环里有 cin 
				// break;
			}
		}

		if (just.size() != K)
		{
			flg = 1;
			goto end;
		}
		
		for (int i = 1; i <= V; i++)
		{
			// 只判断到矩阵的副对角线位置
			int max = i;
			for (int j = 1; j < max; j++)
			{
				if (Map[i][j] != 0 && color[i] == color[j])
				{
					flg = 1;
					break;
				}
			}
			if (flg)
				break;
		}
end:
		if (flg)
			cout << "No" << endl;
		else
			cout << "Yes" << endl;
	}

	return 0;
}
```





## 7-12 月饼 (25分)

月饼是中国人在中秋佳节时吃的一种传统食品，不同地区有许多不同风味的月饼。现给定所有种类月饼的库存量、总售价、以及市场的最大需求量，请你计算可以获得的最大收益是多少。

注意：销售时允许取出一部分库存。样例给出的情形是这样的：假如我们有 3 种月饼，其库存量分别为 18、15、10 万吨，总售价分别为 75、72、45 亿元。如果市场的最大需求量只有 20 万吨，那么我们最大收益策略应该是卖出全部 15 万吨第 2 种月饼、以及 5 万吨第 3 种月饼，获得 72 + 45/2 = 94.5（亿元）。

### 输入格式：

每个输入包含一个测试用例。每个测试用例先给出一个不超过 1000 的正整数 *N* 表示月饼的种类数、以及不超过 500（以万吨为单位）的正整数 *D* 表示市场最大需求量。随后一行给出 *N* 个正数表示每种月饼的库存量（以万吨为单位）；最后一行给出 *N* 个正数表示每种月饼的总售价（以亿元为单位）。数字间以空格分隔。

### 输出格式：

对每组测试用例，在一行中输出最大收益，以亿元为单位并精确到小数点后 2 位。

### 输入样例：

```in
3 20
18 15 10
75 72 45
```

### 输出样例：

```out
94.50
```

C++

**注意**

- 题目没有说变量类型一律按 `double` 处理
- 市场最大需求量 D 可能会小于持有的总货量（最后的 while 循环需要判断两个条件，否则会出现段错误）

```cpp
#include<bits/stdc++.h>
#include<limits.h>

using namespace std;

struct good
{
	double num;
	double price;
	double profit;
}goods[1001];

int main(void)
{
	int N, D;
	cin >> N >> D;

	for (int i = 0; i < N; i++)
		cin >> goods[i].num;
	for (int i = 0; i < N; i++)
		cin >> goods[i].price;
	for (int i = 0; i < N; i++)
		goods[i].profit = goods[i].price / goods[i].num;
	
	sort(goods, goods + N, [](const good& lhs, const good& rhs)-> bool
		{return lhs.profit > rhs.profit; });

	double best = 0;
	int i = 0;
	while (D > 0 && i < N)
	{
		int cnt = D > goods[i].num ? goods[i].num : D;
		if (cnt == goods[i].num)
			best += goods[i].price;
		else
			best += D / goods[i].num * goods[i].price;
		
		D -= cnt;
		i++;
	}

	printf("%.2f\n", best);
	

	return 0;
}
```





## L1-013 计算阶乘和 (10分)

对于给定的正整数*N*，需要你计算 *S*=1!+2!+3!+...+*N*!。

### 输入格式：

输入在一行中给出一个不超过10的正整数*N*。

### 输出格式：

在一行中输出*S*的值。

### 输入样例：

```in
3
```

### 输出样例：

```out
9
```

C++

```cpp
#include<bits/stdc++.h>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    int sum = 0;
    int now = 1;
    for(int i = 1; i <= n; i++)
    {
        now *= i;
        sum += now;
    }
    cout << sum << endl;
}
```



## L1-015 跟奥巴马一起画方块 (15分)

美国总统奥巴马不仅呼吁所有人都学习编程，甚至以身作则编写代码，成为美国历史上首位编写计算机代码的总统。2014年底，为庆祝“计算机科学教育周”正式启动，奥巴马编写了很简单的计算机代码：在屏幕上画一个正方形。现在你也跟他一起画吧！

### 输入格式：

输入在一行中给出正方形边长*N*（3≤*N*≤21）和组成正方形边的某种字符`C`，间隔一个空格。

### 输出格式：

输出由给定字符`C`画出的正方形。但是注意到行间距比列间距大，所以为了让结果看上去更像正方形，我们输出的行数实际上是列数的50%（四舍五入取整）。

### 输入样例：

```in
10 a
```

### 输出样例：

```out
aaaaaaaaaa
aaaaaaaaaa
aaaaaaaaaa
aaaaaaaaaa
aaaaaaaaaa
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

	int row, col = N;
	row = (double)N / 2 + 0.5;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			cout << ch;
		cout << endl;
	}
}
```



## L1-016 查验身份证 (15分)

一个合法的身份证号码由17位地区、日期编号和顺序编号加1位校验码组成。校验码的计算规则如下：

首先对前17位数字加权求和，权重分配为：{7，9，10，5，8，4，2，1，6，3，7，9，10，5，8，4，2}；然后将计算的和对11取模得到值`Z`；最后按照以下关系对应`Z`值与校验码`M`的值：

```
Z：0 1 2 3 4 5 6 7 8 9 10
M：1 0 X 9 8 7 6 5 4 3 2
```

现在给定一些身份证号码，请你验证校验码的有效性，并输出有问题的号码。

### 输入格式：

输入第一行给出正整数*N*（≤100）是输入的身份证号码的个数。随后*N*行，每行给出1个18位身份证号码。

### 输出格式：

按照输入的顺序每行输出1个有问题的身份证号码。这里并不检验前17位是否合理，只检查前17位是否全为数字且最后1位校验码计算准确。如果所有号码都正常，则输出`All passed`。

### 输入样例1：

```in
4
320124198808240056
12010X198901011234
110108196711301866
37070419881216001X
```

### 输出样例1：

```out
12010X198901011234
110108196711301866
37070419881216001X
```

### 输入样例2：

```
2
320124198808240056
110108196711301862
```

### 输出样例2：

```
All passed
```

### 123

C++

```cpp
#include<bits/stdc++.h>

using namespace std;

const int table[] = { 7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2 };
const char M[] = { '1' ,'0' ,'X' ,'9' ,'8' ,'7' ,'6' ,'5' ,'4' ,'3' ,'2' };

int main(void)
{
	int N;
	cin >> N;
	int cnt = 0;
	while (N--)
	{
		string num;
		cin >> num;
		int flg = 0;
		long long judge = 0;
		for (int i = 0; i < 18; i++)
		{
			if (i == 17)
			{
				judge %= 11;
				if (M[judge] != num[i])
					flg = 1;
			}
			else
			{
				if (!isdigit(num[i]))
					flg = 1;
				judge += (num[i] - '0') * table[i];
			}
		}
		if (flg)
		{
			cout << num << endl;
			cnt = 1;
		}
	}
	if (!cnt)
		cout << "All passed" << endl;
}
```








