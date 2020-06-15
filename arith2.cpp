#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
using namespace std;

long long solve(long long a, char x, long long b){
    if(x == '*') return a*b;
    if(x == '/') return a/b;
    if(x == '+') return a + b;
    if(x == '-') return a-b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        cout << endl;
        long long a, b;
        char x;

        cin >> a >> x >> b;
        while(1)
        {
            a = solve(a, x, b);
            cin >> x;
            if(x == '=') break;
            cin >> b;
        }
        cout << a << endl;
    }

    return 0;
}
