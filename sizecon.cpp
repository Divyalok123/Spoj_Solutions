#include <iostream>
using namespace std;

int main() {
	int r = 0;
	int x, v; cin >> x;
	while(x--) { cin >> v; if(v > 0) r+=v;}
	cout << r << endl;
	return 0;
}