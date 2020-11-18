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
	unordered_map<int, pair<string, int>> m;
	int N, M;

	cin >> N;

	while (N--)
	{
		pair<string, int> p;
		int test;

		cin >> p.first >> test >> p.second;
		m[test] = p;
	}

	cin >> N;
	while (N--)
	{
		int test;
		cin >> test;
		cout << m[test].first << " " << m[test].second << endl;
	}

	return 0;
}