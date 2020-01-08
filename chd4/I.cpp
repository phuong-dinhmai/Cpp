#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	int test; cin >> test;
	ll m,n,a[410][410],s[410][410],t[410][410];
	while (test--) {
		cin >> n >> m;
		for (ll i=1; i<=n; i++)
			for (ll j=1; j<=m; j++) cin >> a[i][j];
			
		for (ll i=1; i<=n; i++)
			for (ll j=1; j<=m-2; j++) s[i][j]=a[i][j]+a[i][j+1]+a[i][j+2];
		
		for (ll i=0; i<=m; i++) t[0][i]=0;
		
		for (ll i=1; i<=n; i++) 
			for (ll j=1; j<=m; j++) 
				t[i][j]=t[i-1][j]+a[i][j];
		ll mx=-1e18,gi,gj,gk;
		for (ll i=1; i<=m-2; i++)
			for (ll j=1; j<=n-2; j++)
				for (ll k=j+2; k<=n; k++) {
					if (mx<s[j][i]+s[k][i]+t[k-1][i+1]-t[j][i+1]) {
						mx=s[j][i]+s[k][i]+t[k-1][i+1]-t[j][i+1];
						gi=i; gj=j; gk=k;
					}
				}
		cout << mx << endl;
	}
}