#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll mod=1000000007;

int main() {
	string str;
	ll n;
	while(cin >> str >> n) {
		ll x = str.size(),p=1;
		for (ll i=0; i<x; i++) p=(p*2)%mod;
        p=(mod+p-1)%mod;
        p=(p*n)%mod;
        cout << p << endl;
	}
}