//https://www.acmicpc.net/problem/1018
//2019.09.06 11:13~11:45
#include <iostream>
#define CHESS 8
using namespace std;
char BOARD[51][51];
char COMP[2][CHESS][CHESS];
int N, M;	// 가로, 세로

void init() {
	cin >> N >> M;
	for (int y = 1; y <= N; y++)
		for (int x = 1; x <= M; x++)
			cin >> BOARD[y][x];
	bool FLAG[2]{ false, };
	for (int y = 0; y < CHESS; y++) {
		for (int x = 0; x < CHESS; x++) {
			if (!FLAG[0]) { FLAG[0] = !FLAG[0];	COMP[0][y][x] = 'B'; }
			else { FLAG[0] = !FLAG[0]; COMP[0][y][x] = 'W'; }

			if (!FLAG[1]) { FLAG[1] = !FLAG[1];	COMP[1][y][x] = 'W'; }
			else { FLAG[1] = !FLAG[1]; COMP[1][y][x] = 'B'; }
		}
		FLAG[0] = !FLAG[0]; FLAG[1] = !FLAG[1];
	}
		
}

int comp(int Y, int X) {
	int MIN[2] = { 0, };
	for(int y = 0; y < CHESS; y++)
		for (int x = 0; x < CHESS; x++) {
			if (BOARD[y + Y][x + X] != COMP[0][y][x]) MIN[0]++;
			if (BOARD[y + Y][x + X] != COMP[1][y][x]) MIN[1]++;
		}
	return MIN[0] < MIN[1] ? MIN[0] : MIN[1];
}

int FIND() {
	int MIN = 2500;
	for (int y = 1; y <= N - 7; y++) {
		for (int x = 1; x <= M - 7; x++) {
			int temp = comp(y, x);
			if (temp < MIN) MIN = temp;
		}
	}
	return MIN;
}

void solution() {
	init();
	cout << FIND() << endl;
}

int main() {
	solution();
}