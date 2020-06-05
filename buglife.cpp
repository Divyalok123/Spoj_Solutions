#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

bool solve(vector<vector<int>>& graph, int numbugs, int ver, int color, vector<int>& colorings)
{
    if(colorings[ver] != -1)
        return colorings[ver] == color;
    colorings[ver] = color;
    for(auto x: graph[ver])
    {
        if(colorings[x] == -1)
        {
            if(!solve(graph, numbugs, x, 1-color, colorings))
            {
                return false;            
            }   
        }
        else
            if(colorings[x] == colorings[ver]) return false;    
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int scenario = 1;
    while(n--){
        int numbugs, numinter;
        cin >> numbugs >> numinter;
        vector<vector<int>> graph(numbugs);
        vector<int> color(numbugs, -1);
        for(int i = 0; i < numinter; i++)
        {
            int x, y;
            cin >> x >> y; x--; y--;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }

        bool res = true;
        for(int i = 0; i < numbugs; i++)
            if(color[i] == -1 && !solve(graph, numbugs, i, 1, color))
                res = false;
        
        cout << "Scenario #" << scenario << ":" << '\n';
        if(!res)
            cout << "Suspicious bugs found!" << '\n';
        else
            cout << "No suspicious bugs found!" << '\n';
        scenario++;
        graph.clear();
        color.clear();
    }
    return 0;
}