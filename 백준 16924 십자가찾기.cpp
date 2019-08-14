//https://www.acmicpc.net/problem/16924
//2019.08.09 19:44~21:16
#include <iostream>
#include <vector>
#define MAX 101
using namespace std;
struct pos {
	int r, c, big;
};
vector<pos> ANSWER;
char MAP[MAX][MAX];
bool VISIT[MAX][MAX];
int N, M;
int dr[] = { -1,0,1,0 };
int dc[] = { 0,1,0,-1 };

void init() {
	cin >> N >> M;
	for(int r = 1; r <= N; r++)
		for (int c = 1; c <= M; c++) {
			cin >> MAP[r][c];
			if (MAP[r][c] == '.') VISIT[r][c] = true;
			else VISIT[r][c] = false;
		}
}


int large(int r, int c) {
	int result = 0;
	for (int L = 1; L <= MAX; L++) {
		for (int i = 0; i < 4; i++) {
			int mr = r + L*dr[i], mc = c + L*dc[i];
			if (mr < 1 || mr > N || mc < 1 || mc > M || MAP[mr][mc] == '.') return result;
		}
		result++;
	}
	return result;
}

void visit(int r, int c, int big) {

	VISIT[r][c] = true;
	for (int L = 1; L <= big; L++) {
		for (int i = 0; i < 4; i++) {
			int mr = r + L*dr[i], mc = c + L* dc[i];
			VISIT[mr][mc] = true;
		}
	}
}

bool empty() {
	for (int r = 1; r <= N; r++)
		for (int c = 1; c <= M; c++)
			if (!VISIT[r][c]) return true;
	return false;
}

void print() {
	cout << ANSWER.size() << endl;
	for(int i = 0; i < ANSWER.size(); i++) {
		int R = ANSWER.at(i).r, C = ANSWER.at(i).c, B = ANSWER.at(i).big;
		cout << R << " " << C << " " << B << endl;	
	}
}

void solution() {
	init();
	for(int r = 1; r <= N; r++)
		for (int c = 1; c <= M; c++) {
			if (MAP[r][c] == '*') {
				int L = large(r, c); 
				if (L > 0) {
					visit(r, c, L);
					ANSWER.push_back({ r,c,L });
				}
			}
		}
	if (empty()) cout << -1 << endl;
	else print();
}

int main() {
	solution();
}