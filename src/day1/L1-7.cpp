#include<iostream>
#include<string>

using namespace std;

/*
 * 0 和 1 都不是素数
 * 2 是唯一的偶素数
 */
bool isprime(int dig)
{
	if (dig == 0 || dig == 1)
		return false;
	if (dig == 2)
		return true;
	for (int i = 2; i * i <= dig; i++)
		if (dig % i == 0)
			return false;
	return true;
}

int main(void)
{
	string dig;
	int dignum, num; // dignum --》L，num --》K
	cin >> dignum >> num;
	cin >> dig;

	int i;
	int beg;

	// 下面的 for 循环的控制语句是 i + num <= dignum 
	// 前提是我们假设 num 是大于 0 的。如果 num 小于 0，
	// 会存在越界情况 i (+ 0) == dignum
	if (num == 0)
	{
		cout << "404" << endl;
		return 0;
	}

	for (i = 0; i + num <= dignum; i++)
	{
		string sub = dig.substr(i, num);
		int sub_i = stoi(sub, nullptr, 10);
		if (isprime(sub_i))
		{
			cout << sub << endl;
			return 0;
		}
	}

	cout << "404" << endl;

	return 0;
}