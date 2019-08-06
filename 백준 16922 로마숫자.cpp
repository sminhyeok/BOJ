/*
//https://www.acmicpc.net/problem/16922
// 2019.08.01 17:53~18:05
#include <iostream>
using namespace std;

int ANSWER;
int N, LINE[20], NUM[4] = { 1,5,10,50 };
bool USE[1001] = { false };

void init() {
	ANSWER = 0;
	cin >> N;
}

void DFS(int t, int sum, int next) {
	if (t >= N) {
		if (!USE[sum]) {
			ANSWER++; USE[sum] = true;
		}
		return;
	}
	for (int i = next; i < 4; i++) {
		DFS(t + 1, sum + NUM[i], i);
	}
}

int main() {
	init();
	DFS(0, 0, 0);
	cout << ANSWER << endl;
}
*/