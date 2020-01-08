#include <bits/stdc++.h>
#define inf (int) (1e9+7)
#define maxN 500010
using namespace std;

typedef struct cand
{
	int first, second, third;
} cand;

cand candidate[maxN];
int tree[maxN];
int n;

bool cmp(const cand &a, const cand &b)
{
	return (a.first == b.first? (a.second == b.second? (a.third < b.third): (a.second < b.second)): (a.first < b.first));
}

void update(int pos, int val, int n)
{
	while (pos <= n)
	{
		tree[pos] = min (tree[pos], val);
		pos += (pos & (-pos));
	}
}

int query(int pos)
{
	int mn = inf;
	while (pos)
	{
		mn = min (tree[pos], mn);
		pos -= (pos & (-pos));
	}
	return mn;
}

main(){
	int t;
	//freopen("in.inp","r",stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) 
	{
		int x;
		scanf ("%d", &x);
		candidate[x].first = i+1;
	}
	for (int i = 0; i < n; i++) 
	{
		int x;
		scanf ("%d", &x);
		candidate[x].second = i+1;
	}
	for (int i = 0; i < n; i++)
	{
		int x;
		scanf ("%d", &x);
		candidate[x].third = i+1;
	} 
	sort(candidate, candidate + n + 1, cmp);
	fill(tree, tree+n+9, inf);
	//for (int i = 1; i <= n; i++) cout << candidate[i].first << " " << candidate[i].second << " " << candidate[i].third << endl;
	
	//BIT
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int cur_can = query(candidate[i].second);
		if (cur_can > candidate[i].third) ans++;
		update(candidate[i].second, candidate[i].third, n+9);
	}
	printf("%d\n", ans);
}
