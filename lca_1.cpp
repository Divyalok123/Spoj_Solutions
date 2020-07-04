#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

vector<vector<int>> edges;

bool storepath(int s, int d,  vector<int>& path, vector<bool>& visited) {
    if(s == d)
    {
        path.push_back(d);
        return true;
    }

    else if(edges[s].size() == 1) {
        if(s != d)
        {
            for(int i = 0; i < path.size(); i++)
                if(path[i] == s) {
                    path.erase(path.begin() + i);
                }
        }
        return false;
    }

    visited[s] = true;
    path.push_back(s);
    for(auto e: edges[s])
    {
        if(visited[e] == false)
        { 
            bool ans = storepath(e, d, path, visited);
            if(ans)
                break;
        }
    }
}

int LCA(int a, int b)
{
    if(a == b)
        return a;
    vector<int> path1, path2;

    vector<bool> visited(edges.size(), false);
    storepath(1, a, path1, visited);
    visited.assign(edges.size(), false);
    storepath(1, b, path2, visited);

    int n = path1.size();       
    int m = path2.size();

    int i = 0,j = 0;
    while(i < n && j < m && path1[i] == path2[j]) {
        i++;
        j++;
    }

    return path1[i-1];
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

        edges.resize(n+100);
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
        cout << "Case "<< Case << ":" << endl;
        while(q--)
        {
            int a, b;
            cin >> a >> b;
            cout << LCA(a, b) << endl;
        }
        Case++;
    }

    return 0;   
}
