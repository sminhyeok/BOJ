/*
//https://www.acmicpc.net/problem/17088
//2019.08.06 18:19~19:19
#include <iostream>
#define MAX 100000
using namespace std;
unsigned long long INPUT[MAX];

int N, MIN;

void init() {
	MIN = MAX;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> INPUT[i];

}
void DFS(int index, long long gap, int change) {
	if (index == N) {
		if (change < MIN) MIN = change;
		return;
	}

	for (int i = -1; i <= 1; i++) {
		INPUT[index] += i;
		if (INPUT[index] - INPUT[index - 1] == gap) DFS(index + 1, gap, change + abs(i));
		INPUT[index] -= i;
	}
}

// 처음 1과 0자리를 기준으로 등차수열 가능여부 및 계산 - 1과 0자리가 더해지는 것 부터 빼는것까지 경우의 수 * 고정된 GAP으로 탐색
void solution() {
	init();
	if (N <= 2) { cout << 0 << endl; return; }

	int CHANGE;
	for (int A = -1; A <= 1; A++) {
		if (A != 0) CHANGE = 1;
		else CHANGE = 0;
		INPUT[0] += A;
		for (int B = -1; B <= 1; B++) {
			if (B != 0) CHANGE++;
			else CHANGE--;
			INPUT[1] += B;
			long long GAP = INPUT[1] - INPUT[0];
			DFS(2, GAP, CHANGE);	// 구동
			INPUT[1] -= B;
		}
		INPUT[0] -= A;
	}
	if (MIN == MAX) cout << -1 << endl;
	else cout << MIN << endl;
}

int main() {
	solution();
}
*/