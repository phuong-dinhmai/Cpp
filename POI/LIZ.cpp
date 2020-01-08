#include <bits/stdc++.h>
#define ll long long
#define ii pair <int, int>
using namespace std;

const int N = 1e6+7;
const int inf = -(1e9+7);

int n, m;
int a[N];
ll sum[N];
ii cnt[2*N];
int lft, rght, start = 0;

main(){
	//freopen("in.inp","r",stdin);
	scanf ("%d%d\n", &n, &m);
	for (int i = 1; i <= 2*N; i++) cnt[i] = ii(inf, inf);
	lft = n, rght = 1;
	for (int i = 1; i <= n; i++)
	{
		char c;
		scanf("%c", &c);
		if (c == 'T') a[i] = 2; else a[i] = 1;
		sum[i] = sum[i-1] + a[i];
		cnt[sum[i]] = ii(1, i);
		if (a[i] == 1) lft = min(lft, i), rght = max(i, rght);
	}
	
	start = lft;
	for (int i = start; i <= n; i++)
	{
		int val = sum[i] - sum[start-1];
		cnt[val] = ii(start, i);
	}
	for (int i = start+1; i <= n; i++)
	{
		int val = sum[i] - sum[start];
		cnt[val] = ii(start+1, i);
	}
	for (int i = 1; i < start; i++)
	{
		int val = sum[n] - sum[i-1];
		cnt[val] = ii(i, n);
	}
	
	start = rght;
	for (int i = 1; i <= start; i++)
	{
		int val = sum[start] - sum[i-1];
		cnt[val] = ii(i, start);
	}
	for (int i = 1; i < start; i++)
	{
		int val = sum[start-1] - sum[i-1];
		cnt[val] = ii(i, start-1);
	}
		
	for (int i = 0; i < m; i++)
	{
		int k;
		scanf("%d", &k);
		if (cnt[k] == ii(inf, inf)) printf("NIE\n");
		else printf("%d %d\n", cnt[k].first, cnt[k].second);
	}
}
