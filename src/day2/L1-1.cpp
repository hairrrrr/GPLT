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