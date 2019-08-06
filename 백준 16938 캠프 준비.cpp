/*
//https://www.acmicpc.net/problem/16938
#include <iostream>
using namespace std;

int PROBLEM[15];
int N, L, R, X, ANSWER;

void init() {
	ANSWER = 0;
	cin >> N >> L >> R >> X;
	for (int i = 0; i < N; i++)
		cin >> PROBLEM[i];
}

void DFS(int t, int next, int min, int max, int sum) {
	if (sum > R) return;
	if (t >= 2 && sum >= L && sum <= R) {
		int GAP = max - min;
		if (GAP >= X) ANSWER++;
	}

	for (int i = next; i < N; i++) {
		int sm = PROBLEM[i];
		int lm = sm;
		if (sm > min) sm = min;
		if (lm < max) lm = max;
		DFS(t + 1, i + 1, sm, lm, sum + PROBLEM[i]);
	}
}

int main() {
	init();
	DFS(0, 0, 1000001, 0, 0);
	cout << ANSWER << endl;
}
*/