#include <bits/stdc++.h>
#define WHITE 1
#define BLACK -1
#define vi vector <char>
using namespace std;

vi a;
string s,ss;
int check[30][30],ok[30];

void init()
{
	a.clear();
	for (int i = 0; i < 30; i++)
		for (int j = 0; j < 30; j++) check[i][j] = WHITE;
	for (int i = 0; i < 30; i++) ok[i] = WHITE;
}

bool order(int n, int k, string res)
{
	for (int i = 0; i < n; i++)
		if (check[k - 'a'][res[i] - 'a'] == BLACK) return false;
	return true;
}

void topo(int n,string res)
{
	if (n == a.size())
		cout << res << endl;
	else
	{
		for (int i = 0; i < a.size(); i++)
			if (ok[i] == WHITE && order(n, a[i],res+a[i]))
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
	//freopen("out.out","w",stdout);
	
	bool blank = false;
	while (getline(cin, s))
	{
		init();
		if (blank) cout << endl;
		for (int i = 0; i < s.size(); i++)
			if (s[i] != ' ') a.push_back(s[i]);
		sort(a.begin(),a.end());
		
		getline(cin, ss);
		for (int i = 0; i < ss.size()-2; i+=4)
		{
			check[ss[i] - 'a'][ss[i+2] - 'a'] = BLACK;
		}
		
		topo(0,"");
		
		blank = true;
	}
}
