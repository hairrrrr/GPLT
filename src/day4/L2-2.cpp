#include<bits/stdc++.h>

using namespace std;

struct person
{
	int id;
	char sex;
	int father;
	int mother;

	person(int _id = -1, char _sex = 'M')
		:id(_id)
		, sex(_sex)
		, father(-1)
		, mother(-1)
	{}
};

unordered_map<int, person> m;

bool Find(int id1, int id2, int cnt)
{
	if (cnt >= 4) return true;
	if (id1 == -1 || id2 == -1) return true;
	if (m[id1].father != -1 && m[id1].father == m[id2].father
		|| m[id1].mother != -1 && m[id1].mother == m[id2].mother)
		return false;
	return Find(m[id1].father, m[id2].father, cnt + 1)
		&& Find(m[id1].mother, m[id2].mother, cnt + 1)
		&& Find(m[id1].father, m[id2].mother, cnt + 1)
		&& Find(m[id1].mother, m[id2].father, cnt + 1);
}

int main(void)
{

	int N, K;

	cin >> N;

	while (N--)
	{
		person p;
		cin >> p.id >> p.sex >> p.father >> p.mother;
		m[p.id] = p;
		// 创建父母亲信息，为了下面同性通婚判断使用
		// 为了避免覆盖前面我们输入的数据，仅在父母id不存在时创建
		if (p.father != -1 && m.find(p.father) == m.end())
			m[p.father] = person(p.father, 'M');
		if (p.mother != -1 && m.find(p.mother) == m.end())
			m[p.mother] = person(p.mother, 'F');
	}
	cin >> K;

	while (K--)
	{
		int id1, id2;
		cin >> id1 >> id2;
		if (m[id1].sex == m[id2].sex)
			cout << "Never Mind" << endl;
		else
		{
			if (Find(id1, id2, 0))
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
	}

	return 0;
}