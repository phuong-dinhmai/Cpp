#include <bits/stdc++.h>
using namespace std;

int n,m,len;
char a[100][100];
char s[50000];
int x,y;
char dir;
int ans;

void test(char c)
{
	if (c == 'F')
	{
		if (dir == 'N') 
			if (x > 0 && a[x-1][y] != '#' && x < n) x--;
		if (dir == 'S')
			if (x < n - 1 && a[x+1][y] != '#' && x < n) x++;
		if (dir == 'L')
			if (y < m - 1 && a[x][y+1] != '#' && y < m) y++;
		if (dir == 'O')
			if (y > 0 && a[x][y-1] != '#' && y < m) y--;
	}
	if (c == 'D')
	{
		if (dir == 'N') dir = 'L';
		else if (dir == 'L') dir = 'S';
		else if (dir == 'S') dir = 'O';
		else dir = 'N';
	}
	if (c == 'E')
	{
		if (dir == 'N') dir = 'O';
		else if (dir == 'O') dir = 'S';
		else if (dir == 'S') dir = 'L';
		else dir = 'N';
	}
	if (a[x][y] == '*') {ans++; a[x][y] = '.';}
}

main(){
	//freopen ("in.inp","r",stdin);
	//freopen ("out.out","w",stdout);
	
	while (cin >> n >> m >> len)
	{
		ans = 0; 
		if (n == 0 && m == 0 && len == 0) break;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) 
			{
				cin >> a[i][j];
				if (a[i][j] == 'N' || a[i][j] == 'S' || a[i][j] == 'L' || a[i][j] == 'O') 
				{
					dir = a[i][j];
					x = i;
					y = j;
				}
			}
		
		for (int i = 0; i < len; i++) 
		{
			cin >> s[i];
			test(s[i]);	
		}
		cout << ans << endl;
	}
}
