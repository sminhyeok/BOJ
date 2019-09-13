//https://www.acmicpc.net/problem/10871
//2019.09.013 19:43~19:47
#include <iostream>
using namespace std;

int ANSWER[10000];
int X, N, NA;

void init() {
	cin >> N >> X;
	NA = 0;
}

void solution() {
	init();
	for (int i = 0; i < N; i++) {
		int NUM; cin >> NUM;
		if (NUM < X) ANSWER[NA++] = NUM;
	}

	for (int i = 0; i < NA; i++)
		cout << ANSWER[i] << " ";
}

int main() {
	solution();
}