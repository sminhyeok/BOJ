//https://www.acmicpc.net/problem/1010
//2019.08.13 13:52~14:20
#include <iostream>
#define MAX 31
using namespace std;
unsigned long long DP[MAX][MAX];
int N, M;


void dynamic() {
	for (int i = 0; i <= 30; i++) {
		DP[0][i] = 0;  DP[i][i] = 1; DP[1][i] = i;
	}
	for (int i = 2; i <= 29; i++) {
		for (int j = i + 1; j <= 30; j++) {
			DP[i][j] = DP[i - 1][j - 1] + DP[i][j - 1];
		}
	}
}

void solution() {
	cin >> N >> M;
	cout << DP[N][M] << endl;
}

int main() {
	dynamic();
	int T; cin >> T;
	for(int i = 0; i < T; i++)
		solution();
}