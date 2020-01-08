#include <bits/stdc++.h>
using namespace std;

main(){
	long long ans, test, a[10000];
	
	freopen ("in.inp","r",stdin);
	cin >> test;
	for (int k=0; k<test; ++k)
	{
		long long n;
		cin >> n;
		ans=0;
		for (int i=0; i<n; ++i) cin >> a[i];
		
		cout << "Optimal train swapping takes " << ans << " swaps." << endl;
	}
}
