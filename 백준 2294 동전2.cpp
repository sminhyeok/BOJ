//https://www.acmicpc.net/problem/2294
//2019.08.19 12:57~13:19
#include <iostream>
#define MAX 10001
using namespace std;

int DP[10001], COIN[100];
int N, K;

int min(int a, int b) { return a < b ? a : b; }

void init() {
	cin >> N >> K;
	for (int i = 0; i < N; i++)
		cin >> COIN[i];
	for (int i = 1; i <= K; i++)
		DP[i] = MAX;
}

void dynamic() {
	for (int i = 0; i < N; i++) {
		for (int index = COIN[i]; index <= K; index++) {
			DP[index] = min(DP[index], DP[index - COIN[i]] + 1);
		}
	}
}

void solution() {
	init();
	dynamic();
	if (DP[K] != MAX) cout << DP[K] << endl;
	else cout << -1 << endl;
}

int main() {
	solution();
}