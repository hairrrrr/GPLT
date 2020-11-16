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
	// 下一次入栈的元素

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
				// 限制栈的大小
				if (s.size() == size)
					break;
				s.push(next_in++);
			}

			if (next_in > elem_num)
			{
				cout << "NO" << endl;
				break;
			}
			// 如果还有元素没有入栈而当前栈已满
			else if (s.size() == size)
			{
				cout << "NO" << endl;
				break;
			}
			else
				// next_in 入栈出栈，下一个入栈的是下一位
				next_in++;
		}
		// 退出 while 可能是内部 break 或 seq 为空
		if (seq.empty())
			cout << "YES" << endl;
	}
	return 0;
}