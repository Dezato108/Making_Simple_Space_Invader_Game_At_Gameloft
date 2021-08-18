#include "StateContext.h"
#include "LockedState.h"
#include<iostream>
using namespace std;
int main() {
	int in;
	cout << "Creating a door at Locked state..."<<endl;
	StateContext* aa = new StateContext();
	cout << "A door at Locked state has been created" << endl;
	cout << endl;

	cout << "Current state of the door : Locked and Closed" << endl;
	cout << "---List of actions---" << endl;
	cout << "1. Open the door" << endl;
	cout << "2. Close the door" << endl;
	cout << "3. Lock the door" << endl;
	cout << "4. Unlock the door" << endl;
	cout << "0. Stop interact with the door and exit program" << endl;
	cout << endl;

	while (true) {
		cout << "Choose an action : ";
		cin >> in;
		if (in == 1) {
			cout << "Opening the door..." << endl;
			aa->open();
			cout << endl;
		}
		else if (in == 2) {
			cout << "Closing the door..." << endl;
			aa->close();
			cout << endl;
		}
		else if (in == 3) {
			cout << "Locking the door..." << endl;
			aa->lock();
			cout << endl;
		}
		else if (in == 4) {
			cout << "Unlocking the door..." << endl;
			aa->unlock();
			cout << endl;
		}
		else if (in == 0) {
			cout << "Exitting..." << endl;
			break;
		}
		else cout << "Please enter a valid input!" << endl;
	}

	//FreeMemory
	delete aa;
	_CrtDumpMemoryLeaks();	
	return 0;
}