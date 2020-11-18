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

int digit[10];

int main(void)
{
	string num;

	cin >> num;

	for (auto& e : num)
	{
		digit[e - '0']++;
	}

	for (int i = 0; i < 10; i++)
	{
		if (digit[i] != 0)
			cout << i << ":" << digit[i] << endl;
	}

	return 0;
}