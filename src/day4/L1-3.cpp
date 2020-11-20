#include<bits/stdc++.h>

using namespace std;

int main(void)
{
	double wei, hei;

	cin >> wei >> hei;

	double res = wei / (hei * hei);
	printf("%.1f\n", res);

	if (res > 25)
		cout << "PANG" << endl;
	else
		cout << "Hai Xing" << endl;

	return 0;
}