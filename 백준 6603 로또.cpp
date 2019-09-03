//https://www.acmicpc.net/problem/6603
//2019.09.03 15:29~15:40
#include <iostream>
#define LOTTO 6
using namespace std;
int NUM[13], K;
int ANSWER[6];

void init() {
	for (int i = 0; i < K; i++)
		cin >> NUM[i];
}

void print() {
	for (int i = 0; i < LOTTO; i++)
		cout << ANSWER[i] << " ";
	cout << endl;
}

void DFS(int next, int choose) {
	if (choose == LOTTO) {
		print(); return;
	}

	for (int i = next; i <= K + choose - LOTTO; i++) {
		ANSWER[choose] = NUM[i];
		DFS(i + 1, choose + 1);
	}
}

void solution() {
	cin >> K;
	while (K != 0) {
		init();
		DFS(0, 0);
		cout << endl;
		cin >> K;
	}
}

int main() {
	solution();
}