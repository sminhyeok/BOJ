//https://www.acmicpc.net/problem/11054
//2019.08.22 12:00~12:43
#include <iostream>
using namespace std;

int NUM[1000], DP[1000];
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
	int result = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (NUM[i] < NUM[j]) DP[j] = max(DP[j], DP[i] + 1);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (NUM[i] > NUM[j]) DP[j] = max(DP[j], DP[i] + 1);
		}
		result = max(result, DP[i]);
	}
	return result;
}

void solution() {
	init();
	cout << dynamic() << endl;
}

int main() {
	solution();
}