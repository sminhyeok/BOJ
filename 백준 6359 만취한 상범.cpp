//https://www.acmicpc.net/problem/6359
//2019.08.26 11:13~11:22
#include <iostream>
using namespace std;
bool ROOM[101];
int N;

void init() {
	cin >> N;
	for (int i = 1; i <= N; i++)
		ROOM[i] = false;
}

void simulation() {
	for (int k = 1; k <= N; k++) {
		for (int i = k; i <= N; i += k) {
			ROOM[i] = !ROOM[i];
		}
	}
}

int check() {
	int open = 0;
	for (int i = 1; i <= N; i++)
		if (ROOM[i]) open++;
	return open;
}

void solution() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		init();
		simulation();
		cout << check() << endl;
	}
}

int main() {
	solution();
}