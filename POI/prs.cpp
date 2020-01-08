#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, m, p;
ll ans = 0LL;

main(){
	scanf("%d%d%d", &n, &m, &p);
		
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) 
			if (2*(i+j) >= p) ans += (n-i+1)*(m-j+1);
			
	printf("%lld\n", ans);
}
