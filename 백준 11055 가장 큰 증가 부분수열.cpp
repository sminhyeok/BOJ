//https://www.acmicpc.net/problem/11055
//2019.08.21 12:10~12:29
#include <iostream>
using namespace std;
int NUM[1000], DP[1000];
int N,MAX;

int max(int a, int b) { return a > b ? a : b; }

void init() {
	MAX = 0;
	cin >> N; 
	for (int i = 0; i < N; i++) {
		cin >> NUM[i];
		DP[i] = NUM[i];
		if (NUM[i] > MAX) MAX = NUM[i];
	}
}

void dynamic() {
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (NUM[i] < NUM[j]) {
				DP[j] = max(DP[j], DP[i] + NUM[j]);
			}	
		}
		if (DP[i] > MAX) MAX = DP[i];
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