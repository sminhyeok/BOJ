/*
//https://www.acmicpc.net/problem/16958
//2019.08.04 10:10~11:03,
#include <iostream>
using namespace std;
struct pos {
	int x, y;	//x = row, y = col
};
pos CITY[1001];
bool CAN_TELEPORT[1001];
int N, T, M;
int ANSWER[1001][1001];

void init() {
	cin >> N >> T;
	for (int i = 1; i <= N; i++) {
		cin >> CAN_TELEPORT[i] >> CITY[i].x >> CITY[i].y;
		ANSWER[i][i] = 0;
	}
	cin >> M;
}
int min(int A, int B) { return A < B ? A : B; }

void connect(int A, int B) {

	int x1 = CITY[A].x, y1 = CITY[A].y;
	int x2 = CITY[B].x, y2 = CITY[B].y;
	int distance = abs(x1 - x2) + abs(y1 - y2);
	ANSWER[A][B] = distance;
	if (CAN_TELEPORT[A] && CAN_TELEPORT[B]) ANSWER[A][B] = min(distance, T);
	ANSWER[B][A] = ANSWER[A][B];
}


void Floyd() {
	// 모든 정점간 1차적으로 연결
	for (int A = 1; A < N; A++)
		for (int B = A+1; B <= N; B++)
			connect(A, B);
	// floyd 알고리즘 적용. 중간 경로를 거치는게 더 빠른지 확인
	for (int K = 1; K <= N; K++) {
		for (int A = 1; A <= N; A++) {
			for (int B = 1; B <= N; B++) {
				if (A == K) break;
				if (A == B) continue;
				ANSWER[A][B] = min(ANSWER[A][B], ANSWER[A][K] + ANSWER[K][B]);
			}
		}
	}
}

void print() {
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		cout << ANSWER[A][B] << endl;
	}
}

int main() {
	init();
	Floyd();
	print();
}
*/