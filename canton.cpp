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

void solve(int n)
{
    int val = 1;
    int i = 1;
    int j = 1;

    while (val < n)
    {
        val++;
        i++;

        if (val == n)
        {
            break;
        }

        while (i > 1 && val < n)
        {
            i--;
            j++;
            val++;
        }

        if (val == n)
        {
            break;
        }

        j++;
        val++;

        if(val == n)
        {
            break;
        }

        while (j > 1 && val < n)
        {
            j--;
            i++;
            val++;
        }
    }
    cout << "TERM " << n << " IS " << j << "/" << i << endl;
}

int main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        solve(n);
    }
    return 0;
}