#include <bits/stdc++.h>
#define ll long long
#define maxN 200010
using namespace std;

typedef struct arr
{
	int val, pos;
} arr;

arr a[maxN];
int n, test;
ll tree[maxN];

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

bool cmp(const arr &a, const arr &b)
{
	return a.val < b.val;
}

main(){
	//freopen("in.inp","r",stdin);
	
	scanf("%d", &test);
	while (test--)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i].val);
			a[i].pos = i + 1;
		}
		fill(tree, tree+n+9, 0);
		sort(a, a + n, cmp);
		int pos = 0;
		ll ans = 0;
		for (int i = n-1; i >= 0; i--)
		{
			ans += query(a[i].pos);
			update(a[i].pos);
		}
		printf("%lld\n", ans);
		//cout << endl; 
	}
}
