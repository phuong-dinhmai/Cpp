#include <bits/stdc++.h>
#define ln "\n"
#define ll long long
#define ii pair <int, int>
#define vi vector <int>
#define vll vector <ll>
#define vii vector <ii>
#define x first
#define y second
using namespace std;

const int N = 3e3+7;

int n, m;
char a[N][N];
int lft[N][N], lftdown[N][N], rght[N][N];
vii vec[N];

struct BIT
{
	vll t;
	void init(int num) { t.assign(num, 0);}
	void update(int pos)	{ for (; pos < t.size(); pos += (pos & (-pos))) t[pos]++;}
	ll get(int pos) 	{ ll res = 0LL; for (; pos > 0; pos -= (pos & (-pos))) res += t[pos]; return res;}
} tree[2*N];

void init()
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			if (a[i][j] == '.') lft[i][j] = 0; else lft[i][j] = lft[i][j-1] + 1;
		}
		
	for (int i = 1; i <= n; i++)
		for (int j = m; j > 0; j--)
		{
			if (a[i][j] == '.') rght[i][j] = 0; else rght[i][j] = rght[i][j+1] + 1;
		}
		
	for (int i = n; i > 0; i--)
		for (int j = 1; j <= m; j++)
		{
			if (a[i][j] == '.') lftdown[i][j] = 0; else lftdown[i][j] = lftdown[i+1][j-1] + 1;
		}
		
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			vec[j + rght[i][j] - 1].push_back(ii(i, j));
		}
		
	for (int i = 1; i <= m+n+7; i++) tree[i].init(m + 10);

}

main(){
	//freopen("in.inp","r",stdin);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%s", a[i]+1);
		
	init();
	
	ll ans = 0LL;
	
	for (int j = m; j > 0; j--)
	{
		for (int i = 0; i < vec[j].size(); i++)
		{
			int t1 = vec[j][i].x, t2 = vec[j][i].y;
			tree[t1 + t2].update(t2);
		}
		
		for (int i = 1; i <= n; i++)
		{
			if (a[i][j] == '.') continue;
			int c = min(lft[i][j], lftdown[i][j]);
			ans += (tree[i+j].get(j) - tree[i+j].get(j - c));
		}
	}
		
	printf("%I64d\n", ans);
}
