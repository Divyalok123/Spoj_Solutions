/*
        !! AWESOME PROBLEM !!
*/

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
bool sieve[10000];
vector<int> primes;
vector<vector<int>> graph(10000);
bool visited[10005];

void siv()
{
    memset(sieve, true, sizeof(sieve));

    for (int i = 2; i * i <= 10000; i++)
    {
        if (sieve[i])
            for (int j = i * i; j <= 10000; j += i)
            {
                sieve[j] = false;
            }
    }

    for(int i = 1001; i < 10000; i++)
    {
        if(sieve[i])
        {
            primes.push_back(i);
        }
    }
}

bool isfine(int a, int b)
{
    return (a != b) && ((a/10 == b/10 && a%10 != b%10) || (a/100 == b/100 && a%10 == b%10 && a%100 != b%100) || (a/1000 == b/1000 && a%100 == b%100 && a%1000 != b%1000) || (a/1000 != b/1000 && a%1000 == b%1000));
}

void build() {
    siv();
    int size = primes.size();
    // cout << "Build Start" << endl;
    for(int i = 0; i < size; i++)
    {
        for(int j = i+1; j < size; j++)
        {
            if(isfine(primes[i], primes[j]))
            {
                graph[primes[i]].push_back(primes[j]);
                graph[primes[j]].push_back(primes[i]);
            }
        }
    }
    // cout << "Finished Building" << endl;
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    build();

    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        memset(visited, false, sizeof(visited));
        int mincount = INT_MAX;
        queue<pair<int, int>> q;
        q.push({a, 0});
        visited[a] = true;
        while(!q.empty())
        {
            int size = q.size();
            
            for(int i = 0; i < size; i++)
            {
                pair<int, int> ele = q.front();
                q.pop();
                if(ele.first == b) 
                {
                    mincount = min(mincount, ele.second);
                    continue;
                }
                for(auto j: graph[ele.first])
                {
                    if(!visited[j])
                    {
                        visited[j] = true;
                        q.push({j, ele.second+1});
                    }
                }
            }
        }

        cout << mincount << endl;
    }

    return 0;
}