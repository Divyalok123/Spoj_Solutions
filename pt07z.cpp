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
#define setbits(x) __builtin_popcountll(x)
typedef priority_queue<int> maxheap;
typedef priority_queue<int, vector<int>, greater<int>> minheap;

// int maxx = 0;

// int dfs(int** tree, bool* visited, int node, int n)
// {
//     int first = 0;
//     int second = 0;
//     visited[node] = true;
//     for(int i = 0; i < n; i++)
//     {
//         if(tree[node][i] && visited[i] == 0)
//         {
//             int val = dfs(tree, visited, i, n);
//             if(val > first)
//             {
//                 second = first;
//                 first = val;
//             }
//             else if(val > second){
//                 second = val;
//             }
//         }
//     }

//     maxx = max(maxx, first + second);
//     return ++first;
// }

pair<int, int> bfs(int** tree, int n, int node)
{
    int distance[n];
    memset(distance, -1, sizeof(distance));
    
    queue<int> q;
    q.push(node);
    distance[node] = 0;
    while(!q.empty())
    {
        int temp = q.front();
        q.pop();
        for(int i = 0; i < n; i++)
        {
            if(tree[temp][i] && distance[i] == -1)
            {
                distance[i] = distance[temp] + 1;
                q.push(i);
            }
        }
    }

    int maxlen = 0;
    int newnode = -1;
    for(int i = 0; i < n; i++)
    {
        if(distance[i] > maxlen)
        {
            maxlen = distance[i];
            newnode = i;
        }
    }

    pair<int, int> ans = {newnode, maxlen};
    return ans;
}

int longest(int** tree, int n)
{
    pair<int, int> firstt, secondd;
    firstt = bfs(tree, n, 1);
    secondd = bfs(tree, n, firstt.first);

    return secondd.second;
}

int main()
{
    fast;
    int n;
    cin >> n;

    int **tree = new int *[n];
    for (int i = 0; i < n; i++)
    {
        tree[i] = new int[n];
        for(int j = 0; j < n; j++)
        {
            tree[i][j] = 0;
        }
    }

    for(int i = 0; i < n-1; i++)
    {
        int pri, sec;
        cin >> pri >> sec;
        tree[pri-1][sec-1] = 1;
        tree[sec-1][pri-1] = 1;
    }

    int ans = longest(tree, n);
    cout << ans << endl;

    for(int i = 0; i < n; i++)
    {
        delete[] tree[i];
    }
    delete[] tree;
    return 0;
}
