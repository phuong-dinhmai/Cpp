#include <bits/stdc++.h>
using namespace std;

main(){
	int n;
	cin >> n;
	int a[n];
	int b[n];
	int f[n+1];
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n-1; i++) cin >> b[i];
	f[n] = 0;
	f[n-1] = a[n-1];
	for (int i = n - 2; i >= 0; i--) 
		f[i] = min(f[i+1] + a[i], f[i+2] + b[i]);
	cout << f[0] << endl;
}
