//https://www.acmicpc.net/problem/1965
//2019.08.25 13:08~13:20
#include <iostream>
using namespace std;
int DP[1001], BOX[1001], N;

int max(int a, int b) { return a > b ? a : b; }

void init() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> BOX[i];
		DP[i] = 1;
	}
		
}

int dynamic() {
	int MAX = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			if(BOX[i] < BOX[j])
				DP[j] = max(DP[j], DP[i] + 1);
		}
		MAX = max(MAX, DP[i]);
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