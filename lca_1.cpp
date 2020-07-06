#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;
#define endl '\n'
vector<vector<int>> edges;
int path[1005][1005];
void storepath(int curr, int prev, int des, int x, int ind, bool& flag) {
    for(int i = 0; i < (int)edges[curr].size(); i++)
        if(edges[curr][i] != prev && flag == false) {
            path[x][ind] = edges[curr][i];
            if(edges[curr][i] == des) {
                flag = true;
                path[x][ind+1] = -1;
                return;
            }
            storepath(edges[curr][i], curr, des, x, ind+1, flag);
        }
}

void LCA()
{
    int size = edges.size();

    for(int i = 0; i < 1001; i++) {
        path[i][0] = 1;
    }
    path[1][1] = -1;

    for(int i = 2; i < size; i++) {
        bool flag = false;
        storepath(1, 0, i, i, 1, flag);
    }

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
        memset(path, 0, sizeof(path));
        LCA();

        cout << "Case "<< Case << ":" << endl;
        int q;
        cin >> q;

        while(q--)
        {
            int a, b;
            cin >> a >> b;
            int i = 0;
            while(path[a][i] != -1 && path[a][i] == path[b][i]) {
                i++;
            }

            cout << path[a][i-1] << endl;            
        }
        Case++;
        edges.clear();
    }

    return 0;   
}
