#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
typedef pair<int, int> pii;

vector<vector<pii>> edges;

class compareq {
    public:
    bool operator()(pii const& a, pii const& b) {
        return a.first > b.first;
    }
};

int dij(int s, int e) {
    int n = edges.size();
    vector<int> time(n, INT_MAX);
    time[s] = 0;

    priority_queue<pii, vector<pii>, compareq> q;
    q.push({0, s});

    while(!q.empty()) {
        pii front = q.top();
        q.pop();

        int temptime = front.first;
        int tempval = front.second;

        if(temptime != time[tempval])
            continue;

        if(tempval == e) {
            return temptime;
        }

        for(auto e: edges[tempval]) {
            int tval = e.first;
            int ttime = e.second;

            if(ttime + temptime < time[tval]) {
                time[tval] = ttime+temptime;
                q.push({time[tval], tval});
            }
        }
    }

    if(time[e] == INT_MAX) return -1;
    return time[e];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n, m, qs, qe, s, e, w;
        cin >> n >> m >> qs >> qe;

        edges.resize(n+1);

        for(int i = 0; i < m; i++) {
            cin >> s >> e >> w;
            edges[s].push_back({e, w});
            edges[e].push_back({s, w});
        }

        int ans = dij(qs, qe);
        edges.clear();
        if(ans == -1) {cout << "NONE" << endl; continue;}
        cout << ans << endl;
    }
}