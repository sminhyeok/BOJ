//https://www.acmicpc.net/problem/11053
//2019.08.16 15:26~15:35
#include <iostream>
using namespace std;

int DP[1000], NUM[1000];
int N, MAX;

int max(int a, int b) { return a >= b ? a : b; }

void init() {
	MAX = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> NUM[i]; DP[i] = 1;
	}
}

void dynamic() {
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (NUM[j] > NUM[i]) DP[j] = max(DP[j], DP[i] + 1);
		}
		MAX = max(MAX, DP[i]);
	}
}

void solution() {
	init();
	dynamic();
	cout << MAX << endl;
}

int main() {
	solution();
}