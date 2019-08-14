//https://www.acmicpc.net/problem/16936
//2019.08.09 17:55~18:30
#include <iostream>
#include <algorithm>
#define MAX 100
using namespace std;
unsigned long long NUM[MAX], ANSWER[MAX];
int N, FLAG;

void init() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> NUM[i];
	FLAG = false;
	sort(NUM, NUM + N);
}

bool check(unsigned long long n) {
	if (n > NUM[N - 1]) return false;
	for (int i = 0; i < N; i++) {
		if (NUM[i] == n) return true;
		if (n < NUM[i]) return false;
	}
}

void DFS(unsigned long long n, int t) {
	if (t == N) {
		FLAG = true;
		return;
	}
	if (FLAG) return;

	if (n % 3 == 0 && check(n/3)) {
		ANSWER[t] = n / 3;
		DFS(n / 3, t + 1);
	}
	if (FLAG) return;
	if (check(n * 2)) {
		ANSWER[t] = n * 2;
		DFS(n * 2, t + 1);
	}
}

void print() {
	for (int i = 0; i < N; i++)
		cout << ANSWER[i] << " ";
}

void solution() {
	init();
	for (int i = 0; i < N; i++) 
		if (!FLAG) {
			ANSWER[0] = NUM[i];
			DFS(NUM[i], 1);
		}
	print();
}

int main() {
	solution();
}