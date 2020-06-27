#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
typedef pair<int, int> pii;
#define inf 1e8
vector<vector<pii>> graph;
int n, m, q;
vector<int> dist;

void dijkstra(int s) {
    priority_queue<pii, vector<pii>, greater<pii>> q;
    dist.assign(n, inf);
    dist[s] = 0;
    q.push({0, s});

    int maxdis = 0;
    while(!q.empty())
    {
        pii temp = q.top();
        q.pop();

        int d = temp.first;
        int v = temp.second;

        if(d != dist[v])
            continue;

        if(d > maxdis)
            maxdis = d;

        for(auto edge: graph[v])
        {
            int v_edge = edge.first;
            int v_dis = edge.second;

            if(d + v_dis < dist[v_edge])
            {
                dist[v_edge] = d + v_dis;
                q.push({dist[v_edge], v_edge});
            }
        }
    }

    int count = 0;
    for(int i = 0; i < n; i++)
    {
        if(dist[i] == maxdis)
        {
            count++;
        }
    }

    cout << maxdis << " " << count << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> n >> m >> q;

    graph.resize(n);
    dist.resize(n);

    int a, b, l;
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b >> l;
        graph[a].push_back({b, l});
        graph[b].push_back({a, l});
    }

    int s;
    for(int i = 0; i < q; i++)
    {
        cin >> s;
        dijkstra(s);
    }

    return 0;
}