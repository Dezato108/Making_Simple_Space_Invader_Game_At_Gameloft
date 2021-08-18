#include "StateContext.h"

StateContext::StateContext()
{
	m_currentState = new LockedState();
}

void StateContext::changeCurrentState(StateBase* newState)
{
	m_currentState = newState;
}

void StateContext::open()
{
	m_currentState->open(this);
}

void StateContext::close()
{
	m_currentState->close(this);
}

void StateContext::lock()
{
	m_currentState->lock(this);
}

void StateContext::unlock()
{
	m_currentState->unlock(this);
}
