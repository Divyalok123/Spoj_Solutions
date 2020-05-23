#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>
#include <unordered_map>
#include <iomanip>
#include <stdexcept>
#include <stack>
#include <queue>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
#define ll long long
#define uint unsigned int
#define endl "\n"
#define setbits(x) __builtin_popcountll(x) // returns no. of set bits (for GCC compiler.. Much faster) 
typedef priority_queue<int> maxheap;
typedef priority_queue<int, vector<int>, greater<int>> minheap; 


int main() 
{
    fast;
    int t;
    cin >> t;
    while(t--)
    {
        ll x, y, z; //z == sum
        cin >> x >> y >> z;

        ll n = (2*z)/(x+y); //no. of elements
        ll d = (y-x)/(n-5); //diff
        ll a = (x - (2*d)); // first element

        cout << n << endl;
        int i = 0;
        while(i < n)
        {
            cout << a + (i*d) << " ";
            i++;
        }
        cout << endl;
    }

    return 0;
}