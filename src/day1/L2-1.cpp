#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<map>
#include<string>
#include<stack>
#include<vector>
#include<queue>
#include<deque>

using namespace std;

int main(void)
{
	int size, elem_num, seq_num;

	cin >> size >> elem_num >> seq_num;

	int n = seq_num;
	// ��һ����ջ��Ԫ��

	while (n--)
	{
		queue<int> seq;
		stack<int> s;
		int next_in = 1;

		int i;
		for (i = 0; i < elem_num; i++)
		{
			int elem;
			cin >> elem;
			seq.push(elem);
		}

		while (!seq.empty())
		{
			int elem = seq.front();
			seq.pop();

			if (!s.empty() && s.top() == elem)
			{
				s.pop();
				continue;
			}

			while (next_in <= elem_num && next_in != elem)
			{
				// ����ջ�Ĵ�С
				if (s.size() == size)
					break;
				s.push(next_in++);
			}

			if (next_in > elem_num)
			{
				cout << "NO" << endl;
				break;
			}
			// �������Ԫ��û����ջ����ǰջ����
			else if (s.size() == size)
			{
				cout << "NO" << endl;
				break;
			}
			else
				// next_in ��ջ��ջ����һ����ջ������һλ
				next_in++;
		}
		// �˳� while �������ڲ� break �� seq Ϊ��
		if (seq.empty())
			cout << "YES" << endl;
	}
	return 0;
}