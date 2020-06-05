#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

//way 1 (time efficient)
// vector<int> v;

// void in()
// {
//     long long i = 1;
//     int count = 1;
//     while(i < 1000000000)
//     {
//         v.push_back((int)i);
//         i += 6*(long long)count;
//         count++;
//     }
// }

// void solve(int n)
// {
//     if(binary_search(v.begin(), v.end(), n)) cout << "Y" << endl;
//     else cout << "N" << endl;
// }

//way 2 (super fast)
bool issquare(unsigned int n)
{
    unsigned int x = floor(pow(n, 0.5));
    return x*x == n;
}

void solve(unsigned int n)
{
    if(issquare((4*n-1)/3))
        cout << "Y" << endl;
    else 
        cout << "N" << endl;
}
//way 3: simple brute force (space efficient)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // in();
    unsigned int n;
    cin >> n;
    while(n != -1)
    {
        solve(n);
        cin >> n;
    }

    return 0;
}