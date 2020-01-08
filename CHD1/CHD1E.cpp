#include <bits/stdc++.h>
using namespace std;

main(){
	int test;
	cin >> test;
	while(test--){
		int n, k, res = 0;
		cin >> n >> k;
		for(int i = 0; i < n; i++) {
			int x;
			cin >> x;
			res += (x % 2);
		}
		if (k == 0) {
			if (res % 2) cout << "0.000000" << endl; else cout << "1.000000" << endl;
		} else cout << "0.500000" << endl;
	}
}
