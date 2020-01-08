#include <bits/stdc++.h>
#define WHITE 1
#define BLACK -1
#define vi vector <char>
using namespace std;

int check[30][30], ok[30],ans;
vi a;

void init()
{
	for (int i = 0; i < 30; i++) ok[i] = WHITE;
	for (int i = 0; i < 30; i++)
		for (int j = 0; j < 30; j++) check[i][j] = WHITE;
	a.clear();
	ans = 0;
}

bool order(int n, int k, string res)
{
	for (int i = 0; i < n; i++)
		if (check[k-'A'][res[i] - 'A'] == BLACK) return false;
	return true;
}

void topo(int n, string res)
{
	if (n == a.size())
	{
		ans++;
		for (int i = 0; i < res.size(); i++)
		{
			if (i != 0) cout << " ";
			cout << res[i];
		}	
		cout << endl;
	}
	else 
	{
		for (int i = 0; i < a.size(); i++)
			if (ok[i] == WHITE && order(n, a[i], res+a[i]))
			{
				ok[i] = BLACK;
				n++;
				topo(n,res+a[i]);
				n--;
				ok[i] = WHITE;
			}
	}
}

main(){
	//freopen("in.inp","r",stdin);
	//freopen ("out.out","w",stdout);
	int test;
	string s, ss;
	
	cin >> test;
	getchar();
	for (int k = 0; k < test; k++)
	{
		init(); 
		getchar();
		
		if (k != 0) cout << endl;
		getline(cin,s);
		for (int i = 0; i < s.size(); i++)
			if (s[i] != ' ') a.push_back(s[i]);
		getline(cin, ss);
		for (int i = 0; i < ss.size()-2; i+=4)
		{
			check[ss[i] - 'A'][ss[i+2] - 'A'] = BLACK;
		}
		
		topo(0,"");
		//cout << ans << endl;
		if (ans == 0) cout << "NO" << endl;
	}
}
