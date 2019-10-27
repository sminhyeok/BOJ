// 2019.10.27 10:47~11:28
#include <iostream>
using namespace std;


void solution() {
	int T;
	cin >> T;
	while (T--) {
		// 호텔 높이, 너비, 고객 수
		int H, W, N;
		cin >> H >> W >> N;
		// 배정되는 층 수
		if (N % H == 0) cout << H;
		else cout << N % H;

		// 배정되는 방 번호
		if ((N / H) + 1 < 10) cout << 0;
		else if ((N % H) == 0 && N / H < 10) cout << 0;
		if (N % H == 0) cout << N / H;
		else cout << N / H + 1;
		cout << '\n';
	}
}

int main() {
	solution();
}