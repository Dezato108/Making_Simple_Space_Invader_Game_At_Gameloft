#pragma once
#include "LockedState.h"
class StateContext
{
private:
	StateBase* m_currentState;
public:
	StateContext();
	void changeCurrentState(StateBase* newState);
	void open();
	void close();
	void lock();
	void unlock();
};

