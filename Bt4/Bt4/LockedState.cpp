#include "LockedState.h"
#include <iostream>

using namespace std;


void LockedState::open(StateContext* sc)
{
	cout << "The door can't be openned while locked" << endl;
}

void LockedState::close(StateContext* sc)
{
	cout << "The door is already closed" << endl;
}

void LockedState::lock(StateContext* sc)
{
	cout << "The door is already locked" << endl;
}

void LockedState::unlock(StateContext* sc)
{
	cout << "You unlocked the door" << endl;
	cout << "Current state of the door : Unlocked and Closed" << endl;
	sc->changeCurrentState(new ClosedState);
	delete this;
}
