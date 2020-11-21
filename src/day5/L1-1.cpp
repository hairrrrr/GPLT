#include<bits/stdc++.h>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    int sum = 0;
    int now = 1;
    for (int i = 1; i <= n; i++)
    {
        now *= i;
        sum += now;
    }
    cout << sum << endl;
}