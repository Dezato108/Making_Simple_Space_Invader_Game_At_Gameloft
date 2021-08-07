#include <stdio.h>
#include <iostream>
using namespace std;

void swap1(int x, int y) {
	int temp = x;
	x = y; y = temp;
	cout << endl;
	cout << "SWAP 1" << endl;
	cout << "a = " << x << " " << "b = " << y << endl;
}

void swap2(int* aa, int* bb ) {
	int temp = *aa;
	*aa = *bb;
	*bb = temp;	
}


int main() {
	int a, b;
	cout << "Nhap vao a,b : ";
	cin >> a >> b;
	swap1(a, b);
	swap2(&a, &b);
	cout << endl;
	cout << "SWAP 2" << endl;
	cout << "a = " << a << " " << "b = " << b << endl;
}