#include<bits/stdc++.h>

using namespace std;

const char* win[3] = { "ChuiZi", "JianDao", "Bu" };
int flg;

int main(void)
{
	string str;
	int K;

	cin >> K;
	cin >> str;

	while (str != "End")
	{
		if (flg++ == K)
		{
			cout << str << endl;
			flg = 0;
			// 注意这里不能 continue
		}
		else
		{
			if (str == win[0])
				cout << win[2] << endl;
			else if (str == win[1])
				cout << win[0] << endl;
			else
				cout << win[1] << endl;
		}
		cin >> str;
	}

	return 0;
}