#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define ll long long
using namespace std;

const ll inf=2e9;

ll n,a[1000001],f[1000001],ans[1000001];

int main() {
	cin >> n;
	f[1]=0; a[0]=inf; ans[1]=-1;
	for (ll i=1; i<=n; i++) cin >> a[i];
	for (int i=2; i<=n; i++) {
		f[i]=0; ans[i]=-1;
		if (a[i-1]>a[i]) f[i]=max(f[i],(ll)i-1);
		if (a[f[i-1]]>a[i]) f[i]=max(f[i],f[i-1]);
		if ((f[i]!=(ll)i)&&(f[i]>0)) ans[i]=1; else ans[i]=-1;
	}
	for (ll i=1; i<=n; i++)
		if (ans[i]==-1) cout << "- "; else
			cout << f[i] << " "; cout << endl;
}