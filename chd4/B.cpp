#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

int main() {
	ll n,k,t,s;
	int a[5001],f[5001],ff[5001];
	
	cin >> t;
	while(t--) {
		int ok=1;
		cin >> n >> k;
		for (int i=1; i<=n; i++) {
			cin >> a[i]; a[i]%=k;
			if (a[i]==0) { cout << "YES\n" << i << endl; break; }
			else cout << "NO" << endl;
		}
		s=k;
		memset(f,0,sizeof(f));
		memset(ff,0,sizeof(ff));
		for (int i=1; i<=n; i++) {
			for (int j=0; j<=s; j++) cout << ff[j] << " "; cout << endl;
			for (int j=0; j<=s; j++) {
				if (j>a[i]) f[j]=ff[j]; else f[j]=max(ff[j],f[j-a[i]]+a[i]);
			}
			for (int j=0; j<=s; j++) ff[j]=f[j];
		}
		cout << f[k] << endl;
	}
}