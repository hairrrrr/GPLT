#include<bits/stdc++.h>

using namespace std;

int main(void)
{
	int n;
	cin >> n;

	while (n--)
	{
		string name;
		int breath, palse;
		cin >> name >> breath >> palse;
		if (breath < 15 || breath > 20 || palse < 50 || palse > 70)
			cout << name << endl;
		else
			continue;
	}

	return 0;
}