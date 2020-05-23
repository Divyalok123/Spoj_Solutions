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

int solve(int n, int* arr, int k)
{
    sort(arr, arr+k, greater<int>());
    int val = 0;
    int index = 0;
    while(val < n && index < k)
    {
        val += arr[index];
        index++;
    }

    if(val >= n)
    {
        return index;
    }
    return -1;
}

int main() {
    fast;
    int t;
    cin >> t;
    int i = 0;
    while(t--)
    {
        i++;
        int needs, friends;
        cin >> needs >> friends;
        int* canGive = new int[friends];
        for(int i = 0; i < friends; i++)
        {
            cin >> canGive[i];
        }
        cout << "Scenario #" << i << ":" << endl;
        int ans = solve(needs, canGive, friends); 
        if(ans != -1) cout << ans << endl;
        else cout << "impossible" << endl;
    }
    return 0;
}