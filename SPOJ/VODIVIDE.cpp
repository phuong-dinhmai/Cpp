#include <bits/stdc++.h>
#define maxN 5005
#define inf (int) (1e9+7)
using namespace std;

struct xu{
	int a, b, pos;
} coin[maxN];

int n;
int f[maxN][maxN];
int trace[maxN][maxN];
bool used[maxN];

bool cmp(const xu &x, const xu &y)
{
	return (x.a < y.a || (x.a == y.a && x.b > y.b));
}

main(){
	//freopen("in.inp","r",stdin);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> coin[i].a;
	for (int i = 1; i <= n; i++) 
	{
		cin >> coin[i].b;
		coin[i].pos = i;
	}
	coin[0].pos = 0;
	sort(coin, coin+n+1, cmp);
	//for (int i = 1; i <= n; i++) cout << coin[i].a << " " << coin[i].b << endl;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++) f[i][j] = trace[i][j] = -inf;
	f[0][0] = 0;
	fill(used, used + n + 1, false);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			{
				f[i][j] = f[i-1][j-1] + coin[i].b;
				trace[i][j] = i;
				if (2*j >= i)
				{
					if (f[i][j] < f[i-1][j])
					{ 
						f[i][j] = f[i-1][j];
						trace[i][j] = trace[i-1][j];
					}
				}
			}
	/*for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++) cout << f[i][j] << " ";
		cout << endl;
	}*/
	cout << f[n][n/2] << endl;
	int i = n; int j = n/2;
	while(trace[i][j] >= 0)
	{
		cout << coin[trace[i][j]].pos << " ";
		used[trace[i][j]] = true;
		for (int k = n; k > 0; k--)
			if (!used[k]) 
			{
				cout << coin[k].pos << endl;
				used[k] = true;
				break;
			}
		i = trace[i][j]-1; 
		j--;
	}
}
