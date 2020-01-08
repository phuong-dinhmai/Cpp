#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int n;
int a[100][100];

ll vien(int k)
{
	int m = (n-k)/2+1;
	long long res =0 ;
	for (int i=m+1; i<=m+k-2; i++) 
	{
		res+=(a[m][i] + a[m+k-1][i] + a[i][m] + a[i][m+k-1] );
	}
	res+=(a[m][m] + a[m][m+k-1] + a[m+k-1][m] + a[m+k-1][m+k-1]);
	return res;
		
}

main(){
	stack <ll> ans;
	ll sum = 0;
	int test =0 ;
	//freopen ("in.inp","r",stdin);
	//freopen ("out.out","w",stdout);
	
	while (cin >> n)
	{
		if (n == 0) break; 
		test ++;
		for (int i=1; i<=n; i++)
			for (int j=1; j<=n; j++) cin >> a[i][j];
		if (n%2==0) 
		{
			sum = a[n/2][n/2+1]+a[n/2][n/2]+a[n/2+1][n/2]+a[n/2+1][n/2+1];
			ans.push(sum);
			for (int i=4; i<=n; i+=2)
			{
				sum = vien(i);
				ans.push(sum);
			}
		}
		else 
		{
			sum = a[n/2+1][n/2+1];
			ans.push(sum);
			for (int i=3; i<=n; i+=2)
			{
				sum = vien(i);
				ans.push(sum);
			}
		}
		cout << "Case " << test << ":";
		while (!ans.empty())
			{
				cout << " " << ans.top();
				ans.pop();
			}
		cout << endl;
	}
}
