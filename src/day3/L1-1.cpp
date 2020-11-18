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
	const char* table[11] = {
		"ling", "yi", "er", "san", "si",
		"wu", "liu", "qi", "ba", "jiu", "fu"
	};

	string num;

	cin >> num;

	for (int i = 0; i < num.length(); i++)
	{
		if (num[i] == '-')
			cout << table[10] << " ";
		else
		{
			int j = num[i] - '0';
			if (i == num.length() - 1)
				cout << table[j] << endl;
			else
				cout << table[j] << " ";
		}
	}

	return 0;
}