#include <bits/stdc++.h>
using namespace std;

string b, str;
int n;

main(){
	freopen("CHUTE.inp","r",stdin);
	freopen("CHUTE.out","w",stdout);
	ios_base :: sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		char ch;
		cin >> ch;
		str += ch;
		b += ch;
	}
	
	sort(b.begin(), b.end());
	//cout << str << endl;
	
	for (int i = 0; i < n; i++)
	{
		int pos = i;
		while (str[pos] != b[i]) pos++;
		if (pos == i) continue;
		int k = (pos - i) % 3;
		//cout << pos << " " << k << " " << (n - pos - 1) % 3 << endl;
		if (k == 0)
		{
			for (int j = i; j < pos; j += 3) printf("%d\n", i+1);
			string a;
			a = str.substr(i, (pos - i));
			str.erase(i, (pos - i));
			str += a;
			//cout << str << endl;
		}
		else
		{
			string a;
			int x = (n - pos - 1) % 3;
			if (pos == n-1)
			{
				for (int j = i+3; j < pos; j += 3) printf("%d\n", i+1);
				pos = (n - 1) % 3;
				a = str.substr(i, (n - 1 - pos));
				str.erase(i, (n - 1 - pos));
				//cout << a << endl;
				str += a;
				//cout << str << endl;
			}
			if (((x == 2 && k == 2) || (x == 0 && k == 1)) && pos != n-1)
			{
				printf("%d\n", pos);
				a = str.substr(pos-1, 3);
				//cout << a << endl;
				str.erase(pos-1, 3);
				str += a;
				pos = n - 2;
			} 
			else if (((x == 1 && k == 1) || (x == 0 && k == 2)) && pos != n-1)
			{
				printf("%d\n", pos+1);
				a = str.substr(pos, 3);
				//cout << a << endl;
				str.erase(pos, 3);
				str += a;
				pos = n - 3;
			}
			else if (x == 1 && k == 2)
			{
				printf("%d\n", pos - 1);
				a = str.substr(pos-2, 3);
				//cout << a << endl;
				str.erase(pos-2, 3);
				str += a;
				pos = n - 1;
			} 
			else if (x == 2 && k == 1 )
			{
				printf("%d\n", pos+1);
				a = str.substr(pos, 3);
				//cout << a << endl;
				str.erase(pos, 3);
				str += a;
				pos = n - 3;
				//cout << str << endl;
				printf("%d\n", pos - 1);
				a = str.substr(pos-2, 3);
				//cout << a << endl;
				str.erase(pos-2, 3);
				str += a;
				pos = n - 1;
			}
			//cout << str << endl;
			if (str[i] == b[i]) continue;
			for (int j = i; j < pos; j += 3) printf("%d\n", i+1);
			a = str.substr(i, (pos - i));
			str.erase(i, (pos - i));
			str += a;
			//cout << str << endl;
		}
	}
}
