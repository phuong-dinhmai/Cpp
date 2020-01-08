#include <iostream>
#include <fstream>
using namespace std;

int dist(int x, int y, int z, int t) {
	return (x - z) * (x - z) + (y - t) * (y - t);
}

int x, y, n;
int X[30], Y[30];

int main() {
	string inf, ouf; getline(cin, inf); getline(cin, ouf);
	fstream fin(inf + "lena.inp"), fout(ouf + "lena.out"), fans(inf + "lena.out");
	fin >> X[0] >> Y[0] >> n;
	for (int i = 1; i <= n; ++i)	fin >> X[i] >> Y[i];
	int out, ans; if (!(fout >> out)) return cout << "Error Underflow\n0.0" << endl, 0;
	fans >> ans; if (out != ans) return cout << "Wrong answer jury has better answer\n0.0" << endl, 0;
	if (!(fout >> out)) return cout << "Error Underflow\n0.0" << endl, 0;
	if (out != 0) return cout << "Wrong answer starting point not 0\n0.0" << endl, 0;
	int St[2], num = 0, done = 0, total = 0, last = 0;
	while (fout >> out) {
		if (out < 0 || out > n) return cout << "Wrong answer point out of range [1..n]\n0.0" << endl, 0;
		total += dist(X[out], Y[out], X[last], Y[last]); 
		if (out == 0) { while (num > 0) done |= (1 << St[--num]); last = out; continue; }
		if (done & (1 << out)) return cout << "Wrong answer visiting point twice\n0.0" << endl, 0;
		if (num == 2) return cout << "Wrong answer bag is already full\n0.0" << endl, 0;
		St[num++] = out; last = out;
	} 
	if (out != 0) return cout << "Wrong answer ending point not 0\n0.0" << endl, 0;
	if (done != ((1 << (n + 1)) - 2)) return cout << "Wrong answer did not pick up all items\n0.0" << endl, 0;
	if (total != ans) return cout << "Wrong answer given path is not optimal, expected " << ans << " got " << total << "\n0.0" << endl, 0;
	cout << "Correct path\n1.0" << endl;
}