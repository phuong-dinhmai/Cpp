#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
int main() {
	ll t; 
	scanf("%lld",&t);
	while (t--) {
		ll ok=1;
		ll n,m,a[500001],b[2001];
		scanf("%lld%lld",&n,&m);
		for (ll i=0; i<n; i++) cin >> a[i];
		for (ll i=0; i<m; i++) cin >> b[i];
		for (ll i=0; i<n; i++) {
			for (ll j=0; j<m; j++)
				while (a[i]%b[j]==0) a[i]/=b[j];
		}
		for (ll i=1; i<n; i++)
			if (a[i]!=a[0]) { ok=0; break; }
		if (ok==1) printf("Yes\n"); else printf("No\n");
	}
}
