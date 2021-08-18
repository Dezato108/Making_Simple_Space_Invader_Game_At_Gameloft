#pragma once
class StateContext;

class StateBase
{
public : 
	StateBase();
	virtual void open(StateContext* sc) = 0;
	virtual void close(StateContext* sc) = 0;
	virtual void lock(StateContext* sc) = 0;
	virtual void unlock(StateContext* sc) = 0;
};

