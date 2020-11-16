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
					// ��������
					cout << books << " " << int((double(times) / books) + 0.5) << endl;

				// ע��Ҫ�����
				m.clear();
				break;
			}
			// ����
			if (op == 'S')
				// ��ν��飬���һ�ε�ʱ��Ϊ׼����Ҫ���½ڵ�� time�������� insert��
				m[num] = time;
			// ɾ��
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