//https://www.acmicpc.net/problem/9498
//2019.09.11 13:15~13:18
#include <iostream>
using namespace std;

int main() {
	int NUM;
	cin >> NUM;
	
	if (NUM >= 90) cout << 'A' << endl;
	else if (NUM >= 80) cout << 'B' << endl;
	else if (NUM >= 70) cout << 'C' << endl;
	else if (NUM >= 60) cout << 'D' << endl;
	else cout << 'F' << endl;
}