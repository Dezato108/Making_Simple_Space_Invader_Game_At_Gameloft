#include <bits/stdc++.h>

using namespace std;

void swap1(int a, int b) {
	int temp = a;
	a = b; b = temp;
}


int main() {
	int a, b;
	cout << "Nhap vao a,b :" << endl;
	cin >> a >> b;

	cout << "Doi cho" << endl;
	swap(a, b);
	cout << "a = " << a;
	cout << "b = " << b;
}