#pragma once
#include "OpennedState.h"
#include "LockedState.h"

class ClosedState : public StateBase
{
public:
	void open(StateContext* sc) override;
	void close(StateContext* sc) override;
	void lock(StateContext* sc) override;
	void unlock(StateContext* sc) override;
};

