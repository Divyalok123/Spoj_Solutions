#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
vector<string> graph;
int h, w;
string s;

void initialise(bool **v, int n, int m)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            v[i][j] = false;
}

void solve(int i, int j, int curr, int &ans, bool **visited)
{
    if (i >= h || i < 0 || j < 0 || j >= w || visited[i][j])
        return;

    if (curr > ans)
        ans = curr;
    // cout << "I'm at i: " << i << " j: " << j << endl;
    visited[i][j] = true;
    char nextchar = graph[i][j] + 1;
    if (i > 0 && graph[i - 1][j] == nextchar)
        solve(i - 1, j, curr + 1, ans, visited);
    if (i < h - 1 && graph[i + 1][j] == nextchar)
        solve(i + 1, j, curr + 1, ans, visited);
    if (j > 0 && graph[i][j - 1] == nextchar)
        solve(i, j - 1, curr + 1, ans, visited);
    if (j < w - 1 && graph[i][j + 1] == nextchar)
        solve(i, j + 1, curr + 1, ans, visited);
    if (i > 0 && j > 0 && graph[i - 1][j - 1] == nextchar)
        solve(i - 1, j - 1, curr + 1, ans, visited);
    if (i > 0 && j < w - 1 && graph[i - 1][j + 1] == nextchar)
        solve(i - 1, j + 1, curr + 1, ans, visited);
    if (i < h - 1 && j > 0 && graph[i + 1][j - 1] == nextchar)
        solve(i + 1, j - 1, curr + 1, ans, visited);
    if (i < h - 1 && j < w - 1 && graph[i + 1][j + 1] == nextchar)
        solve(i + 1, j + 1, curr + 1, ans, visited);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int c = 1;
    while (1)
    {
        cin >> h >> w;
        if (h == 0 && w == 0)
            break;

        cout << "Case " << c << ": ";
        bool **visited = new bool *[h];
        for (int i = 0; i < h; i++)
        {
            visited[i] = new bool[w];
        }
        vector<pair<int, int>> points;

        for (int i = 0; i < h; i++)
        {
            cin >> s;
            graph.push_back(s);
            for (int j = 0; j < s.length(); j++)
            {
                if (s[j] == 'A')
                    points.push_back({i, j});
            }
        }

        int ans = 0;
        for (int i = 0; i < points.size(); i++)
        {
            initialise(visited, h, w);
            int currans = 1;
            solve(points[i].first, points[i].second, 1, currans, visited);
            if (currans > ans)
                ans = currans;
        }

        cout << ans << endl;

        c++;
        for (int i = 0; i < h; i++)
            delete[] visited[i];
        delete[] visited;
        graph.clear();
    }

    return 0;
}