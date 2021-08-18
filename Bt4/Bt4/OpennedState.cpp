#include "OpennedState.h"
#include <iostream>
using namespace std;

void OpennedState::open(StateContext* sc)
{
	cout << "The door is already openned" << endl;
}

void OpennedState::close(StateContext* sc)
{
	cout << "You closed the door" << endl;
	cout << "Current state of the door : Unlocked and Closed" << endl;
	sc->changeCurrentState(new ClosedState);
	delete this;
}

void OpennedState::lock(StateContext* sc)
{
	cout << "The door can't be locked while openned" << endl;
}

void OpennedState::unlock(StateContext* sc)
{
	cout << "The door is already unlocked" << endl;
}
