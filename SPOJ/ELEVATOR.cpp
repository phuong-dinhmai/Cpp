#include <bits/stdc++.h>
#define maxN 401
#define maxHeight 400005
using namespace std;

struct block
{
	int h, num, mx;
} a[maxN];
int n;
bool f[maxHeight];
int k = 0;

bool cmp(const block &a, const block &b)
{
	return a.mx < b.mx;
}
main(){
	//freopen("in.inp","r",stdin);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].h >> a[i].mx >> a[i].num;
		k = max(k, a[i].mx);
	}
	sort(a, a+n, cmp);
	fill(f, f+maxHeight+1, false);
	int ans = 0;
	f[0] = true;
	for (int j = 0; j < n; j++)
		for (int h = 1; h <= a[j].num; h++)
			for (int i = a[j].mx; i >= a[j].h; i--)
			{
				f[i] = f[i] || f[i - a[j].h];
				if (f[i]) 
				{
					ans = max(ans, i);
				}
			}
	//for (int i = 0; i <= k; i++) cout << f[i] << endl;;
	//cout << endl;
	cout << ans << endl;
}
