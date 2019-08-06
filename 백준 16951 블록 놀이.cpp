/*
//https://www.acmicpc.net/problem/16951
// 2019.08.04 15:18~16:38
#include <iostream>
#include <queue>
using namespace std;
struct info {
	int height, time, index;
};
int BLOCK[1000];	// 블록들의 높이
int N, K;	// 블록 수, 블록 간 높이 차
int MIN;

void init() {

	cin >> N >> K;
	MIN = N;
	for (int i = 0; i < N; i++)
		cin >> BLOCK[i];
}

void BFS(int n) {
	int total = 0;
	int num = BLOCK[n];
	if (num - n * K <= 0)	return;

	for (int i = n - 1; i >= 0; i--) {
		num -= K;
		if (num != BLOCK[i]) total++;
		if (total >= MIN) return;
	}

	num = BLOCK[n];
	for (int i = n + 1; i < N; i++) {
		num += K;
		if (num != BLOCK[i]) total++;
		if (total >= MIN) return;
	}
	if (total < MIN) MIN = total;
}

void solutuion() {
	for (int i = 0; i < N; i++) BFS(i);
	cout << MIN << endl;
}

int main() {
	init();
	solutuion();
}
*/