#include <bits/stdc++.h>
using namespace std;

int test, n;

main(){
	freopen("in.inp","r",stdin);
	cin >> test;
	while(test--){
		cin >> n;
		int t = 0, day = 0, total = 1;
		for (int i = 1; i <= n; ++i){
			int x;
			cin >> x;
			t += x;
			if (total == i && total < n) {
				total += t;
				++day;
			}
		}
		cout << day << endl;
	}
}
