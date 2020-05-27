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
#include <vector>
#include <list>

using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define endl "\n"
#define setbits(x) __builtin_popcountll(x) // returns no. of set bits (for GCC compiler.. Much faster) 
typedef priority_queue<int> maxheap;
typedef priority_queue<int, vector<int>, greater<int>> minheap; 

int store[1000][1000];

//memo
// int solve(int** arr, int r, int c, int i, int j)
// {
//     if(i >= r || j < 0 || j >= c)
//     {
//         return 0;
//     }

//     if(store[i][j] != 0) return store[i][j];
//     int a = arr[i][j] + solve(arr, r, c, i+1, j-1);
//     int b = arr[i][j] + solve(arr, r, c, i+1, j+1);
//     int d = arr[i][j] + solve(arr, r, c, i+1, j);
//     int maxx = max(a, max(b, d));
//     store[i][j] = maxx;
//     return maxx;
// }

//dp
int solve(int** arr, int r, int c)
{
    for(int i = 0; i < c; i++)
    {
        store[0][i+1] = arr[0][i];
    }

    for(int i = 1; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            store[i][j+1] = arr[i][j] + max(store[i-1][j+1], max(store[i-1][j], store[i-1][j+2]));
        }
    }

    int maxx = 0;
    for(int i = 0; i < c; i++)
    {
        if(store[r-1][i+1] > maxx)
        {
            maxx = store[r-1][i+1];
        }
    }

    return maxx;
}

int main()
{ 
    fast;
    int t;
    cin >> t;
    while(t--)
    {
        int r, c;
        cin >> r >> c;
        memset(store, 0, sizeof(store));
        int** arr = new int*[r];
        for(int i = 0; i < r; i++)
        {
            arr[i] = new int[c];
            for(int j = 0; j < c; j++)
            {
                cin >> arr[i][j];
            }
        }
        //for memo
        // int maxx = 0;
        // int ans = 0;
        // for(int i = 0; i < c; i++)
        //     ans = max(ans, solve(arr, r, c, 0, i));

        //for dp
        int ans = solve(arr, r, c);
        cout << ans << endl;
        for(int i = 0; i < r; i++)
        {
            delete[] arr[i];
        }
        delete[] arr;
    }
    return 0;
}