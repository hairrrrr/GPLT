#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<map>
#include<string>
#include<stack>
#include<vector>
#include<queue>
#include<deque>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>

using namespace std;

int main(void)
{
	int A, B;
	cin >> A >> B;

	int flg = 0;
	int sum = 0;
	for (int i = A; i <= B; i++)
	{
		sum += i;
		printf("%5d", i);
		if (++flg % 5 == 0)
			printf("\n");
	}
	if ((B - A + 1) % 5 == 0)
		printf("Sum = %d\n", sum);
	else
		printf("\nSum = %d\n", sum);

	return 0;
}

