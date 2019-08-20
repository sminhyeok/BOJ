//https://www.acmicpc.net/problem/11727
//2019.08.15 18:39~20:06
#include <iostream>
using namespace std;
int DP[1001];

int main() {
	int N; cin >> N;
	DP[1] = 1;
	DP[2] = 3;
	for (int i = 3; i <= N; i++)
		DP[i] =(DP[i - 1] + 2 * DP[i - 2]) % 10007;
	cout << DP[N] << endl;
}