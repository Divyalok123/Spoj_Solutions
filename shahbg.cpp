#include <iostream>
#include <vector>
#include <string>
using namespace std;

void print(vector<bool> v, int n)
{
    for(int i = 1; i <= n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<bool> people(20002, false);

    int groups;
    int pos;
    for(int i = 1; i <= n; i++)
    {
        cin >> pos;
        if(i == 1)
        {
            people[pos] = true;
            groups = 1;
        }
        else 
        {
            people[pos] = true;
            groups++;
            if(people[pos-1] && people[pos+1])
                groups -= 2;
            else if(people[pos-1] || people[pos+1])
                groups--;
        }
        // cout << "Printing vector" << endl;
        // print(people, n);
        cout << groups << endl;
    }

    return 0;
}

