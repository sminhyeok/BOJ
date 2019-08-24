//https://www.acmicpc.net/problem/2293
//2019.08.17 19:52~
#include <iostream>
using namespace std;
int NUM[100], N, K;
unsigned long long DP[100001];

void init() {
	DP[0] = 1;
	cin >> N >> K;
	for (int i = 0; i < N; i++)
		cin >> NUM[i];
}

void dynamic() {
	for (int i = 0; i < N; i++) {
		for (int j = NUM[i]; j <= K; j++)
			DP[j] += DP[j - NUM[i]];
	}
}

void solution() {
	init();
	dynamic();
	cout << DP[K] << endl;
}

int main() {
	solution();
}