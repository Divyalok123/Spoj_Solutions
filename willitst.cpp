#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <unordered_map>
#include <iomanip>
#include <stack>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
#define ll long long
#define uint unsigned int
#define endl "\n"

// In this we need to check if n is a power of 2 or not
// A little modification of collatz conjecture

//or

//we can maintain a set and check if a number appears again

int main()
{
    fast;
    ll n;
    cin >> n;
    if (n <= 1 || ((n & (n - 1)) == 0)) 
    {
        cout << "TAK" << endl;
    }
    else
    {
        cout << "NIE" << endl;
    }

    return 0;
}