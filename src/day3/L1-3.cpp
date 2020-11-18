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
	if (!x || !y)
		return 0;
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
	if (!x || !y)
		return 0;
	// 先 / 再 * 
	return x / gcd * y;
}

inline void simple()
{
	if (Nume == 0)
		return;
	long long gcd;

	// 除去负号
	int flg = 0;
	if (Nume < 0)
	{
		flg = 1;
		Nume *= -1;
	}

	while ((gcd = GCD(Nume, Deno)) != 1)
	{
		Nume /= gcd;
		Deno /= gcd;
	}

	if (flg)
		Nume *= -1;
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

			if (new_deno == 0)
				continue;

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
		int flg = 0;
		if (Nume < 0)
		{
			flg = 1;
			Nume *= -1;
		}

		long long integer = Nume / Deno;

		if (flg)
		{
			integer *= -1;
			Nume *= -1;
		}

		cout << integer << " ";
		cout << (Nume - integer * Deno) << "/" << Deno << endl;
	}
	else
		cout << Nume << "/" << Deno << endl;

	return 0;
}

// 找到一个很简洁的程序
#include<bits/stdc++.h>
using namespace std;
int n, a, b, up, down = 1;
char c;
int main()
{
	cin >> n;
	while (n--)
	{
		cin >> a >> c >> b;
		up = up * b + a * down;                     /*通分*/
		down *= b;
		int k = abs(__gcd(up, down));
		up /= k;                              /*约分*/
		down /= k;
	}
	if (up % down == 0)cout << up / down << endl;      /*结果为整数*/
	else
	{
		if (up / down)cout << up / down << ' ';      /*结果大于1*/
		cout << up - up / down * down << '/' << down << endl;
	}
	return 0;
}
