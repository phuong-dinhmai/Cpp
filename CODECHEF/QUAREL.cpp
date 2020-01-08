#include <bits/stdc++.h>
using namespace std;

const int maxN = 1000005;

bool cmp(int x, int y){
	return (x > y);
}

int test, n, k;
int a[maxN];

main(){
	//freopen("in.inp","r",stdin);
	cin >> test;
	while(test--){
		cin >> n >> k;
		for (int i = 0; i < n; i++) cin >> a[i];
		sort(a, a+n, cmp);
		int x = a[k-1], ans = 0;
		for (int i = 0; i < n; i++) 
			if (a[i] >= x) ++ans;
		cout << ans << endl;
	}
}
