//https://www.acmicpc.net/problem/2503
//2019.08.30 10:22~11:42
#include <iostream>
#include <string>
using namespace std;

string IN[100];
int N, BALL[100], STRIKE[100];

void init() {
	cin >> N;
	for (int i = 0; i < N; i++) 
		cin >> IN[i] >> STRIKE[i] >> BALL[i];
}

bool check(string answer) {
	for (int i = 0; i < N; i++) {
		int B = 0, S = 0;
		for (int j = 0; j < 3; j++) {
			if (answer[j] == IN[i][j]) S++;
			else {
				bool flag = false;
				for (int k = 0; k < 3; k++)
					if (answer[k] == IN[i][j]) flag = true;
				if (flag) B++;
			}
		}
		if (B != BALL[i] || S != STRIKE[i]) return false;
	}
	return true;
}

int find() {
	int result = 0;
	for(int x = 1; x <= 9; x++)
		for(int y = 1; y <= 9; y++)
			for (int z = 1; z <= 9; z++) {
				if (x == y || x == z || y == z) continue;
				string ans;
				ans += x + '0';
				ans += y + '0';
				ans += z + '0';
				if (check(ans)) result++;
			}
	return result;
}

void solution() {
	init();
	cout << find() << endl;
}

int main() {
	solution();
}