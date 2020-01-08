#include <bits/stdc++.h>
#define vi vector <int>
#define vs vector <string>
using namespace std;

int test, n;
string line;
vi a;
vs st;
string x;

main(){
	//freopen("in.inp","r",stdin);
	//freopen("out.out","w",stdout);
	cin >> test;
	getchar();
	getchar();
	while (test--)
	{
		a.clear();
		st.clear();
		getline(cin, line);
		stringstream ss (line);
		while(ss >> n)
		{
			a.push_back(n);
		}
		getline(cin, line);
		int i = 0;
		stringstream s (line);
		while (s >> x)
		{
			st.push_back(x);
		}
		//cout << a.size() << endl;
		vs res(st.size(), "");
		for (int i = 0; i < st.size(); i++)
		{
			res[a[i] - 1] = st[i];
		}
		for (int i = 0; i < st.size(); i++) cout << res[i] << endl;
		if (test) cout << endl;
		getchar();
	}
}
