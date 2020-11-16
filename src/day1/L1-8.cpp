#include<iostream>
#include<map>
#include<string>

using namespace std;

int main(void)
{
	map<int, int> m;
	int day, num, hour, min;
	char op;

	cin >> day;
	if (day <= 0)
	{
		cout << "0 0" << endl;
		return 0;
	}
	while (day--)
	{
		int books = 0, times = 0;
		while (1)
		{
			cin >> num >> op;
			scanf("%d:%d", &hour, &min);
			int time = hour * 60 + min;
			if (num == 0)
			{
				if (books == 0)
					cout << "0 0" << endl;
				else
					// 四舍五入
					cout << books << " " << int((double(times) / books) + 0.5) << endl;

				// 注意要清空树
				m.clear();
				break;
			}
			// 插入
			if (op == 'S')
				// 多次借书，最后一次的时间为准（需要更新节点的 time，不能用 insert）
				m[num] = time;
			// 删除
			else
			{
				auto it = m.find(num);
				if (it != m.end())
				{
					books++;
					times += time - it->second;
				}
			}
		}
	}

	return 0;
}