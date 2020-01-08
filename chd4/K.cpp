#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back
using namespace std;

int n,m,b[10001],p[100001],sp=0;
long long a[100001];

int main() {
	int t; cin >> t;
	while (t--) {
		int ok=1;
		cin >> n >> m;
		for (int i=0; i<n; i++) cin >> a[i];
		for (int i=0; i<m; i++) cin >> b[i];
		sort(b,b+m);

		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++)
				while (a[i]%b[j]==0) a[i]/=b[j];
		}
		for (int i=1; i<n; i++)
			if (a[i]!=a[0]) { ok=0; break; }
		if (ok==1) cout << "Yes\n"; else cout << "No\n";
	}
}
