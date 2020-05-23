#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        cout << endl;
        int ng, nm;
        cin >> ng >> nm;
        int* g = new int[ng];
        int* m = new int[nm];

        for(int i = 0; i < ng; i++)
        {
            cin >> g[i];
        }

        for(int i = 0; i < nm; i++)
        {
            cin >> m[i];
        }

        int maxg = *max_element(g, g+ng);
        int maxm = *max_element(m, m+nm);

        if(maxg >= maxm)
        {
            cout << "Godzilla" << endl;
        }
        else cout << "MechaGodzilla" << endl;

        delete[] g;
        delete[] m;
    }
    return 0;
}