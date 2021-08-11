#include <stdio.h>
#include <iostream>
using namespace std;
float n;

bool check(float &n) {
	if (n == int(n)) return true;
	return false;
}

long long factorial(float &n) {
	if (n == 0) return 1;
	long long s=1;
	for (int i = 2; i <= n; i++) {
		s = s * i;
	}
	return s;
}

int main() {
		input:
		cout << "n= ";
		cin >> n;
		if (check(n) && (n > 0) && (n <= 20)) {
			cout << "--> n! = " << factorial(n) << endl;
		}
		else {
			cout << "Invalid number, please re-input !" << endl;
			goto input;
		}		
		return 0;
}