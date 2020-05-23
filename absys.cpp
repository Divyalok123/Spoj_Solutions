#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <stdexcept>
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
        string num1, op, num2, sign, num3;
        cin >> num1 >> op >> num2 >> sign >> num3;
        int _num1, _num2, _num3;
        int ans;
        string invalid;

        if(!all_of(num1.begin(), num1.end(), ::isdigit))
        {   
            invalid = num1;
        }
        else _num1 = stoi(num1);

        if(!all_of(num2.begin(), num2.end(), ::isdigit))
        {
            invalid = num2;
        }
        else _num2 = stoi(num2);

        if(!all_of(num3.begin(), num3.end(), ::isdigit))
        {
            invalid = num3;
        }
        else _num3 = stoi(num3);

        if(invalid == num1)
        {   
            ans = _num3 - _num2;
            cout << ans << " " << op << " " << _num2 << " " << sign << " " << _num3 << endl;
        }

        else if(invalid == num2)
        {   
            ans = _num3 - _num1;
            cout << _num1 << " " << op << " " << ans << " " << sign << " " << _num3 << endl;
        }
        else
        {   
            ans = _num1 + _num2;
            cout << _num1 << " " << op << " " << _num2 << " " << sign << " " << ans << endl;
        }
    }

    return 0;
}