//https://www.acmicpc.net/problem/2468
//2019.08.14 09:30~09:55
#include <iostream>
#include <queue>
#define MAX 100
using namespace std;
struct pos {
	int y, x;
};
int MAP[MAX][MAX];
bool WATER[MAX][MAX];
int N, H;
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };

void init() {
	H = 0;
	cin >> N;
	for(int y = 0; y < N; y++)
		for (int x = 0; x < N; x++) {
			cin >> MAP[y][x];
			WATER[y][x] = false;
			if (MAP[y][x] > H) H = MAP[y][x];
		}
}

void rain(int w) {
	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			if (MAP[y][x] <= w) WATER[y][x] = true;
}

void recovery() {
	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			WATER[y][x] = false;
}

void BFS(int y, int x) {
	queue<pos> Q;
	WATER[y][x] = true;
	Q.push({ y,x });
	while (!Q.empty()) {
		int Y = Q.front().y, X = Q.front().x; Q.pop();
		for (int i = 0; i < 4; i++) {
			int my = Y + dy[i], mx = X + dx[i];
			if (my >= 0 && mx >= 0 && my < N && mx < N && !WATER[my][mx]) {
				WATER[my][mx] = true;
				Q.push({ my,mx });
			}
		}
	}
}

bool check(int y, int x) {
	if (!WATER[y][x]) { BFS(y, x); return true; }
	else return false;
}

void simulation() {
	init();
	int answer = 0;
	for (int w = 0; w < H; w++) {
		int group = 0;
		rain(w);
		for (int y = 0; y < N; y++)
			for (int x = 0; x < N; x++)
				if (check(y, x)) group++;
		if (answer < group) answer = group;
		recovery();
	}
	cout << answer << endl;
}

int main() {
	simulation();
}