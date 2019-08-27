//https://www.acmicpc.net/problem/1904
//2019.08.26 10:43~10:57
#include <iostream>
#define DIV 15746
using namespace std;

int DP[1000001];
int N;

void init() {
	cin >> N;
	DP[1] = 1; DP[2] = 2;
}

int dynamic() {
	for (int i = 3; i <= N; i++) {
		DP[i] = (DP[i - 1] + DP[i - 2]) %DIV;
	}
	return DP[N];
}

void solution() {
	init();
	cout << dynamic();
}

int main() {
	solution();
}