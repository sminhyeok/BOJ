//https://www.acmicpc.net/problem/1699
//2019.08.20 13:39~14:19
#include <iostream>
#include <cmath>
using namespace std;
int DP[100001];
int N;

int min(int a, int b) { return a < b ? a : b; }

void init() {
	cin >> N;
	for (int i = 1; i <= N; i++)
		DP[i] = 100001;
}

void dynamic() {
	DP[1] = 1; DP[2] = 2; DP[3] = 3;
	for (int i = 4; i <= N; i++) {
		int temp = sqrt(i);
		if (temp * temp == i) DP[i] = 1;
		else {
			for (int j = temp; j >= 1; j--) 
				DP[i] = min(DP[i], DP[j*j] + DP[i - j*j]);
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