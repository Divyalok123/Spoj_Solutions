#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

int power(long long int x, long long int y, long long int p) 
{ 
    long long int res = 1; 
  
    x = x % p;
  
    while (y > 0) { 
        if (y & 1) 
            res = (res * x) % p; 
        y = y >> 1; 
        x = (x * x) % p; 
    } 
    return res; 
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
    int a, x;
    long long int y;
    cin >> a;
    while (a--) {
        cin >> x >> y;
        cout << power(x, y, 10) << "\n";
    }
	return 0;
}