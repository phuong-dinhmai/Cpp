#include <bits/stdc++.h>
using namespace std;

int n;
int a[105], f[105];

main(){
	freopen("in.inp","r",stdin);
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	f[0] = f[1] = f[2] = 0;
	for (int i = 3; i <= n; ++i){
		if (a[i] == 1 && a[i-1] == 0 && a[i-2] == 1) {
			f[i] = f[i-3]+1;
			a[i] = 0;
		}
		else f[i] = f[i-1];
	}
	cout << f[n] << endl;
}
