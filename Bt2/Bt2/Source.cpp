#include <stdio.h>
#include <iostream>
using namespace std;

unsigned long long int factorial(int n) {
	if (n == 0 || n==1) return 1;
	unsigned long long int s=1;
	for (int i = 2; i <= n; i++) {
		s = s * i;
	}
	return s;
}

int main() {
		int n;
		
		cout << "n= ";
		cin >> n;
		while (n <= 0) {
			cout << "Please re - enter a valid input"<<endl;
			cout << "n= ";
			cin >> n;
		}		
		cout << "--> n! = " << factorial(n) << endl;
		return 0;
}