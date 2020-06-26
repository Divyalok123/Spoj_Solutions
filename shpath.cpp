#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <string>
#include <unordered_map>
using namespace std;
#define pii pair<int, int>
#define inf 1e8
unordered_map<string, int> mapp;
vector<vector<pii>> graph;

void dijkstras(int s, int e)
{
    priority_queue<pii, vector<pii>, greater<pii>> q;
    int size = graph.size();
    vector<int> dist(size, inf);

    dist[s] = 0;
    q.push({0, s});
    while(!q.empty())
    {
        pii top = q.top();
        q.pop();

        int dis = top.first;
        int v = top.second;

        if(v == e)
        {
            cout << dis << endl;
            return;
        }

        if(dist[v] != dis) 
            continue;

        for(auto edge: graph[v])
        {
            int vert = edge.first;
            int weight = edge.second;

            if(weight + dis < dist[vert])
            {
                dist[vert] = weight + dis;
                q.push({weight + dis, vert});
            }
        }
    }
    cout << dist[e] << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        graph.resize(n + 1);
        int i = 1;
        while (i <= n)
        {
            string s;
            cin >> s;
            mapp[s] = i;

            int e;
            cin >> e;

            int v, weight;
            for (int k = 0; k < e; k++)
            {
                cin >> v >> weight;
                graph[i].push_back({v, weight});
            }

            i++;
        }

        int r;
        cin >> r;

        while (r--)
        {
            string c1, c2;
            cin >> c1 >> c2;
            dijkstras(mapp[c1], mapp[c2]);
        }

        mapp.clear();
        graph.clear();
    }
    return 0;
}