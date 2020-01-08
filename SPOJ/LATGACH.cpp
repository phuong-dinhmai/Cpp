#include <bits/stdc++.h>
using namespace std;

string add(string b, string a)
{
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	while(a.size() < b.size()) a = a + "0";
	while (b.size() < a.size()) b = b + "0";
	string ans = "";
	int carry = 0;
	for (int i = 0; i < a.size(); i++)
	{
		carry = (a[i] + b[i] + carry - 96);
		ans = ans + (char)(carry % 10 + 48);
		carry /= 10;
	}
	if (carry > 0) ans = ans + (char)(carry % 10 + 48);
	reverse(ans.begin(), ans.end());
	return ans;
}

string f[101];

main(){
	int test;
	cin >> test;
	f[1] = "1";
	f[2] = "2";
	for (int i = 3; i <= 100; i++) 
	{
		f[i] = add(f[i-1], f[i-2]);
	}
	while (test--)
	{
		int n;
		cin >> n;
		cout << f[n] << endl;
	}
}
