#include <bits/stdc++.h>
#define maxN (10000)
using namespace std;

typedef struct arr
{
	string name;
	int d, base, size;
	int l[21];
	int u[21];
} arr;

arr lis[maxN];
int c[10000][21];
int n, m;
string Name;

void cal(string s)
{
	int pos;
	int ans = 0;
	for (int i = 1; i <= n; i++)
		if (lis[i].name == s)
		{
			pos = i;
			break;
		}
	ans = c[pos][0];
	int a[21];
	for (int i = 1; i <= lis[pos].d; i++)
	{
		cin >> a[i];
		ans += (c[pos][i] * a[i]);
	} 
	cout << lis[pos].name << "[";
	for (int i = 1; i <= lis[pos].d; i++)
	{
		if (i != lis[pos].d) cout << a[i] << ", ";
		else cout << a[i];
	}
	cout << "] = " << ans << endl; 
}

main(){
	//freopen("in.inp","r",stdin);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> lis[i].name >> lis[i].base >> lis[i].size >> lis[i].d;
		for (int j = 1; j <= lis[i].d; j++) cin >> lis[i].l[j] >> lis[i].u[j];
	}
	for (int i = 1; i <= n; i++)
	{
		c[i][0] = lis[i].base - lis[i].l[lis[i].d] * lis[i].size;
		c[i][lis[i].d] = lis[i].size;
		for (int j = lis[i].d-1; j > 0; j--)
		{
			c[i][j] = c[i][j+1] * (lis[i].u[j+1] - lis[i].l[j+1] + 1);
			c[i][0] -= c[i][j] * lis[i].l[j];
		}
	}
	for (int i = 0; i < m; i++)
	{
		cin >> Name;
		cal(Name);
	}
}
