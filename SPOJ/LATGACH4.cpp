#include <bits/stdc++.h>
#define ll long long
#define vi vector <ll>
#define mod (ll) (111539786)
using namespace std;

ll n, test;
vi bi;
ll bs[2][2] = {0, 1, 1, 1};
ll c[2][2] = {0, 0, 0, 0};
ll d[2][2] = {0, 0, 0, 0};
ll f[2][2] = {0, 0, 0, 0};

main(){
	cin >> test;
	while (test--)
	{
		cin >> n;
		bi.clear();
		while (n > 1)
		{
			bi.push_back(n % 2);
			n /= 2;
		}
		reverse(bi.begin(), bi.end());
		for (ll i = 0; i < 2; i++)
			for (ll j = 0; j < 2; j++) {f[i][j] = bs[i][j];}
		for (ll l = 0; l < bi.size(); l++)
		{
			for (ll i = 0; i < 2; i++)
					for (ll j = 0; j < 2; j++) {c[i][j] = 0;}
			for (ll i = 0; i < 2; i++)
					for (ll j = 0; j < 2; j++) {d[i][j] = 0;}
			for (ll i = 0; i < 2; i++)
				for (ll j = 0; j < 2; j++) 
					for (ll k = 0; k < 2; k++) c[i][j] = (c[i][j] + (f[i][k]*f[k][j]%mod))%mod;
			if (bi[l]) 
				for (ll i = 0; i < 2; i++)
					for (ll j = 0; j < 2; j++) 
						for (ll k = 0; k < 2; k++) d[i][j] = (d[i][j] + (c[i][k]*bs[k][j]%mod))%mod;
			if (bi[l] == 0) 
			{
				for (ll i = 0; i < 2; i++)
					for (ll j = 0; j < 2; j++) {f[i][j] = c[i][j];}
			} 
			else 
			{
				for (ll i = 0; i < 2; i++)
					for (ll j = 0; j < 2; j++) {f[i][j] = d[i][j];}
			}
		}
		/*for (ll i = 0; i < 2; i++)
			for (ll j = 0; j < 2; j++) cout << f[i][j] << endl;*/
		cout << f[1][1] << endl;
	}
}
