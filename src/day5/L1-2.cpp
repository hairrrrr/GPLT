#include<bits/stdc++.h>

using namespace std;

int main(void)
{
	int N;
	char ch;
	cin >> N >> ch;

	int row, col = N;
	row = (double)N / 2 + 0.5;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			cout << ch;
		cout << endl;
	}
}