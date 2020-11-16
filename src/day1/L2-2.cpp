#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<map>
#include<string>
#include<stack>
#include<vector>
#include<queue>
#include<deque>
#include<algorithm>

using namespace std;

struct packet
{
	int id;
	int income;
	int p_num; // ºì°ü¸öÊı

	packet() = default;

	packet(const int& _id)
		:id(_id)
		, income(0)
		, p_num(0)
	{}
};

int main(void)
{
	map<int, packet> p;
	int N;

	cin >> N;

	for (int i = 1; i <= N; i++)
		p.insert(make_pair(i, packet(i)));

	for (int i = 1; i <= N; i++)
	{
		int send_num, get_id, get_num;

		cin >> send_num;
		while (send_num--)
		{
			cin >> get_id >> get_num;
			p[i].income -= get_num;
			p[get_id].income += get_num;
			p[get_id].p_num++;
		}
	}

	vector<packet> v;

	for (auto& e : p)
	{
		v.push_back(e.second);
	}


	sort(v.begin(), v.end(), [](const packet& lhs, const packet& rhs)-> bool {
		if (lhs.income != rhs.income)
			return lhs.income > rhs.income;
		else
		{
			if (lhs.p_num != rhs.p_num)
				return lhs.p_num > rhs.p_num;
			else
				return lhs.id < rhs.id;
		}
		});

	for (auto& e : v)
	{
		printf("%d %.2f\n", e.id, e.income / 100.0);
	}

	return 0;
}