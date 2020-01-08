#include <bits/stdc++.h>
#define maxN 230009
using namespace std;

typedef struct vi
{
	int i, j, id, type;
} vi;

int tree[maxN];
vi a[maxN];
int last[1000010];
int res[maxN];

bool cmp(const vi &a, const vi &b)
{
	if (a.j == b.j) return (a.type < b.type);
	return (a.j < b.j);
}

void update(int pos, int c)
{
	while (pos <= maxN)
	{
		tree[pos] += c;
		pos += (pos & (-pos));
	}
}

int query(int pos)
{
	int ans = 0;
	while (pos)
	{
		ans += tree[pos];
		pos -= (pos & (-pos));
	}
	return ans;
}

main(){
	int n, m;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) 
	{
		scanf ("%d", &a[i].i);
		a[i].j = i;
		a[i].type = -1;
	}
	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d", &a[i+n].i, &a[i+n].j);
		a[i+n].id = i; 
	}
	sort(a+1, a+n+m+1, cmp);
	//for (int i = 0; i < (int) (1e6+10); i++) last[i] = 0;
	for (int i = 1; i <= n+m; i++)
	{
		if (a[i].type == -1)
		{
			update(a[i].j, 1);
			if (last[a[i].i] > 0) update(last[a[i].i], -1);
			last[a[i].i] = a[i].j;
		}
		else res[a[i].id] = query(a[i].j) - query(a[i].i - 1);
	} 
	for (int i = 1; i <= m; i++) printf("%d\n", res[i]);
}
