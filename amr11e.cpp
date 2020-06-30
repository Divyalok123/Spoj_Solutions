#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>
using namespace std;
vector<int> lucky;

bool islucky(int n)
{
    int count = 0;
    for(int i = 2; i <= n; i++)
    {
        if(n%i == 0)
        {
            count++;
            while(n%i == 0)
                n /= i;
        }
        if(count == 3)
            return true;
    }
    return false;
}

void get() {
    int arr[5] = {30, 42, 60, 66, 70};
    for(int i = 0; i < 5; i++)
        lucky.push_back(arr[i]);

    int count = 4;
    int num = 71;
    while(count <= 1000)
    {
        if(islucky(num))
        {
            lucky.push_back(num);
            count++;
        }
        num++;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    get();
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        cout << lucky[n-1] << endl;
    }

    return 0;
}