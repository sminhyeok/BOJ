// 2019.10.27 10:47~11:28
#include <iostream>
using namespace std;


void solution() {
	int T;
	cin >> T;
	while (T--) {
		// ȣ�� ����, �ʺ�, �� ��
		int H, W, N;
		cin >> H >> W >> N;
		// �����Ǵ� �� ��
		if (N % H == 0) cout << H;
		else cout << N % H;

		// �����Ǵ� �� ��ȣ
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