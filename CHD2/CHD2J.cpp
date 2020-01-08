#include <bits/stdc++.h>
using namespace std;

main() {
	long x, y, z;
	char k;
	while (cin >> x >> y >> z >> k){
		long mn = min(x, min(y, z));
		if (k == 'A') cout << 4 << endl; else cout << x+y+z-mn+2 << endl;
	}
}
