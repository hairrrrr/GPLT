#include<bits/stdc++.h>

using namespace std;

int main(void)
{
	int N;
	char ch;
	string str;

	cin >> N >> ch;
	getchar();
	getline(cin, str);

	if (str.size() > N)
		cout << str.substr(str.size() - N, N) << endl;
	else if (str.size() == N)
		cout << str << endl;
	else
	{
		for (int i = 0; i < N - str.size(); i++)
			cout << ch;
		cout << str << endl;
	}

	return 0;
}