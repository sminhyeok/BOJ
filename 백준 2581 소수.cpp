// 2019.10.27 11:42~11:47
#include <iostream>
using namespace std;
const int SIZE = 10000;

void solution() {
	int M, N;
	cin >> M >> N;

	bool NUM[SIZE + 1]; NUM[1] = true;
	for (int i = 2; i <= SIZE; i++) NUM[i] = false;
	for (int i = 2; i <= SIZE; i++) {
		if (!NUM[i]) {
			for (int j = i * 2; j <= SIZE; j += i) NUM[j] = true;
		}
	}
	int answer = 0, MIN = SIZE;
	for (int i = M; i <= N; i++)
		if (!NUM[i]) { answer += i; if (MIN > i) MIN = i; }
	if (answer != 0) cout << answer << '\n' << MIN;
	else cout << -1;
}

int main() {
	solution();
}