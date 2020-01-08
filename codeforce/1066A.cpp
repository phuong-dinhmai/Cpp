#include <bits/stdc++.h>
using namespace std;

int l, v, st, en;
int test;

main(){
	freopen("in.inp","r",stdin);
	cin >> test;
	while(test--){
		cin >> l >> v >> st >> en;
		cout << l/v + (st-1)/v - en/v << endl;
	}
}
