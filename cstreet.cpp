#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#include <vector>
using namespace std;

class edge
{
public:
    int s;
    int d;
    int w;
    edge() {}
    edge(int s, int d, int w)
    {
        this->s = s;
        this->d = d;
        this->w = w;
    }

    bool operator<(edge const &a)
    {
        return w < a.w;
    }
};

vector<int> parent;
vector<int> r;
vector<edge> edges;

int find_p(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find_p(parent[v]);
}

void union_e(int a, int b)
{
    int p_a = find_p(a);
    int p_b = find_p(b);

    if (p_a != p_b)
    {
        if (r[p_a] < r[p_b])
        {
            int temp = p_a;
            p_a = p_b;
            p_b = temp;
        }
        parent[p_b] = p_a;
        if (r[p_a] == r[p_b])
        {
            r[p_a]++;
        }
    }
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
        int p, n, s;
        cin >> p;
        cin >> n >> s;

        // cout << "Initial Check" << endl;
        parent.assign(n + 1, 0);
        r.assign(n + 1, 0);

        for (int i = 1; i <= n; i++)
        {
            // cout << "Internal Checkpoint 1" << endl;
            parent[i] = i;
        }

        // cout << "Checkpoint 1!" << endl;
        int a, b, c;
        for (int i = 0; i < s; i++)
        {
            // cout << "Internal Checkpoint 2" << endl;
            cin >> a >> b >> c;
            edge temp(a, b, c);
            edges.push_back(temp);
        }

        // cout << "Checkpoint 2!" << endl;
        sort(edges.begin(), edges.end());

        // cout << "Checkpoint 3!" << endl;
        unsigned int cost = 0;
        int count = 1;
        for (auto e : edges)
        {
            if (find_p(e.s) != find_p(e.d))
            {
                cost += (unsigned int)e.w;
                union_e(e.s, e.d);
                count++;
            }
        }

        // cout << "Checkpoint 4!" << endl;
        cout << (unsigned int)p * cost << endl;
        edges.clear();
        r.clear();
        parent.clear();
    }

    return 0;
}
