//https://www.acmicpc.net/problem/1920
//2019.09.16 14:02~14:31
#include <iostream>
#include <algorithm>
using namespace std;
int A[100000], N;
int ANSWER[100000],M;
int MAX, MIN;
void init() {
	cin >> N;
	MIN = 987654321; MAX = -1;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		if (MIN > A[i]) MIN = A[i];
		if (MAX < A[i]) MAX = A[i];
	}
	cin >> M;
	for (int i = 0; i < M; i++)
		cin >> ANSWER[i];
	sort(A, A + N);
}

int index(int left, int right, int num) {
	long long middle = ((long long)left + (long long)right) / 2;
	if (left >= right) return right;
	
	if (A[middle] == num) return middle;
	
	if (A[middle] < num) return index(middle+1, right, num);
	else return index(left, middle, num);
}

bool check(int num) {
	if (num < MIN || num > MAX) return false;
	if (num == A[index(0,N-1,num)]) return true;
	else return false;
}

void solution() {
	init();
	for (int i = 0; i < M; i++) {
		cout << check(ANSWER[i]) << '\n';
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	solution();
}