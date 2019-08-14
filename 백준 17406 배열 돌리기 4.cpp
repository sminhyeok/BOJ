//https://www.acmicpc.net/problem/17406
//2019.08.14 10:43~11:19
#include <iostream>
#define MAX 51
using namespace std;
struct pos {
	int r, c, s;
};
pos CYCLE[6];
bool USE[6];
int MAP[MAX][MAX];
int N, M, K, MIN;

void init() {
	MIN = 5001;
	cin >> N >> M >> K;
	for (int r = 1; r <= N; r++) {
		int sum = 0;
		for (int c = 1; c <= M; c++) {
			cin >> MAP[r][c]; sum += MAP[r][c];
		}
		if (MIN < sum) MIN = sum;
	}
		
	for (int i = 0; i < K; i++) {
		cin >> CYCLE[i].r >> CYCLE[i].c >> CYCLE[i].s;
		USE[i] = false;
	}
		
}

void calc() {
	for (int r = 1; r <= N; r++) {
		int SUM = 0;
		for (int c = 1; c <= M; c++)
			SUM += MAP[r][c];
		if (SUM < MIN) MIN = SUM;
	}
}

void turn(int r, int c, int s) {
	for (int i = 1; i <= s; i++) {
		int temp = MAP[r-i][c-i];
		// 왼쪽 아래에서 위로
		for (int R = r - i; R < r + i; R++)
			MAP[R][c - i] = MAP[R + 1][c - i];
		// 아래쪽 오른쪽에서 왼쪽으로
		for (int C = c - i; C < c + i; C++)
			MAP[r + i][C] = MAP[r + i][C + 1];
		// 오른쪽 위에서 아래로
		for (int R = r + i; R > r - i; R--)
			MAP[R][c + i] = MAP[R - 1][c + i];
		// 위쪽 왼쪽에서 오른쪽으로
		for (int C = c + i; C > c - i; C--)
			MAP[r - i][C] = MAP[r - i][C - 1];
		MAP[r - i][c - i + 1] = temp;
	}
}

void reverse(int r, int c, int s) {
	for (int i = 1; i <= s; i++) {
		int temp = MAP[r - i][c - i];
		// 위쪽 오른쪽에서 왼쪽으로
		for (int C = c - i; C < c + i; C++)
			MAP[r - i][C] = MAP[r - i][C + 1];
		// 오른쪽 아래에서 위로
		for (int R = r - i; R < r + i; R++)
			MAP[R][c + i] = MAP[R + 1][c + i];
		// 아래쪽 왼쪽에서 오른쪽으로
		for (int C = c + i; C > c - i; C--)
			MAP[r + i][C] = MAP[r + i][C - 1];
		// 왼쪽 위에서 아래로
		for (int R = r + i; R > r - i; R--)
			MAP[R][c - i] = MAP[R - 1][c - i];
		MAP[r - i + 1][c - i] = temp;
	}
}

void DFS(int k) {
	if (k == K) {
		calc(); return;
	}

	for (int i = 0; i < K; i++) {
		if (!USE[i]) {
			USE[i] = true;
			turn(CYCLE[i].r, CYCLE[i].c, CYCLE[i].s);
			DFS(k + 1);
			reverse(CYCLE[i].r, CYCLE[i].c, CYCLE[i].s);
			USE[i] = false;
		}
	}
}

void solution() {
	init();
	DFS(0);
	cout << MIN << endl;
}

int main() {
	solution();
}