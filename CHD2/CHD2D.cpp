#include <bits/stdc++.h>
using namespace std;

main() {
	int n;
	while (cin >> n){
		int res = 0;
		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			if (a % 2) res++;
		}
		if (res % 2) cout << "Thanh" << endl; else cout << "Bach" << endl;
	}
}
