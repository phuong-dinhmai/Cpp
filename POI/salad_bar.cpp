#include <bits/stdc++.h>
#define maxN 100005
#define inf (int) (1e9+7)
using namespace std;

int n;
map <int, int> mp;
map <int, int> :: iterator it;
char a[maxN];
int lft[maxN], rght[maxN];
int f[maxN];
int M[maxN][32];
int ans = 0;

main(){
	freopen("in.inp","r",stdin);
	cin >> n;
	for (int i = 1; i <= n; i++) 
	{
		cin >> a[i];
		if (i == 1) f[i] = (a[i] == 'p'); else 
		f[i] = f[i-1] + (a[i] == 'p');
	}
	for (int i = 1; i <= n; i++) 
		f[i] = f[i] - (i - f[i]);
	for (int i = 1; i <= n; i++)
	{
		it = mp.find(f[i]);
		mp[f[i]] = i;
		if (it != mp.end()) 
		{
			lft[i] = it -> second;
		}
	}
	for (int i = 1 ; i <= n; i++) cout << lft[i] << " ";
	cout << endl;
	for (int i = 1; i <= n; i++) M[i][0] = i;
	for (int j = 1; (1 << j) <= n; j++)
		for (int i = 1; i + (1 << j) - 1 <= n; i++) 
		{
			if (f[M[i][j-1]] > f[M[i + (1 << (j-1))][j-1]])
				M[i][j] = M[i][j-1]; else M[i][j] = M[i + (1 << (j-1))][j-1];
		}
	for (int l = 1; l <= n; l++)
	{
		int k = log2(l - lft[l] + 1);
		int r;
		if (a[M[lft[l]][k]] > a[M[l - (1 << k) + 1][k]]) r = M[lft[l]][k];
		else if (a[M[lft[l]][k]] < a[M[l - (1 << k) + 1][k]]) r = M[l - (1 << k) + 1][k];
		else r = max(M[lft[l]][k], M[l - (1 << k) + 1][k]);
		ans = max(ans, r - lft[l] + 1);
		//cout << lft[l] << " " << l << " " << r << endl;
	}
	cout << ans << endl;
}
