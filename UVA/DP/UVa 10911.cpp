#include <bits/stdc++.h>
#define ii pair <int, int>
#define x first
#define y second
using namespace std;

const int N = (1 << 20);
const double inf = 1e9+7;

int n;
string str;
ii a[20];
int cnt = 0;
double f[N];

double dis(int i, int j)
{
	return sqrt((a[i].x - a[j].x)*(a[i].x - a[j].x) + (a[i].y - a[j].y)*(a[i].y - a[j].y));
}

double F(int mask)
{
	if (mask == 0) return 0;
	if (f[mask] != -1) return f[mask];
	double ans = inf;
	for (int i = 0; i < 2*n; i++)
	{
		if (mask & (1 << i))
		{
			int msk = mask ^ (1 << i);
			for (int j = i; j < 2*n; j++)
			{
				if (msk & (1 << j)) 
				{
				 	ans = min(F(msk ^ (1 << j)) + dis(i, j), ans);
				}
			}
		} 
	}
	return f[mask] = ans;
}

main(){
	//freopen("in.inp","r",stdin);
	//freopen("out.out","w",stdout);
	ios_base :: sync_with_stdio(false); cin.tie(0);
	while(cin >> n)
	{
		if (n == 0) break;
		cnt++;
		fill(f, f+N, -1);
		for (int i = 0; i < 2*n; i++)
		{
			cin >> str >> a[i].x >> a[i].y;
		}
		printf("Case %d: %.2lf\n", cnt, F((1 << (2*n)) - 1));
	}
}
