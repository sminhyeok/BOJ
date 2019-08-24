//https://www.acmicpc.net/problem/14501
//2019.08.17 18:58~19:47
#include <iostream>
using namespace std;
int DP[16], T[16], P[16];
int N;

int max(int a, int b) { return a > b ? a : b; }

void init() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> T[i] >> P[i];
		DP[i] = 0;
	}
	DP[N] = 0;
}

void dynamic() {
	for (int i = 0; i < N; i++) {
		int time = T[i] + i;
		int p = P[i] + DP[i];
		for (int t = time; t <= N; t++) 
			DP[t] = max(DP[t], p);
	}
}

void solution() {
	init();
	dynamic();
	cout << DP[N] << endl;
}

int main() {
	solution();
}