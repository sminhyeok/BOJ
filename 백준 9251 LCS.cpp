//https://www.acmicpc.net/problem/9251
//2019.08.21 17:47~19:03
#include <iostream>
#include <string>
using namespace std;
int DP[1001][1001];
int LA, LB;
string A, B;

int max(int a, int b) { return a > b ? a : b; }

void init() {
	cin >> A >> B;
	LA = A.size(); LB = B.size();
}

void dynamic() {
	for(int a = 1; a <= LA; a++)
		for (int b = 1; b <= LB; b++) {
			if (A[a - 1] == B[b - 1]) DP[a][b] = DP[a - 1][b - 1] + 1;
			else {
				DP[a][b] = max(DP[a][b - 1], DP[a - 1][b]);
			}
		}
}

void solution() {
	init();
	dynamic();
	cout << DP[LA][LB] << endl;
}

int main() {
	solution();
}