#include <bits/stdc++.h>
#define int long long
#define ii pair <int, int>
#define cnt first
#define len second
#define maxN (int) (1e5+5)
using namespace std;

struct rec
{
	int x1, x2, y, type;
	rec(int x1 = 0, int x2 = 0, int y = 0, int type = 0): x1(x1), x2(x2), y(y), type(type){}
} seg[2*maxN];

int n;
ii t[8*maxN];
int dic[2*maxN];
int ans = 0;
int size;

bool cmp(const rec &a, const rec &b)
{
	return (a.y < b.y || (a.y == b.y && a.type < b.type));
}

int find(int num)
{
	return lower_bound(dic, dic+size, num) - dic;
}

void update(int node, int l, int r, int a, int b, int type)
{
	if (b <= l || r <= a) return;
	if (r - l <= 1)
	{
		t[node].cnt += type;
		if (t[node].cnt) t[node].len = (dic[r] - dic[l]);
		else t[node].len = 0;
		return ;
	}
	if (a <= l && r <= b)
	{
		t[node].cnt += type;
		if (t[node].cnt) t[node].len = (dic[r] - dic[l]);
		else t[node].len = t[2*node].len + t[2*node+1].len;
		return;
	}
	int mid = (l + r)/2;
	update(2*node, l, mid, a, b, type);
	update(2*node+1, mid, r, a, b, type);
	if (t[node].cnt == 0) t[node].len = t[2*node].len + t[2*node+1].len;
	return;
}

main(){
	//freopen("in.inp","r",stdin);
	//freopen("out.out","w",stdout);
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	for (int i = 0; i < 8*maxN; i++) t[i].cnt = t[i].len = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if (x1 > x2) swap(x1, x2);
		if (y1 > y2) swap(y1, y2);
		seg[i] = rec(x1, x2+1, y1, 1);
		seg[i+n] = rec(x1, x2+1, y2+1, -1);
		dic[i] = x1;
		dic[i+n] = x2+1;
	}
	sort(seg, seg+2*n, cmp);
	sort(dic, dic+2*n);
	size = unique(dic, dic+2*n) - dic;
	n *= 2;
	int y0 = 0;
	for (int i = 0; i < n; i++)
	{
		ans += (seg[i].y - y0)*t[1].len;
		//cout << ans << endl;
		y0 = seg[i].y;
		update(1, 0, size, find(seg[i].x1), find(seg[i].x2), seg[i].type);
	}
	printf("%I64d\n", ans);
}
