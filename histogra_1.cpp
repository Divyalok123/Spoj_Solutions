#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>
#include <climits>
using namespace std;
#define ll long long

int n;
ll arr[100005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    while(n)
    {
        for(int i = 0; i < n; i++)
            cin >> arr[i];

        ll max = 0, curr;
        int i = 0;
        stack<int> s;
        while(i < n)
        {
            if(s.empty() || arr[i] >= arr[s.top()])
                s.push(i++);

            else
            {
                int v = s.top();
                s.pop();

                curr = arr[v]*(s.empty() ? i : i-s.top()-1);
                if(curr > max) max = curr;
            }
        }
        while(!s.empty())
        {
            int v = s.top();
            s.pop();

            curr = arr[v]*(s.empty() ? i : i - s.top()-1);
            if(curr > max) max = curr;
        }

        cout << max << endl;
        cin >> n;
    }

    return 0;
}