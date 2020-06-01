#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

/* !! Not Solved!! */

unordered_map<char, int> mapp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        string first, second, third, fourth, fifth;
        cin >> first >> second >> third >> fourth >> fifth;
        
        mapp[first[0]]++; mapp[first[1]]++;
        mapp[second[0]]++; mapp[second[1]]++;
        mapp[third[0]]++; mapp[third[1]]++;
        mapp[fourth[0]]++; mapp[fourth[1]]++;
        mapp[fifth[0]]++; mapp[fifth[1]]++;


        if(mapp['K'] && mapp['Q'] && mapp['A'] && mapp['T'] && mapp['J'] && (mapp['S'] == 5 || mapp['H'] == 5|| mapp['D'] == 5|| mapp['C'] == 5))
            cout << "royal flush" << endl;
        
        mapp.clear();
    }

    return 0;
}