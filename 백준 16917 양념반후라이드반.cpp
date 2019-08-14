//https://www.acmicpc.net/problem/16917
//2019.08.09 13:53~14:11
#include <iostream>
using namespace std;
int PRICE[3];	// 양념, 후라이드, 반반 가격
int X, Y;		// 양념, 후라이드 치킨

int min(int a, int b) { return a < b ? a : b; }

void init() {
	for (int i = 0; i < 3; i++) cin >> PRICE[i];
	cin >> X >> Y;
}

void solution() {
	init();
	int MIN = min(PRICE[0] + PRICE[1], PRICE[2] * 2);	// 양념, 후라이드 한마리씩 살 때 제일 적게드는 비용
	int MIN_EA = min(X, Y);	// 더 적은 치킨 종류
	int TOTAL = MIN_EA * MIN;
	int GAP = X - Y;

	int REST;	// 남은 치킨 살 때
	if (GAP < 0) REST = abs(GAP) * PRICE[1];	// 후라이드를 더 사야할때
	else REST = GAP * PRICE[0];				// 양념을 더 사야할때
	REST = min(REST, abs(GAP) * PRICE[2] * 2); // 남은걸 단일로 살때와 반반으로 살때 비교
	TOTAL += REST;
	cout << TOTAL << endl;
}

int main() {
	solution();
}