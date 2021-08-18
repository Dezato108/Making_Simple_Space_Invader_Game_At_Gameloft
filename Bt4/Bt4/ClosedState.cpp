#include "ClosedState.h"
#include<iostream>
using namespace std;

void ClosedState::open(StateContext* sc)
{
	cout << "You openned the door" << endl;
	cout << "Current state of the door : Unlocked and Openned" << endl;
	sc->changeCurrentState(new OpennedState);
	delete this;
}

void ClosedState::close(StateContext* sc)
{
	cout << "The door is already closed" << endl;
}

void ClosedState::lock(StateContext* sc)
{
	cout << "You locked the door" << endl;
	cout << "Current state of the door : Locked and Closed" << endl;
	sc->changeCurrentState(new LockedState);
	delete this;
}

void ClosedState::unlock(StateContext* sc)
{
	cout << "The door is already unlocked" << endl;
}
