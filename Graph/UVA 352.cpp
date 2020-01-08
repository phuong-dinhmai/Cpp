#include <bits/stdc++.h>
#define WHITE 1
#define BLACK -1
using namespace std;

int n,test;
char a[25][25];
int check [25][25];

void dfs(int i, int j)
{
	if (i<0 || j<0 || i>=n || j>=n) return;
	if (a[i][j] == '0' || check[i][j] == BLACK) return;
	else 
	{ 
		//cout << 1 << endl;
		check[i][j] = BLACK;
		dfs(i,j+1);
		dfs(i,j-1);
		dfs(i+1,j);
		dfs(i-1,j);
		dfs(i+1,j+1);
		dfs(i-1,j+1);
		dfs(i+1,j-1);
		dfs(i-1,j-1);
	}
}

main(){
	//freopen ("in.inp","r",stdin);
	//freopen ("out.out","w",stdout);
	
	test = 0;
	 while (cin >> n)
	 {
	 	test++;
	 	for (int i = 0; i < n; i++)
	 		for (int j = 0; j < n; j++) cin >> a[i][j];
	 	for (int i = 0; i < 25 ; i++)
	 		for (int j = 0 ; j < 25; j++) check[i][j] = WHITE;
	 	int ans = 0;
	 	
	 	for (int i = 0; i < n; i++)
	 		for (int j = 0; j < n; j++)
	 		{
	 			if (a[i][j] ==  '1' && check[i][j] == 1)
	 			{
	 				ans++;
	 				dfs(i,j);
	 			}
	 		}
	 	cout << "Image number " << test << " contains " << ans  << " war eagles." << endl;
	 }
}
