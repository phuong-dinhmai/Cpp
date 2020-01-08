#include <bits/stdc++.h>
#define vi vector <int>
using namespace std;

int gcd(int a, int b)
{
	return (b == 0? a: gcd(b, a%b));
}

map <int, int> ans;
vi res;

main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n*n; i++) 
	{
		int x;
		cin >> x;
		ans[x]++;
	}
	for (map <int, int> :: reverse_iterator i = ans.rbegin(); i != ans.rend(); )
	{	
		if (i->second > 0)
		{
			res.push_back(i->first);
			for (int j = 0; j < res.size(); j++)
				ans[gcd(i->first, res[j])] -= 2;
		}
		else i++;
	}
	for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
	cout << endl;
}
