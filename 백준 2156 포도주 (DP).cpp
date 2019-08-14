/*
//https://www.acmicpc.net/problem/2156
#include <iostream>
using namespace std;

int DP[10000],GLASS[10000];

int max(int a, int b, int c) { return a > b ? a > c ? a : c : b > c ? b : c; }

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> GLASS[i];
	DP[0] = GLASS[0];
	if (N > 1) DP[1] = DP[0] + GLASS[1];
	if (N >= 2) DP[2] = max(DP[0] + GLASS[2], DP[1], GLASS[1] + GLASS[2]);

	for (int i = 3; i < N; i++)
		DP[i] = max(DP[i - 3] + GLASS[i - 1] + GLASS[i], DP[i - 2] + GLASS[i], DP[i - 1]);
	cout << DP[N - 1] << endl;

}
*/