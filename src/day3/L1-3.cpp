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

// �����Լ��
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

// ����С������
inline long long LCM(long long x, long long y, long long gcd)
{
	if (!x || !y)
		return 0;
	// �� / �� * 
	return x / gcd * y;
}

inline void simple()
{
	if (Nume == 0)
		return;
	long long gcd;

	// ��ȥ����
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
		// ��һ������
		if (Deno == 0)
			scanf("%lld/%lld", &Nume, &Deno);
		else
		{
			scanf("%lld/%lld", &nume, &deno);

			long long new_deno = LCM(deno, Deno, GCD(deno, Deno));

			if (new_deno == 0)
				continue;

			// ���·���
			Nume = nume * (new_deno / deno) + Nume * (new_deno / Deno);
			//���·�ĸ
			Deno = new_deno;
			// ����
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

// �ҵ�һ���ܼ��ĳ���
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
		up = up * b + a * down;                     /*ͨ��*/
		down *= b;
		int k = abs(__gcd(up, down));
		up /= k;                              /*Լ��*/
		down /= k;
	}
	if (up % down == 0)cout << up / down << endl;      /*���Ϊ����*/
	else
	{
		if (up / down)cout << up / down << ' ';      /*�������1*/
		cout << up - up / down * down << '/' << down << endl;
	}
	return 0;
}
