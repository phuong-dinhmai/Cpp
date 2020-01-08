#include <bits/stdc++.h>
#define vi vector <int>
using namespace std;

string s, str, ans = "";
vi dig(10, 0);
int n;

int num_dig(int num)
{
	int cnt = 0;
	while (num > 0)
	{
		num /= 10;
		cnt++;
	}
	return cnt;
}

void check(int num, vi dig)
{
	int x = num;
	while (num > 0)
	{
		dig[num%10]--;
		num /= 10;
	}
	string res = "";
	if (s[0] != '0')
	{
		res = s;
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < dig[i]; j++) res += (char) (i + '0');
		if (res.size() < ans.size() || (res.size() == ans.size() && res < ans) || ans == "") ans = res;
	}
	res = "";
	int k = 1;
	while (!dig[k] && k < 10) k++;
	if (k != 10) res = (char) k + '0';
	if (res.size() == 0) 
	{
		if (ans != "") cout << ans << endl;
		exit(0);
	}
	dig[k]--;
	k = 0;
	for (int i = 1; i < s.size(); i++) 
		if (s[i] != s[0])
		{
			k = (s[0] > s[i]? 0 : 1);
			break;
		}
	for (int i = 0; i < s[0] - '0' + k; i++)
	{
		for (int j = 0; j < dig[i]; j++) res += (char)(i + '0');
	}
	res = res + s;
	for (int i = s[0] - '0' + k; i < 10; i++) 
	{
		for (int j = 0; j < dig[i]; j++) res += (char)(i + '0');
	}
	if (res.size() < ans.size() || (res.size() == ans.size() && res < ans) || ans == "") ans = res;
	cout << ans << endl;
	exit(0);
}

main(){
	//freopen("in.inp","r",stdin);
	//freopen("out.out","w",stdout);
	cin >> str >> s;
	n = str.size();
	for (int i = 0; i < n; i++) dig[str[i] - '0']++;
	for (int i = 0; i < s.size(); i++) 
	{
		dig[s[i] - '0']--;
	}
	if (str.size() == 2 && s.size() == 1)
	{
		cout << s << endl;
		return 0;
	}
	int num = 0;
	for (int i = 7; i > 0; i--)
	{
		if (num_dig(n - i) == i) 
		{
			num = i;
			break;
		}
	}
	//cout << n-num << endl;
	check(n-num, dig);
}
