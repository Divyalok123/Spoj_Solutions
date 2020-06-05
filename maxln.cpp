#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    int cas = 1;
    while(t--)
    {
        int n; 
        cin >> n;
        cout << "Case " << cas << ": ";
        long long dai = (long long)(2*n)*(2*n);
        cout << dai << ".25" << endl;
        cas++;
    }

    

    return 0;
}