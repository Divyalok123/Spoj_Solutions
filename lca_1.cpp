#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

vector<vector<int>> edges;
int path1[1005], path2[1005];

void dfs(int curr, int prev, int node, bool& flag, int* path, int index)
{
    cout << "in dfs" << endl;
    for(int i = 1; i <= edges[curr].size(); i++)
    {
        if(edges[curr][i] != prev && !flag)
        {
            path[index] = edges[curr][i];
            if(edges[curr][i] == node)
            {
                flag = true;
                path[index+1] = -1;
                return;
            }
            dfs(edges[curr][i], curr, node, flag, path, index+1);
        }
    }
    cout << "dfs end" << endl;
}

int LCA(int a, int b)
{
    if(a == b)
        return a;
    cout << "in lca" << endl;
    path1[1] = path2[1] = path1[0] = path2[0] = 1;

    bool found = false;
    dfs(1, 0, a, found, path1, 2);

    cout << "point 1" << endl;

    found = false;
    dfs(1, 0, b, found, path2, 2);

    cout << "point 2" << endl;
    int i = 0;
    while(path1[i] == path2[i])
        i++;
    cout << "i: " << i << endl;
    return path1[i];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    int Case = 1;
    while(t--)
    {
        int n;
        cin >> n;

        edges.resize(n+1);
        for(int i = 1; i <= n; i++)
        {
            int size, val;
            cin >> size;
            while(size--)
            {
                cin >> val;
                edges[i].push_back(val);
                edges[val].push_back(i);
            }
        }

        int q;
        cin >> q;
        cout << "Case " << Case << ": " << endl;
        while(q--)
        {
            int a, b;
            cin >> a >> b;
            cout << "in while s" << endl;
            cout << LCA(a, b) << endl;
            cout << "in while e" << endl;
        }
        Case++;
    }

    return 0;   
}