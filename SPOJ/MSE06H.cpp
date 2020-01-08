#include <bits/stdc++.h>
#define ii pair<int, int>
#define ll long long
#define maxN 1000010
using namespace std;

ii a[maxN];
ll tree[maxN];
int n, m, k;

bool cmp(const ii &a, const ii &b)
{
	return (a.first == b.first? a.second < b.second: (a.first < b.first));
}

void update(int pos)
{
	while (pos <= maxN)
	{
		tree[pos] += 1;
		pos += (pos & (-pos));
	}
}

ll query(int pos)
{
	ll ans = 0;
	while (pos)
	{
		ans += tree[pos];
		pos -= (pos & (-pos));
	}
	return ans;
}

main(){
	//freopen("in.inp","r",stdin);
	
	int test;
	scanf("%d", &test);
	for (int x = 1; x <= test; x++)
	{
		scanf("%d %d %d", &n, &m, &k);
		for (int i = 0; i < k; i++)
		{
			scanf("%d%d", &a[i].first, &a[i].second);
		}
		sort(a, a+k, cmp);
		fill(tree, tree + maxN, 0);
		ll ans = 0;
		for (int i = 0; i < k; i++)
		{
			ans += (query(m) - query(a[i].second));
			update(a[i].second);
		}
		//for (int i = 0; i < k; i++) cout << tree[i] << endl;
		printf("Test case %d: %lld\n", x, ans);
	}
}
