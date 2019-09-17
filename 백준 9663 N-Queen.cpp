//https://www.acmicpc.net/problem/9663
//2019.09.17 17:40~17:56
#include <iostream>
using namespace std;

int LINE[16];
bool USE[16];
int N, ANSWER;

void init() {
	cin >> N;
	ANSWER = 0;
	for (int i = 0; i <= 15; i++) {
		LINE[i] = 0;
		USE[i] = false;
	}
}

bool check(int index) {
	for (int i = 1; i < index; i++) {
		// 같은 Y에 있을 때
		if (LINE[i] == LINE[index]) return false;
		// 같은 대각선에 있을 때
		if (abs(LINE[i] - LINE[index]) == index - i) return false;
	}
	return true;
}

void DFS(int index) {
	if (index == N + 1) {
		ANSWER++;
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (!USE[i]) {
			USE[i] = true;
			LINE[index] = i;
			if (check(index)) DFS(index + 1);
			USE[i] = false;
		}
	}
}

void solution() {
	init();
	DFS(1);
	cout << ANSWER << endl;
}

int main() {
	solution();
}