#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        unsigned long long int n;
        cin >> n;
        unsigned long long int a = n*(n+2)*(2*n+1)/8;
        cout << a << endl;
    }
    return 0;
}