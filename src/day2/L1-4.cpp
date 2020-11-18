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

// �������ӵ����� [L,R)
int L, R;

int main(void)
{
	int N;
	cin >> N;

	// �������������
	if (isPrime(N))
	{
		cout << 1 << endl << N << endl;
		return 0;
	}

	// i Ϊ������ʽ��˵㣬��˵�һ��С�� ���� N
	// ���ǻ���Ҫд <= �������д������ 9 �����
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