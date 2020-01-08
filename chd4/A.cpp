#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

const ll mod=1e9+7;

ll f[1000010];
int n;

int main() {
	ll t;
	scanf ("%lld",&t);
	f[0]=1; f[1]=1;
	for (int i=2; i<=1e6; i++) f[i]=(f[i-1]+f[i-2])%mod;
	while (t--) {
		scanf ("%lld",&n);
		if (n == 1) printf("0 1");
		else if (n == 0) printf("1 0"); else printf("%lld %lld",f[n-2],f[n-1]);
		if (t != 0) printf("\n");
	}
}
