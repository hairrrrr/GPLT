#include<bits/stdc++.h>

using namespace std;

int  main(void)
{
    int n;
    cin >> n;
    // (n - 1) % 7 + 1 ½« 1 ~ 7 Ó³ÉäÎª 0 ~ 6
    // (n + 1) --> (n - 1 + 2)
    cout << ((n + 1) % 7 + 1) << endl;

    return 0;
}