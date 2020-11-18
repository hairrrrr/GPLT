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
	// ���һ��ķ�����
	*use_num = cur_num - 2 * (2 * cnt + 1);
	// cnt �����һ��
	--cnt;

	return cnt;
}

int main(void)
{
	int num;
	char ch;

	cin >> num >> ch;

	int use_num;// �Ѿ�ʹ�õķ�����
	int level = countLevel(num, &use_num);

	// ���� num Ϊ 0��level Ϊ -1
	if (level <= 0)
	{
		if (num <= 0)
			cout << "0" << endl;
		else
		{
			// ��� level <= 0 ���� num ��Ϊ 0 ���п��õķ��ţ�
			// ��Ӧ�����һ�����ţ����Ұ�ʣ��ķ�����Ŀ��ȥ 1
			cout << ch << endl;
			cout << num - 1 << endl;
		}
		return 0;
	}

	int i;
	// ��ӡɳ©�ϰ벿�֣��������м�� *��
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

	// ��ӡ�°벿��
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