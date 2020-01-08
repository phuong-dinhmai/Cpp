#include <bits/stdc++.h>
using namespace std;

int a[100][100];
int n;
bool ok[100], fir[100];
bool ans[100][100];

void dfs(int x, int y)
{
	if (x == y) return;
	ok[x] = true;
	for (int i = 0; i < n; i++)
		if (a[x][i] == 1 && !ok[i]) dfs(i, y);
}

void line()
{
	cout << "+";
	for (int i = 0; i < (2*n - 1); i++) cout << "-";
	cout << "+" << endl;
}

void result ()
{
	line();
	for (int i = 0; i < n; i++)
	{
		cout << "|";
		for (int j = 0; j < n ; j++) 
			if (ans[i][j]) cout << "Y|"; else cout << "N|";
		cout << endl;
		line();
	}
}

main(){
	//freopen("in.inp","r",stdin);
	//freopen("out.out","w",stdout);
	
	int test;
	cin >> test;
	for (int k = 0; k < test; k++)
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) 
			{
				a[i][j] = 0;
				ans[i][j] = false;
			}
		for (int i = 0; i < n; i++) ok[i] = false;
		
		cin >> n;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) cin >> a[i][j];
	
		dfs(0, -1);
		for (int i = 0; i < n; i++) 
		{
			fir[i] = ok[i];
			//cout << fir[i] << " " ;
		}
		
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n ; j++) ok[j] = false;
			dfs(0, i);
			for (int j = 0; j < n; j++)
				if (fir[j] && !ok[j]) ans[i][j] = true; else ans[i][j] = false;
		}
		cout << "Case " << k+1 << ":" << endl;
		result();
	}
}
