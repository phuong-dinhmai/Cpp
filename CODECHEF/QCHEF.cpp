#include <bits/stdc++.h>
#define vi vector <int>
#define vvi vector <vi>
using namespace std;

const int N = 320;

int n, m, k;
vvi pos;
int left_most[N*N];
int ans[N][N*N];
int a[N*N];

main(){
	//freopen("in.inp","r",stdin);
	ios_base :: sync_with_stdio(false); cin.tie(0);
	
	cin >> n >> m >> k;
	pos.assign(m+1, vi());
	int size_block = sqrt(n);
	int num_block = ceil(n / size_block);
	for (int i = 1; i <= n; i++) cin >> a[i], pos[a[i]].push_back(i);

	memset(left_most, -1, sizeof(left_most));
	for (int i = 1; i <= num_block; i++)
	{
		int k = (i-1) * size_block + 1;
		for (int j = k; j <= n; j++) 
		{
			if (left_most[a[j]] < k) left_most[a[j]] = j;
			ans[i][j] = max(ans[i][j-1], j - left_most[a[j]]);
		}
	}
	
	while (k--)
	{
		int l, r;
		cin >> l >> r;
		int res = 0;
		int p = (l + size_block - 1) / size_block;
		int p1 = r / size_block;
		//cout << size_block << " " << p << " " << p1 << endl;
		if (p >= p1)
		{
			for (int i = l ; i <= r; i++)
			{
				int x = upper_bound(pos[a[i]].begin(), pos[a[i]].end(), r) - pos[a[i]].begin() - 1;
				if (x < 0) continue;
				if (pos[a[i]][x] < l) continue;
				res = max(res, pos[a[i]][x] - i);
			//	cout << r << " " << x << " " << pos[a[i]][x] << " " << i << endl;
			}
		} 
		else
		{
			int lim = p * size_block;
			for (int i = l; i <= lim; i++)
			{
				int x = upper_bound(pos[a[i]].begin(), pos[a[i]].end(), r) - pos[a[i]].begin() - 1;
				if (x < 0) continue;
				if (pos[a[i]][x] < l) continue;
				res = max(res, pos[a[i]][x] - i);
			}
			res = max(res, ans[p+1][r]);
		}
		printf("%d\n", res);
	}
}
