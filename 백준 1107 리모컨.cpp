//https://www.acmicpc.net/problem/1107
//2019.09.08 16:54~19:09
#include <iostream>
#include <queue>
#define START 100
using namespace std;
struct info {
	int C, T, LEN;	// 현재 채널, 누른 횟수
};
queue<info> Q;
int N, M, LENGTH, MIN;	// 목표 채널 번호, 못쓰는 리모컨 버튼
int BUTTON[10];
bool CAN[10];

void init() {
	cin >> N >> M;
	MIN = abs(START - N);
	for (int i = 0; i < 10; i++) {
		BUTTON[i]; CAN[i] = true;
	}

	for (int i = 0; i < M; i++) {
		int temp;
		cin >> temp;
		CAN[temp] = false;
	}
	int temp = N;
	while (temp) {
		temp /= 10;
		LENGTH++;
	}
}

void DFS(int C, int T, int L) {
	if (T >= MIN) return;
	if (C == N) {
		if (MIN > T) MIN = T;
		return;
	}

	int gap = abs(C - N);
	if (MIN > T + gap) MIN = T + gap;

	for (int i = 0; i < 10; i++) {
		if (CAN[i] && L <= LENGTH ) {
			if (i == 0 && C == 0) return;
			DFS(C * 10 + i, T + 1, L + 1);
		}
	}
	
}

void solution() {
	init();
	if (M == 10) {
		DFS(START, 0, 3);
	}
	else {
		for (int i = 0; i < 10; i++) 
			if (CAN[i]) DFS(i, 1, 1);
	}
	
	cout << MIN << endl;
}

int main() {
	solution();
}