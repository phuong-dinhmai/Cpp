#include <bits/stdc++.h>
#define ll long long 
#define WHITE 1
#define BLACK -1
using namespace std;

main(){
	//freopen ("in.inp", "r", stdin);
	//freopen ("out.out","w",stdout);
	int n,m,x,y,f[51][51];
	char c1;
	string s;
	cin >> n >> m;
	for (int i=0; i<51; i++)
		for (int j=0; j<51; j++)
				f[i][j] = BLACK;
	while (cin >> x >> y >> c1){
		cin >> s;
		int ok = 0,c;
		if (c1 == 'N') c=0;
		else if (c1 == 'E') c=1;
		else if (c1 == 'S') c=2;
		else c=3;
		for (int i=0; i<s.size(); i++)
		{
			if (s[i] == 'L') 
			{
				if (c == 0) c=3;
				else c--;
			} 
			if (s[i] == 'R')
			{
				if (c == 3) c=0;
				else c++;
			} 
			if (s[i] == 'F')
			{
				if (c == 0)
				{
					if (y == m && f[x][y] == BLACK)
					{
						ok = 1;
						f[x][y] = WHITE;
						cout << x << " " << m << " N LOST" << endl;
						break;
					}
					else if (y < m) y++;
				}
				if (c == 1)
				{
					if (x == n && f[x][y] == BLACK)
					{
						ok = 1;
						f[x][y] = WHITE;
						cout << x << " " << y << " E LOST" << endl;
						break;
					}
					else if (x < n) x++;
				}
				if (c == 2)
				{
					if (y == 0 && f[x][y] == BLACK)
					{
						ok = 1;
						f[x][y] = WHITE;
						cout << x << " " << y << " S LOST" << endl;
						break;
					}
					else if (y > 0) y--;
				}
				if (c == 3)
				{
					if (x == 0) 
					{
						ok = 1;
						f[x][y] = WHITE;
						cout << x << " " << y << " W LOST" << endl;
						break;
					}
					else if (x > 0) x--;
				}
			}
		}
		if (ok == 0) 
		{
			cout << x << " " << y;
			if (c == 0) cout << " N" << endl;
			else if (c == 1) cout << " E" << endl;
			else if (c == 2) cout << " S" << endl;
			else cout << " W" << endl;
		}
	}
}

