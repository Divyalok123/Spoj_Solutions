#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>
#include <unordered_map>
#include <iomanip>
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

int main() {
    fast;
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        if(next_permutation(arr.begin(), arr.end()))
        {
            for(int i = 0; i < n; i++)
            {
                cout << arr[i];
            }
            cout << endl;
        }
        else
        {
            cout << -1 << endl;
        }
        
    }
    return 0;
}