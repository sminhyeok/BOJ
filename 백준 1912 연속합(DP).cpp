/*
//https://www.acmicpc.net/problem/1912
#include <iostream>
using namespace std;

int max(int a, int b) { return a > b ? a : b; }

long long DP[100000];
int NUM[100000];

int main() {
	long long MAX = -100000000;
	int N;
	cin >> N >> NUM[0];
	DP[0] = NUM[0];
	if (DP[0] > MAX) MAX = DP[0];
	if (DP[0] < 0) DP[0] = 0;

	for (int i = 1; i < N; i++) {
		cin >> NUM[i];
		DP[i] = DP[i - 1] + NUM[i];

		if (DP[i] > MAX) MAX = DP[i];
		if (DP[i] <= 0) DP[i] = 0;
	}

	cout << MAX << endl;
}
*/