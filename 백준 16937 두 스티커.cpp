/*
//https://www.acmicpc.net/problem/16937
// 2019.08.02 14:58~
#include <iostream>
#include <algorithm>
using namespace std;

struct STICKER {
	int R, C;
};
STICKER S1[100], S2[100];	// 넓이 기준으로 내림차순, 내림차순 된 스티커에서 90회전(R과 C가 바뀜)
int H, W, N;	// 높이, 가로, 스티커 수
int MAX;
int H1, W1, H2, W2;	// 스티커를 붙인 범위 - R = 1, C = 1 인 스티커면 H1, H2 =0, W1,W2 = 0이 됨
bool FIND;

bool comp(const STICKER& a, STICKER& b) {
	if (a.R * a.C > b.R * b.C) return true;
	else return false;
}


void init() {
	FIND = false;
	H1 = 0; W1 = 0;
	cin >> H >> W >> N;

	for (int i = 0; i < N; i++) {
		int r, c;
		cin >> r >> c;
		S1[i].R = r; S1[i].C = c;
	}
	sort(S1, S1 + N, comp);
	for (int i = 0; i < N; i++) {
		S2[i].R = S1[i].C;
		S2[i].C = S1[i].R;
	}

}

// 해당 스티커를 붙일 공간이 있는지 확인
bool check(STICKER s, int r, int c, int t) {
	// 스티커를 부착했을때 모눈종이를 벗어날 경우
	if (r < 0 || c < 0) return false;
	if (r + s.R > H || c + s.C > W) return false;

	// 스티커가 붙은 네 모서리인 H1,W1,H2,W2 안 에 새로 부착하는 위치가 겹치는지 확인
	if (t==1 && (H1 <= r && H2 >= r) && (W1 <= c && W2 >= c)) return false;

	return true;
}

void DFS(int t, int sum, int next) {
	if (t == 2) {
		if (MAX < sum) MAX = sum;
		return;
	}

	for (int i = next; i < N; i++) {
		if (t == 0) {
			if (MAX >= S1[i].R * S1[i].C * 2) return;	// 이미 구한 MAX 보다 더 큰 MAX가 나올 수 가 없으므로 종료
			if (check(S1[i], 0, 0, 0)) {	// 왼쪽 아래에 스티커 부착
				H2 = S1[i].R - 1; W2 = S1[i].C - 1;
				DFS(t + 1, S1[i].R * S1[i].C, i + 1);
			}
			if (check(S2[i], 0, 0, 0)) {
				H2 = S2[i].R - 1; W2 = S2[i].C - 1;
				DFS(t + 1, S2[i].R * S2[i].C, i + 1);
			}
		}
		else {
			if (MAX >= sum + S1[i].R * S1[i].C) return;	// 이미 구한 MAX 보다 더 큰 MAX 구할 수 없음
			if (check(S1[i], H - S1[i].R, W - S1[i].C, 1)) {	// 오른쪽 아래에 스티커 부착
				DFS(t + 1, sum + S1[i].R * S1[i].C, i);
			}
			if (check(S2[i], H - S2[i].R, W - S2[i].C, 1)) {	// 오른쪽 아래에 스티커 부착
				DFS(t + 1, sum + S2[i].R * S2[i].C, i);
			}
		}
	}
}

int main() {
	init();
	DFS(0, 0, 0);
	cout << MAX << endl;
}

*/