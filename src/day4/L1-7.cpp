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