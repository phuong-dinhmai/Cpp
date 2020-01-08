#include <bits/stdc++.h>
#define vc vector <char>
#define vcc vector <vc>
using namespace std;

int n;
vcc a, b;
int re, ro;
int test = 0;

bool check(vcc a, vcc b)
{
	for (int i = 0; i < a.size(); i++)
		for (int j = 0; j < a[i].size(); j++)
		{
			if (a[i][j] != b[i][j]) return false;
		}
	return true;
}

void rotate()
{
	for (int i = 0; i < (n/2); i++)
		for (int j = 0; j < ((n+1)/2); j++)
		{
			char c = a[i][j];
			a[i][j] = a[n - j - 1][i];
			a[n - j - 1][i] = a[n - i - 1][n - j - 1];
			a[n - i - 1][n - j - 1] = a[j][n - i - 1];
			a[j][n - i - 1] = c;
		}
}

void reflect()
{
	for (int i = 0; i < (n/2); i++)
		for (int j = 0; j < n; j++) 
			swap(a[i][j], a[n-i-1][j]);
}

void sol()
{
	while(re < 2)
	{
		while (ro < 4)
		{
			if (a == b) return;
			rotate();
			ro++;
		}
		ro = 0;
		reflect();
		re++;
	}
}

main(){
	//freopen("in.inp","r",stdin);
	//freopen("out.out","w",stdout);
	while (cin >> n)
	{
		test++;
		a.assign(n, vc());
		b.assign(n, vc());
		for (int i = 0; i < n; i++)
		{
			a[i].assign(n, '-');
			b[i].assign(n, '-');
			for (int j = 0; j < n; j++) cin >> a[i][j];
			getchar();
			for (int j = 0; j < n; j++) cin >> b[i][j];
		}
		re = 0; ro = 0;
		sol();
		cout << "Pattern" << " " << test << " " << "was" << " ";
		if (re == 0)
		{
			if (ro == 0) cout << "preserved." << endl;
			else cout << "rotated " << 90*ro << " degrees." << endl;
		} 
		else if (re == 1)
		{
			cout << "reflected vertically";
			if (ro == 0) cout << "." << endl; else cout << " and rotated " << 90*ro << " degrees." << endl; 
		} else cout << "improperly transformed." << endl;
	}
}
