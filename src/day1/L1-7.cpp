#include<iostream>
#include<string>

using namespace std;

/*
 * 0 �� 1 ����������
 * 2 ��Ψһ��ż����
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
	int dignum, num; // dignum --��L��num --��K
	cin >> dignum >> num;
	cin >> dig;

	int i;
	int beg;

	// ����� for ѭ���Ŀ�������� i + num <= dignum 
	// ǰ�������Ǽ��� num �Ǵ��� 0 �ġ���� num С�� 0��
	// �����Խ����� i (+ 0) == dignum
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