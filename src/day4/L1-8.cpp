#include<bits/stdc++.h>

using namespace std;

int main(void)
{
	unordered_set<char> s;
	string A, B;
	getline(cin, A);
	getline(cin, B);

	for (auto& e : B)
	{
		s.insert(e);
	}

	for (auto& e : A)
	{
		if (s.find(e) == s.end())
			cout << e;
	}
	cout << endl;

	return 0;
}