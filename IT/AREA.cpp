#include <bits/stdc++.h>
#define ii pair <int, int>
#define ll long long
#define num first
#define len second 
#define maxN 20005
using namespace std;

const int N = 30005;

struct rec
{
	int x, y1, y2, type;
} a[maxN];

ii t[5*N];
ll res = 0;
int n;

bool cmp(const rec &a, const rec &b)
{
	return (a.x < b.x || (a.x == b.x && a.type < b.type));
}

void update(int node, int l, int r, int a, int b, int type)
{
	if (b < l || r < a || l > r) return;
	if (a <= l && r <= b)
	{
		t[node].num += type;
		if (type == 1)
		{
			t[node].len = (r-l+1);
		}
		else
		{
			if (t[node].num == 0)
			{
				t[node].len = t[2*node].len + t[2*node+1].len;
			}
		}
		return;
	}
	int mid = (l + r)/2;
	update(2*node, l, mid, a, b, type);
	update(2*node+1, mid+1, r, a, b, type);
	if (t[node].num == 0)
	{
		t[node].len = t[2*node].len + t[2*node+1].len;
	}
	return;
}

main(){
	//freopen("in.inp","r",stdin);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		a[i].x = x1;
		a[i+n].x = x2;
		a[i].y1 = a[i+n].y1 = y1;
		a[i].y2 = a[i+n].y2 = y2;
		a[i].type = 1;
		a[i+n].type = -1;
	}
	n *= 2;
	sort(a, a+n, cmp);
	/*for (int i = 0; i < n; i++)
		{
			cout << a[i].x << " " << a[i].y1 << " " << a[i].y2 << endl;
		}*/
	int x0 = 0;
	for (int i = 0; i < n; i++)
	{
		res += (a[i].x - x0)*(t[1].len);
		x0 = a[i].x;
		update(1, 0, N, a[i].y1, a[i].y2-1, a[i].type);
	}
	printf("%lld\n", res);
}
