/*
//https://www.acmicpc.net/problem/16953
// 2019.08.03 08:39 ~ 08:56
#include <iostream>
#include <queue>
using namespace std;

struct info {
	long long num;
	int t;
};
queue<info> Q;
long long A, B;

void init() {
	cin >> A >> B;
	Q.push({ A,0 });
}

int BFS() {
	int result = -1;
	while (!Q.empty()) {
		long long num = Q.front().num;
		int t = Q.front().t;
		Q.pop();

		if (num == B) return t+1;
		else {
			if (num * 2 <= B) {
				if (num * 2 == B) return t + 2;
				Q.push({ num * 2,t + 1 });
			}
			if (num * 10 + 1 <= B) {
				if (num * 10 + 1 == B) return t + 2;
				Q.push({ num * 10 + 1, t + 1 });
			}
		}
	}
	return result;
}

int main() {
	init();
	cout << BFS() << endl;
}
*/