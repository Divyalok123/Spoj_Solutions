#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    n %= 10;
    if(n == 0) cout << 2 << endl;
    else 
    {
        cout << 1 << endl << n << endl;
    }

    return 0;   
}