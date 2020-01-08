#include <bits/stdc++.h>
#define vi vector <int>
using namespace std;

vi a, b;
int n;

void change(int start, int en)
{
	for (int i = start; i <= en; i += 2) swap(a[i], a[i+1]);
}

main(){
	//freopen("in.inp","r",stdin);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		a.push_back(x);
	}
	b = a;
	sort(b.begin(), b.end());
	
	for (int i = 0; i < n; i++)
	{
		int pos;
		for (int j = i; j < n; j++)
		{
			if (a[j] == b[i]) 
			{
				pos = j;
				break;
			}
		}
		if (pos == i) continue;
		if ((pos - i) % 2 == 0) 
			if (pos != 0) swap(a[pos], a[pos-1]), cout << pos << " " << pos+1 << endl, pos--; 
			else swap(a[pos], a[pos+1]), cout << pos+1 << " " << pos+2 << endl, pos++;
		
		while (b[i] != a[i] && pos >= 0) swap(a[pos], a[pos-1]), pos--, cout << pos+1 << " " << pos+2 << endl;
	}
//	for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
}
