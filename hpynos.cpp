#include <iostream>
#include <cmath>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;
#define uint unsigned int

bool arr[1000];

uint square_of_digits(uint n)
{
    uint ans = 0;
    while(n)
    {
        uint x = n%10;
        ans += x*x;
        n/=10;
    }
    return ans;
}

void solve(uint n)
{
    if(n == 1) cout << 0 << endl;
    int count = 0;
    n = square_of_digits(n);
    while(n!=1 && !arr[n])
    {
        arr[n] = true;
        count++;
        n = square_of_digits(n);
    }

    if(n == 1) cout << count << endl;
    else cout << -1 << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    memset(arr, false, sizeof(arr));
    uint n;
    cin >> n;

    solve(n);
    return 0;
}