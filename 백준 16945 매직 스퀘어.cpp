/*
//https://www.acmicpc.net/problem/16945
// 2019.08.02 20:46~21:06
#include <iostream>
using namespace std;
int NUM[9], MIN;
bool USE[10];
bool check() {
	int A = NUM[0] + NUM[1] + NUM[2];
	if (A != NUM[3] + NUM[4] + NUM[5]) return false;
	if (A != NUM[6] + NUM[7] + NUM[8]) return false;
	if (A != NUM[0] + NUM[3] + NUM[6]) return false;
	if (A != NUM[1] + NUM[4] + NUM[7]) return false;
	if (A != NUM[2] + NUM[5] + NUM[8]) return false;
	if (A != NUM[0] + NUM[4] + NUM[8]) return false;
	if (A != NUM[2] + NUM[4] + NUM[6]) return false;
	return true;
}

void init() {
	MIN = 100;
	for (int i = 0; i < 9; i++) {
		cin >> NUM[i];
		USE[i + 1] = false;

	}
}

void DFS(int t, int total) {
	if (total >= MIN) return;
	if (t == 9) {
		if (check())
			if (MIN > total) MIN = total;
		return;
	}

	for (int i = 1; i <= 9; i++) {
		if (!USE[i]) {
			USE[i] = true;
			int temp = NUM[t];
			NUM[t] = i;
			DFS(t + 1, total + abs(temp - i));
			USE[i] = false;
			NUM[t] = temp;
		}
	}
}

int main() {
	init();
	DFS(0, 0);
	cout << MIN << endl;
}
*/