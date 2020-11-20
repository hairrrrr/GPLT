#include<bits/stdc++.h>

using namespace std;

int main(void)
{
	int N;
	cin >> N;

	while (N--)
	{
		string num;
		cin >> num;
		if (num[0] + num[1] + num[2] == num[3] + num[4] + num[5])
			cout << "You are lucky!" << endl;
		else
			cout << "Wish you good luck." << endl;
	}

	return 0;
}