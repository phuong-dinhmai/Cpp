#include <bits/stdc++.h>
#define ll long long 
#define maxN 10005
using namespace std;

ll f[maxN];
ll n;

void F()
{
	for (int i = 1; i < 22; i++)
	{
		int cube = i * i * i;
		f[cube] += 1;
		for (int j = 1; j < maxN; j++) 
		{
			if (cube <= j) f[j] += f[j-cube];
		}
	}
}

main(){
	//freopen("in.inp","r",stdin);
	ios_base :: sync_with_stdio(false);
	for (int i = 0; i < maxN; i++) f[i] = 0;
	F();
	while(cin >> n)
	{
		printf("%lld\n", f[n]);
	}
}
