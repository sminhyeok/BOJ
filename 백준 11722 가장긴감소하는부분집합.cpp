//https://www.acmicpc.net/problem/11722
//2019.08.21 19:37~19:46
#include <iostream>
using namespace std;
int NUM[1001], DP[1001];
int N;

int max(int a, int b) { return a > b ? a : b; }

void init() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> NUM[i];
		DP[i] = 1;
	}
}

int dynamic() {
	int MAX = 1;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) 
			if (NUM[i] > NUM[j]) DP[j] = max(DP[j], DP[i] + 1);
		if (MAX < DP[i]) MAX = DP[i];
	}
	return MAX;
}

void solution() {
	init();
	cout << dynamic() << endl;
}

int main() {
	solution();
}