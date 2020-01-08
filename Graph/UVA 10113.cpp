#include <bits/stdc++.h>
#define maxN 100
using namespace std;

int n;
int adj[maxN][maxN];

int gcd(int a, int b)
{
	if (b == 0) return a; else return gcd(b, a%b);
}

void dfs(int x, int y)
{
	int a,b,c,d,r1,r2,uc;
	for (int i = 0; i < n; i++)
		if (adj[x][i] == -1 && adj[y][i] != -1 && i != x)
		{
			a = adj[x][y];
			b = adj[y][x];
			c = adj[y][i];
			d = adj[i][y];
			uc = gcd(b,c);
			r1 = c / uc;
			r2 = b / uc;
			uc = gcd(a*r1, d*r2);
			adj[x][i] = a*r1/uc;
			adj[i][x] = d*r2/uc;
			dfs(x,i);
		}	

}

main(){
	//freopen("in.inp","r",stdin);
	//freopen("out.out","w",stdout);
	
	map <string, int> m;
	string s1, s2;
	int a, b;
	char k, s;
	
	for (int i = 0; i < maxN; i++)
		for (int j = 0; j < maxN; j++) adj[i][j] = -1;
	n = 0;
	
	while (cin >> s)
	{
		if (s == '.') break;
		if (s == '!')
		{
			cin >> a >> s1 >> k >> b >> s2;
			if (m.find(s1) == m.end()) 
			{
				m[s1] = n; 
				n++;
			}
			if (m.find(s2) == m.end()) 
			{
				m[s2] = n;
				n++;
			}
			int x, y, uc;
			x = m[s1];
			y = m[s2];
			uc = gcd(a,b);
			adj[x][y] = a / uc;
			adj[y][x] = b / uc;
		}
		else
		{
			cin >> s1  >> k >> s2;
			if (m.find(s1) == m.end()) 
			{
				m[s1] = n; 
				n++;
			}
			if (m.find(s2) == m.end()) 
			{
				m[s2] = n;
				n++;
			}
			int x, y;
			x = m[s1];
			y = m[s2];
			for (int i = 0; i < n ; i++)
				if (adj[x][i] != -1) dfs(x,i);
			if (adj[x][y] != -1) 
				cout << adj[x][y] << " " << s1 << " = " << adj[y][x] << " " << s2 << endl;
			else cout << "? " << s1 << " = " << "? " << s2 << endl;
		}
	}
}
