#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
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
#define setbits(x) __builtin_popcountll(x) 

void dfs(int** arr, int v, int i, bool* visited)
{
    visited[i] = true;

    for(int j = 1; j <= v; j++)
    {
        if(arr[i][j] && !visited[j])
        {
            dfs(arr, v, j, visited);
        }
    }
}

int main()
{
    fast;
    int n, m;
    cin >> n >> m;
    if(m != n-1) // no of edges must be equal to no. of vertices-1 
    {
        cout << "NO" << endl;
        return 0;
    }

    int** arr = new int*[n+1];
    for(int i = 0; i <= n; i++)
    {
        arr[i] = new int[n+1];
        for(int j = 0; j <= n; j++)
        {
            arr[i][j] = 0;
        }
    }

    for(int i = 0; i < m; i++)
    {
        int vert1, vert2;
        cin >> vert1 >> vert2;
        arr[vert1][vert2] = 1;
        arr[vert2][vert1] = 1;
    }

    bool* visited = new bool[n+1];
    visited[0] = true;
    for(int i = 1;  i <= n; i++)
    {
        visited[i] = false;
    }

    dfs(arr, n, 1, visited);


    for(int i = 1; i <= n; i++)
    {
        if(visited[i] == false)
        {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    return 0;
}