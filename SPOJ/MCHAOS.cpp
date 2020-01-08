#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>
#define ll long long
#define maxN 100010
using namespace std;

typedef struct rever
{
	int pos;
	string str;
} rever;

int tree[maxN];
rever s[maxN];
rever ss[maxN];
int n;

bool cmp(const rever &a, const rever &b)
{
	return (a.str < b.str);
}

bool compare(const rever &a, const rever &b)
{
	return (a.str > b.str);
}

void update(int pos)
{
	while (pos <= n)
	{
		tree[pos]++;
		pos += (pos & (-pos));
	}
}

ll query(int pos)
{
	ll res = 0;
	while (pos)
	{
		res += tree[pos];
		pos -= (pos & (-pos));
	}
	return res;
}

int main(){
	//freopen("in.inp","r",stdin);
	cin.sync_with_stdio(false);
	cin >> n;
	fill(tree, tree + maxN, 0);
	for (int i = 0; i < n; i++) 
	{
		cin >> s[i].str;
		ss[i].str = string(s[i].str.rbegin(), s[i].str.rend());
		ss[i].pos = i;
	}
	sort(ss, ss+n, cmp);
	for (int i = 0; i < n; i++) s[ss[i].pos].pos = i + 1;
	sort(s, s+n, compare);
	ll ans = 0;
	for (int i = 0; i < n; i++) 
	{
		ans += query(s[i].pos);
		update(s[i].pos);
	}
	cout << ans << endl;
	return 0;
}
