//https://www.acmicpc.net/problem/4948
//2019.08.27 10:21~10:40
#include <iostream>
#define MAX 123456
using namespace std;

bool CHECK[250000];
int N;

void init() {
	cin >> N;
}

void calc() {
	for (int i = 1; i <= 2 * MAX; i++)
		CHECK[i] = false;
	for (int i = 2; i <= 2 * MAX; i++) {
		if (!CHECK[i]) {
			for (int j = 2 * i; j <= 2 * MAX; j += i)
				CHECK[j] = true;
		}
	}
}

int find() {
	int answer = 0;
	for (int i = N+1; i <= 2 * N; i++)
		if (!CHECK[i]) answer++;
	return answer;
}

void solution() {
	calc();
	while (1) {
		init();
		if (N != 0) cout << find() << endl;
		else return;
	}
	
	
}

int main() {
	solution();
}