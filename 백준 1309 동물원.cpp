//https://www.acmicpc.net/problem/1309
//2019.08.24 13:34~
#include <iostream>
#define DIV 9901
using namespace std;
int DP[100001];

int dynamic() {
	int N;
	cin >> N;
	DP[1] = 3; DP[2] = 7;
	for (int i = 3; i <= N; i++) {
		DP[i] = (2 * DP[i - 1] + DP[i - 2]) % DIV;
	}
	return DP[N];
}

void solution() {
	cout << dynamic() << endl;
}

int main() {
	solution();
}