//https://www.acmicpc.net/problem/1026
//2019.09.15 20:06~20:14
#include <iostream>
using namespace std;

int A[50], B[50], N;

void sortUP(int arr[]) {
	for(int i = 0; i < N-1; i++)
		for (int j = i + 1; j < N; j++) {
			if (arr[i] < arr[j]) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
}
void sortDOWN(int arr[]) {
	for (int i = 0; i < N - 1; i++)
		for (int j = i + 1; j < N; j++) {
			if (arr[i] > arr[j]) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
}

void init() {
	cin >> N;
	for (int n = 0; n < N; n++)
		cin >> A[n];
	for (int n = 0; n < N; n++)
		cin >> B[n];

	sortUP(A);
	sortDOWN(B);
}

int calc() {
	int result = 0;
	for (int i = 0; i < N; i++)
		result += A[i] * B[i];
	return result;
}

void solution() {
	init();
	cout << calc();
}

int main() {
	solution();
}