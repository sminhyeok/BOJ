//https://www.acmicpc.net/problem/2798
//2019.08.28 08:56~09:27
#include <iostream>
#include <algorithm>>
#define MAX 100
using namespace std;

int CARD[MAX], N, M;
int ANSWER;

void init() {
	ANSWER = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> CARD[i];
	sort(CARD, CARD + N);
}

void DFS(int n, int index, int total) {
	if (total > M) return;
	if (n == 3) {
		if (total > ANSWER) ANSWER = total;
		return;
	}

	for (int i = index; i < N; i++) {
		DFS(n + 1, i + 1, total + CARD[i]);
	}
}

void solution() {
	init();
	DFS(0, 0, 0);
	cout << ANSWER << endl;
}

int main() {
	solution();
}