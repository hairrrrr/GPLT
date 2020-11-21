#include<bits/stdc++.h>

using namespace std;

const int table[] = { 7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2 };
const char M[] = { '1' ,'0' ,'X' ,'9' ,'8' ,'7' ,'6' ,'5' ,'4' ,'3' ,'2' };

int main(void)
{
	int N;
	cin >> N;
	int cnt = 0;
	while (N--)
	{
		string num;
		cin >> num;
		int flg = 0;
		long long judge = 0;
		for (int i = 0; i < 18; i++)
		{
			if (i == 17)
			{
				judge %= 11;
				if (M[judge] != num[i])
					flg = 1;
			}
			else
			{
				if (!isdigit(num[i]))
					flg = 1;
				judge += (num[i] - '0') * table[i];
			}
		}
		if (flg)
		{
			cout << num << endl;
			cnt = 1;
		}
	}
	if (!cnt)
		cout << "All passed" << endl;
}