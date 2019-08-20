//https://www.acmicpc.net/problem/10844
//2019.08.17 17:15~18:10
#include <iostream>
#define DIV 1000000000
using namespace std;
unsigned long long DP[101][11];
int N;

void init(){
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= 10; j++)
			DP[i][j] = 0;
	}
	for (int i = 0; i <= 9; i++) DP[1][i] = 1;
}

void dynamic() {
	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= 9; j++) 
			DP[i][j] = (DP[i - 1][j - 1] + DP[i - 1][j + 1]) % DIV;
		DP[i][0] = DP[i-1][1];
	}
}

void solution() {
	init();
	dynamic();
	unsigned long long result = 0;
	for (int i = 1; i <= 9; i++)
		result = (result + DP[N][i]) % DIV;
	cout << result << endl;
}

int main() {
	solution();
}