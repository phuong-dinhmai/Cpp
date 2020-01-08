#include <bits/stdc++.h>
#define WHITE 1
#define BLACK -1
using namespace std;

int n,m,ans;
int check[50][50];
char a[50][50];

void grid (int i, int j, char c1, char c2)
{
	if (i<0 || j<0 || i>=n || j>=m) return ;
	if (a[i][j] != c1) return;
	a[i][j] = c2;
	grid(i,j+1,c1,c2);
	grid(i,j-1,c1,c2);
	grid(i+1,j,c1,c2);
	grid(i-1,j,c1,c2);
}

void find(int i, int j, char c1, char c2)
{
	if (i<0 || j<0 || i>=n || j>=m) return ;
	if (a[i][j] == 'X') 
	{
		grid(i,j,'X','*');
		ans++;
	}
	if (a[i][j] != c1) return;
	a[i][j] = c2;
	find(i,j+1,c1,c2);
	find(i,j-1,c1,c2);
	find(i+1,j,c1,c2);
	find(i-1,j,c1,c2);
}

main(){
	//freopen("in.inp","r",stdin);
	//freopen("out.out","w",stdout);
	int test  = 0;
	
	while (cin >> m >> n)
	{
		test++;
		vector <int> res;
		if (n == 0 && m == 0) break;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) cin >> a[i][j];
			
		for (int i = 0; i < n; i++)
			for (int j = 0 ; j < m; j++)
			if (a[i][j] != '.')
				{
					ans = 0;
					find(i,j,'*','.');
					if (ans) 
					{
						res.push_back(ans);
					}
				}

 		sort(res.begin(),res.end());
		cout << "Throw " << test << endl;
		for (int i = 0; i < res.size(); i++) 
		{
			if (i != 0) cout << " ";
			cout << res[i];
		}
		cout << endl; 
		cout << endl;
	}
}
