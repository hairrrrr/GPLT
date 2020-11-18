#define _CRT_SECURE_NO_WARNINGS

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

int main(void)
{
	vector<int> v(3);

	cin >> v[0] >> v[1] >> v[2];

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++)
	{
		if (i == v.size() - 1)
			cout << v[i] << endl;
		else
			cout << v[i] << "->";
	}

	return 0;
}