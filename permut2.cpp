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
    int n;
    cin >> n;
    string right = "ambiguous";
    string wrong = "not ambiguous";
    while(n != 0)
    {
        int* arr = new int[n];
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        bool flag = true;
        for(int i = 0; i < n; i++)
        {
            if(arr[arr[i]-1] != i+1)
            {
                flag = false;
                break;
            }
        }

        if(flag) cout << right << endl;
        else cout << wrong << endl;
        cin >> n;
    }
    return 0;
}