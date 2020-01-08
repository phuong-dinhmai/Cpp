#include <iostream>
#include <random>
using namespace std;

typedef long long ll;
random_device rd;
const int BILL = 1e9;

ll nxt() { return ll(rd()%BILL) * BILL + rd()%BILL; }

int main() {
	cout << nxt() << ' ' << rd()%100 + 1 << endl;

}