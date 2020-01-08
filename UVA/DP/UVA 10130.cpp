#include <bits/stdc++.h>
#define ii pair <int, int>
using namespace std;

main(){
	//freopen("in.inp","r",stdin);
	//freopen("out.out","w",stdout); 
	
	int test = 0;
	ii a[1000];
	int b[101];
	int n, m;
	int dp[32];
	scanf("%d", &test);
	while (test--)
	{
		scanf("%d", &m);
		for (int j = 0; j < m; j++) scanf("%d%d", &a[j].second, &a[j].first);
		scanf("%d", &n);
		for (int i = 0; i < n; i++) scanf("%d", &b[i]);
		for (int i = 0; i <= 31; i++) dp[i] = 0;
		for (int i = 0; i < m; i++)
			for (int j = 31; j >= 0; j--)
				if (a[i].first <= j) dp[j] = max(dp[j], dp[j - a[i].first] + a[i].second);
		int ans = 0;
		for (int i = 0; i < n; i++)
			ans += dp[b[i]];
		printf("%d\n", ans); 
	}
	
}
