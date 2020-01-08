#include <bits/stdc++.h>
#define WHITE 1
#define BLACK 0
#define vi vector <int>
using namespace std;

int a[30], check[30][30],ok[30];
string ans;


void init()
{
	for (int i = 0; i < 26; i++)
		for (int j = 0; j < 26; j++) check[i][j] = WHITE;
	for (int i = 0; i < 26; i++) 
	{
		a[i] = 0;
		ok[i] = WHITE;
	} 
	ans = "";
}

void find(int i)
{
	for (int j = 0; j < 26; j++)
		if (a[j] != 0 && ok[j] == WHITE)
		{
			if (check[j][i] == BLACK) return;
			if (check[i][j] == BLACK)
			{
				ok[j] = BLACK;
				find(j);
				ok[j] = WHITE;
			}
		}
	ans+=char (i+'A');
	
}

main(){
	//freopen("in.inp","r",stdin);
	//freopen("out.out","w",stdout);
	string s[10000];
	int k = 1;
	int mn;
	
	while (cin >> s[0])
	{
		init();
		while (cin >> s[k])
		{
			if (s[k] == "#") break;
			for (int i = 0; i < s[k].size(); i++) a[s[k][i] - 'A'] = 1;
			k++;
		}
		
		for (int i = 1; i < k; i++) 
		{
			mn = min(s[i-1].size(), s[i].size());
			for (int j = 0; j < mn; j++)
			{
				if (s[i][j] != s[i-1][j]) 
				{
					check[s[i-1][j] - 'A'][s[i][j] - 'A'] = BLACK;
					break;
				}
			}
		}
		
		for (int i = 0; i < 26; i++)
			for (int j = 0; j < 26; j++)
				for (int k = 0; k < 26; k++)
					if (check[j][i] == BLACK && check[i][k] == BLACK) check[j][k] = BLACK;
	
		for (int i = 0; i < 26; i++)
			if (ok[i] == WHITE && a[i] != 0) 
			{
				ok [i] = BLACK;
				find(i);
				ok [i] = WHITE;
			}
				
		reverse(ans.begin(),ans.end());
		for (int i = 0; i < ans.size(); i++) cout << ans[i];
		//cout << ans.size();
		cout << endl;
		k = 1;
	}
}
