#include <bits/stdc++.h>
#define ll long long
using namespace std;

int test; 
ll m,n,a[410][410],s[410][410];

int f(int i,int j,int k) {
	return s[i+k-1][j+k-1]-s[i-1][j+k-1]-s[i+k-1][j-1]+s[i-1][j-1];
}

int main() {
	cin >> test;
	while (test--) {
		cin >> n >> m;
		for (ll i=0; i<=n; i++) a[i][0]=0;
		for (ll i=0; i<=m; i++) a[0][i]=0;
		for (ll i=1; i<=n; i++)
			for (ll j=1; j<=m; j++) { cin >> a[i][j]; s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j]; }
			
		ll mx=-1e18;
		for (int k=3; k<=min(m,n); k++) 
			for (int i=1; i+k<=n+1; i++)
				for (int j=1; j+k<=m+1; j++) {
					ll big=f(i,j,k);
					ll small=f(i+1,j+1,k-2);
					mx=max(mx,big-small);
				}
		cout << mx << endl;
	}
}