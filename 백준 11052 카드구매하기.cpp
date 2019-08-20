//https://www.acmicpc.net/problem/11052
//2019.08.15 20:09~20:24
#include <iostream>
using namespace std;
int DP[1001], PRICE[1001];
int N;

int max(int a, int b) { return a > b ? a : b; }

void init() {
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> PRICE[i];
}

void dynamic() {
	for (int i = 1; i <= N; i++) {
		DP[i] = PRICE[i];
		for (int j = 1; j <= i/2; j++) {
			DP[i] = max(DP[i], DP[j] + DP[i - j]);
		}
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