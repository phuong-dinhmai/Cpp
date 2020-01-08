#include <iostream>
#include <random>
#include <set>
using namespace std;

typedef pair<int, int> ii;
random_device rd;

int pnt() { return int(rd()%201) - 100; }
set<ii> S;

int main() {
	int n = 12 + rd()%13; 
	int fx = pnt(), fy = pnt();
	S.insert(ii(fx, fy));
	cout << fx << ' ' << fy << ' ' << n << endl;
	for (int i = 0; i < n; ++i) {
		int x, y; do { x = pnt(), y = pnt(); } while (S.count(ii(x, y)));
		S.insert(ii(x, y)); cout << x << ' ' << y << endl;
	}

}